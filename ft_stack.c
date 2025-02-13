/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:22:14 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:22:14 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Função para inicializar a pilha vazia com valor 
	NULL no top, sem nenhum parametro
*/
t_stack	*init_stack()
{
	// Declarar variável local para a estrutura da pilha
	t_stack	*stack;
	
	// Aloca memória para a estrutura de dados da pilha (membro stack)
	stack = (t_stack *)malloc(sizeof(t_stack));
	//Em caso que alocaçao da memoria do membro falhar, retorna NULL
	if (!stack)
	{
		// Retorna NULL em caso de falha na alocação de memória
		return (NULL);
	}
	// Inicializa o membro com o topo da pilha como NULL, indicando que a pilha está vazia
	stack->top = NULL;
	// Retornar o membro apontada para a estrutura da pilha recém-criada
	return stack;
}

/*
	Função para verificar se a pilha está vazia
	Retorna 1 se a pilha está vazia, caso contrário retorna 0
*/
int	is_empty(t_stack *stack)
{
	//Verificar se a pilha esta vazia
	if (stack->top == NULL)
	{
		//Retornar 1 se nao tiver valor
		return (1);
	}
	else
	{
		//Retornar 0 se tiver valor
		return(0);
	}
}

/*
    Função para exibir todos os elementos da pilha
*/
void	display(t_stack *stack)
{
	t_node	*current;
	
	// Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
	}
	// Exibe os valores diretamente na ordem em que estão na pilha
	current = stack->top;
	while (current)
	{
		ft_printf("%d \n", current->value);
		current = current->next;
	}
}

/*
	Função para liberar a memória de uma pilha.
	Percorre cada nó da pilha e libera a memória alocada.
*/
void	free_stack(t_stack *stack)
{
	//Declarar a variavel que vai armazenar valor de top da pilha
	t_node	*current;
	// Declara a variável que armazenará o próximo nó
	t_node	*next_node;
	
	// Atribui o valor do topo da pilha à variável (current)
	current = stack->top;
	// Percorre a pilha enquanto o nó atual não for NULL
	while (current != NULL)
	{
		// Armazena o próximo nó para continuar a iteração após liberar o nó atual
		next_node = current->next;
		 // Libera a memória do nó atual
		free(current);
		// Avança para o próximo nó
		current = next_node;
	}
	// Libera a estrutura da pilha
	free(stack);
}

/*
	Função para validar os valores e empilhá-los
*/
void	validate_and_push(char **args, t_stack *temp_stack, t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	num;

	j = 0;
	while (args[j] != NULL) // Validar números
	{
		if (!ft_digit_valid(args[j]))
		{
			ft_printf("Erro: Caractere '%s' é um dígito inválido\n", args[j]);
			ft_freememoria(args);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		num = ft_is_valid_number(args[j], stack_a, stack_b);

		// Verificar duplicatas antes de empilhar
		check_duplicate(temp_stack, num);
		// Armazenar temporariamente os valores na ordem correta
		push(temp_stack, num);
		j++;
	}
}

/*
	Função para dividir a string em substrings e 
	validar os valores
*/
void	process_arguments(char *arg, t_stack *temp_stack, t_stack *stack_a, t_stack *stack_b)
{
	char	**args;

	// Divide cada argumento em substrings
	args = ft_split(arg, ' ');
	if (!args || args[0] == NULL) // Verifica se a divisão falhou
	{
		ft_printf("Erro: Delimitador '%s' sem dígitos\n", arg);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	// Validar e empilhar números
	validate_and_push(args, temp_stack, stack_a, stack_b);
	ft_freememoria(args);
}

/*
	Função para inicializar chamando outras funções
*/ 
void	initialize_stacks(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack *temp_stack;

	*stack_a = init_stack();
	*stack_b = init_stack();
	temp_stack = init_stack();
	i = 1;
	while (argv[i] != NULL)
	{
		// Verificação de Argumentos Vazios
		if (ft_strlen(argv[i]) == 0)
		{
			i++;
			continue;
		}
		// Chama a função de processamento de argumentos
		process_arguments(argv[i], temp_stack, *stack_a, *stack_b);
		i++;
	}
	// Empilhar os valores da pilha temporária na pilha original
	while (!is_empty(temp_stack))
		push(*stack_a, pop(temp_stack));
	free_stack(temp_stack);
}
