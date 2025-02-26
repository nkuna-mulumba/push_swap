/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:36:46 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-17 22:36:46 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Funçao para assignar indice aos nodos
*/
void	assig_indice(t_stack *stack_a)
{
	t_node	*i;
	t_node	*j;

	i = stack_a->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
				i->index += 1;
			else
				j->index += 1;
			j = j->next;
		}
		i = i->next;
	}
}

/*
	Funçao main para provar o projecto
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length_elements;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	length_elements = initialize_stacks(argv, &stack_a, &stack_b);
	assig_indice(stack_a);
	if (!is_sorted(stack_a))
	{
		if (length_elements == 2)
			sort_two(stack_a);
		else if (length_elements == 3)
			sort_three(stack_a);
		else if (length_elements == 4)
			sort_four(stack_a, stack_b);
		else if (length_elements == 5)
			sort_five(stack_a, stack_b, 0);
		else if (length_elements > 5)
			ksort(stack_a, stack_b);
	}
	free_stack(stack_a);
	return (free_stack(stack_b), 0);
}
