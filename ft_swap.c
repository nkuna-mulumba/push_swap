/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:57:16 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:57:16 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Funçao para trocar os dois elementos
*/
void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

// Função que verifica se a pilha tem pelo menos dois elementos
int	can_swap(t_stack *stack)
{
	return (stack->top != NULL && stack->top->next != NULL);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [A]
int	sa(t_stack *stack_a)
{
	if (!can_swap(stack_a))
	{
		return (0);
	}
	swap(stack_a);
	ft_printf("sa\n");
	return (1);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [B]
int	sb(t_stack *stack_b)
{
	if (!can_swap(stack_b))
	{
		return (0);
	}
	swap(stack_b);
	ft_printf("sb\n");
	return (1);
}

//Funçao para trocar simultaneamente 2 primeiro elementos de [A] e [B]
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	can_swap_a;
	int	can_swap_b;

	can_swap_a = can_swap(stack_a);
	can_swap_b = can_swap(stack_b);
	if (can_swap_a)
		swap(stack_a);
	if (can_swap_b)
		swap(stack_b);
	if (can_swap_a && can_swap_b)
		ft_printf("ss\n");
}
