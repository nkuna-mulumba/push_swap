/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuna <nkuna@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 09:41:47 by nkuna             #+#    #+#             */
/*   Updated: 2025-02-05 09:41:47 by nkuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Funçao para ordenara dois valor no stack_a
*/
void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	a = stack->top->value;
	b = stack->top->next->value;
	if (a > b)
		sa(stack);
}

/*
	Função para ordenar três valores na stack_a
*/
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->top || !stack->top->next || !stack->top->next->next)
		return ;
	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		(sa(stack), rra(stack, 1));
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		(sa(stack), ra(stack, 1));
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
}

/*
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);
	if (min_pos == 1)
		ra(stack_a, 1);
	else if (min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (min_pos == 3)
		rra(stack_a, 1);
	if (!is_sorted(stack_a))
	{
		pb(stack_b, stack_a);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

/*
	Função para ordenar cinco valores na stack_a 
*/
void	sort_five(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	min_pos;

	while (count++ < 1)
	{
		min_pos = find_min_position(stack_a);
		if (min_pos == 1)
			ra(stack_a, 1);
		else if (min_pos == 2)
		{
			ra(stack_a, 1);
			ra(stack_a, 1);
		}
		else if (min_pos == 3)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		else if (min_pos == 4)
			rra(stack_a, 1);
		if (!is_sorted(stack_a))
			pb(stack_b, stack_a);
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b);
}

/*
	Função para ordenar um grande número de elementos na stack_a 
	utilizando a stack_b como pilha auxiliar.
	Esta função utiliza uma combinação de divisão e conquista e funções 
	auxiliares para garantir a ordenação eficiente dos elementos.
	* stack_a: Pilha principal que contém os elementos a serem ordenados.
	* stack_b: Pilha auxiliar usada durante o processo de ordenação.
	* total_elements: Número total de elementos na stack_a.
*/
void	sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
	move_to_stack_b(stack_a, stack_b, &total_elements);
	finalize_sort(stack_a, stack_b, total_elements);
}
