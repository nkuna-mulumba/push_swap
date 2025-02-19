/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ord_sort_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 18:17:18 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-14 18:17:18 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Função auxiliar para verificar se a pilha está ordenada	
*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (is_empty(stack) || stack->top == NULL)
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
	Função para contar o número de elementos na stack_a
*/
int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}



/*
	Função auxiliar de (sort_four) para 
	encontrar o índice do menor valor na stack_a
*/
int	find_min_position(t_stack *stack)
{
	t_node	*currente;
	int		min;
	int		min_pos;
	int		i;

	if (!stack || !stack->top)
		return (-1);
	currente = stack->top;
	min = currente->value;
	min_pos = 0;
	i = 0;
	while (currente)
	{
		if (currente->value < min)
		{
			min = currente->value;
			min_pos = i;
		}
		currente = currente->next;
		i++;
	}
	return (min_pos);
}



/*
	Funçao para mover elementos menores 
	ate stack_a ter apenas 5 elementos

void	move_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *size)
{
	int	min_pos;

	while (*size > 5)
	{
		min_pos = find_min_position(stack_a);
		if (min_pos <= *size / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			while (++min_pos <= *size)
				rra(stack_a, 1);
		}
		pb(stack_b, stack_a);
		(*size)--;
	}
}
*/


/*
	Funçao para ordenar e mesclagem de 
	valores removidos
	//% ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./push_swap $ARG | wc -l
	//1334

void	finalize_sort(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
	if (total_elements == 5)
		sort_five(stack_a, stack_b, 0);
	else if (total_elements == 4)
		sort_four(stack_a, stack_b);
	else if (total_elements == 3)
		sort_three(stack_a);
	else if (total_elements == 2)
		sort_two(stack_a);
	while (!is_empty(stack_b))
		pa(stack_a, stack_b);
	while (!is_sorted(stack_a))
		ra(stack_a, 1);
}
*/
