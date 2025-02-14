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
void free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next_node;

	if (!stack) // Verifica se a pilha é nula
		return;
	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL; // Define o topo da pilha como NULL após liberar os nós
	free(stack); // Libera a estrutura principal da pilha
}

/*
    Função para inicializar chamando outras funções
*/ 
int	initialize_stacks(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack *temp_stack;

	*stack_a = init_stack();
	*stack_b = init_stack();
	temp_stack = init_stack();
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) != 0) // Ignorar argumentos vazios
		process_arguments(argv[i], temp_stack, *stack_a, *stack_b);
		i++;
	}
	while (!is_empty(temp_stack))
		push(*stack_a, pop(temp_stack));
	free_stack(temp_stack);

	if (*stack_a && stack_size(*stack_a) <= 0) // Verifica se *stack_a não é NULL antes de chamar stack_size
	{
		free_stack(*stack_a); // Libera stack_a imediatamente se nenhum elemento válido for fornecido
		*stack_a = NULL; // Define *stack_a como NULL após liberação
		return (-1);
	}
	return (stack_size(*stack_a));
}
