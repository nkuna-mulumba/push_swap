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
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

/*
	Função para verificar se a pilha está vazia
	Retorna 1 se a pilha está vazia, caso contrário retorna 0
*/
int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	if (stack->top == NULL)
		return (1);
	else
		return (stack->top == NULL);
}

/*
	Função para exibir todos os elementos da pilha
*/
void	display(t_stack *stack)
{
	t_node	*current;

	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
	}
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
	t_node	*current;
	t_node	*next_node;

	if (!stack)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

/*
	Função para inicializar chamando outras funções
*/
int	initialize_stacks(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_stack;

	*stack_a = init_stack();
	*stack_b = init_stack();
	temp_stack = init_stack();
	if (!validate_args(argv, temp_stack, *stack_a, *stack_b))
		return (-1);
	while (!is_empty(temp_stack))
		push(*stack_a, pop(temp_stack));
	free_stack(temp_stack);
	if (*stack_a && stack_size(*stack_a) <= 0)
	{
		free_stack(*stack_a);
		exit(1);
	}
	return (stack_size(*stack_a));
}
