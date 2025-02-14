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
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);//Encontra a posição do menor valor na pilha A
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

