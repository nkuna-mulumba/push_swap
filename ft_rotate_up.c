/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:49:00 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:49:00 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Função para rotacionar a pilha A, movendo o primeiro elemento para o final
*/
void	ra(t_stack *stack_a, int print)
{
	t_node	*new_node;
	t_node	*current;

	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return ;
	new_node = stack_a->top;
	stack_a->top = stack_a->top->next;
	new_node->next = NULL;
	current = stack_a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	if (print != 0)
		ft_printf("ra\n");
}

/*
	Função para rotacionar a pilha B, movendo o primeiro elemento para o final
*/
void	rb(t_stack *stack_b, int print)
{
	t_node	*new_node;
	t_node	*current;

	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return ;
	new_node = stack_b->top;
	stack_b->top = stack_b->top->next;
	new_node->next = NULL;
	current = stack_b->top;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	if (print)
		ft_printf("rb\n");
}

/*
	Função para rotacionar ambas as pilhas A e B, movendo o primeiro elemento 
	de cada pilha para o final
*/
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	can_rotate_a;
	int	can_rotate_b;

	can_rotate_a = (stack_a->top != NULL && stack_a->top->next != NULL);
	can_rotate_b = (stack_b->top != NULL && stack_b->top->next != NULL);
	if (can_rotate_a && can_rotate_b)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		ft_printf("rr\n");
	}
}
