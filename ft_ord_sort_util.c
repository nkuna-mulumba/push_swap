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
/*
	Funçao para assignar indice aos nodos
*/
// void	test_ord(t_stack *stack_a)
void	assig_indice(t_stack *stack_a)
{
	t_node	*i;
	t_node	*j;

	i  = stack_a->top;
	// ft_printf("VALORES DE [I]%d\n",i->value);
	// ft_printf("VALORES DE [J]%d\n",j->value);

	// 	 exit(1);

	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			//ft_printf("VALORES DE [I]%d, index %d \n",i->value,i->index);
			 //ft_printf("VALORES DE [J],  %d,  index %d\n",i->value,j->index);
			if(i->value > j->value)
				i->index += 1;	
			else
				j->index+= 1;
			j = j->next;
		}
		i = i->next;
	}
}

/**
 * ft_sqrt - Calcula a raiz quadrada inteira de um número.
 * @num: O número para o qual calcular a raiz quadrada.
 *
 * Esta função retorna a raiz quadrada inteira de um número dado.
 * Se o número não tem uma raiz quadrada inteira, a função retorna 0.
 *
 * Retorna: A raiz quadrada inteira de num ou 0 se não for uma raiz quadrada perfeita.
 */
int	ft_sqrt(int	num)
{
	int	n;
	
	n = 1;
	if (num < 0)
		return (0);
	
	while (n * n <= num)
	{
		if (n * n == num)
			return (n);
		n++;
	}
	return (n);
}