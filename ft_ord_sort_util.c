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
	Função para verificar se a string representa um
	número válido dentro do intervalo de int 
	e retornar o valor convertido
*/
long	ft_valid_number(const char *str, t_stack *a, t_stack *b)
{
	long	num;

	(void)a;
	(void)b;
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		num = 2147483648;
		return (num);
	}
	return ((int)num);
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
