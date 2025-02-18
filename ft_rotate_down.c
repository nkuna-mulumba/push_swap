/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:49:44 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:49:44 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Função para rotacionar a pilha [A] ao contrário, movendo o último 
	elemento para o topo
*/
void	rra(t_stack *stack_a, int print)
{
	t_node	*last;
	t_node	*second_last;

	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_a->top;
	stack_a->top = last;
	second_last->next = NULL;
	if (print != 0)
		ft_printf("rra\n");
}

/*
	Função para rotacionar a pilha [B] ao contrário, movendo o último 
	elemento para o topo
*/
void	rrb(t_stack *stack_b, int print)
{
	t_node	*last;
	t_node	*second_last;

	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_b->top;
	stack_b->top = last;
	second_last->next = NULL;
	if (print != 0)
		ft_printf("rrb\n");
}

/*
	Função para rotacionar ambas as pilhas [A] e [B] ao contrário (rrr)
*/
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	can_rotate_a;
	int	can_rotate_b;

	can_rotate_a = (stack_a->top != NULL && stack_a->top->next != NULL);
	can_rotate_b = (stack_b->top != NULL && stack_b->top->next != NULL);
	if (can_rotate_a && can_rotate_b)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		ft_printf("rrr\n");
	}
}
