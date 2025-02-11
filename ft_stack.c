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
	Função para inicializar e validar as pilhas, chamando ostras funçoes
*/ 
void	initialize_stacks(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int num;

	*stack_a = init_stack();
	*stack_b = init_stack();

	if (argc < 2)
	{
		ft_printf("Número de argumentos insuficiente\n");
		free_stack(*stack_a);
		free_stack(*stack_b);
		exit(1);
	}

	i = argc - 1; // Inicia no último argumento (ex: argv[4] para "./push_swap 1 2 3 4")
	while (i >= 1)// Processa do último para o primeiro
	{
		num = ft_is_valid_number(argv[i], *stack_a, *stack_b);
		check_duplicate(*stack_a, num);
		push(*stack_a, num);
		i--;
	}
}
