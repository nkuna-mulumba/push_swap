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

//com dois valores
// 1 2 Ordenada
// -1 1 ordenada
// -2 -1 ordenada
// -2 2  ordenada
// 2 1 SA
// -1 -2 SA


void	sort_two(t_stack *stack)
{
	int a;
	int b;

	a = stack->top->value;
	b = stack->top->next->value;
	if (a > b)
	{
		return;
	}
	else if (a < b)
	{
		sa(stack);
		display(stack);
	}
}
//1 2 3 NEHUMA OPERAÇAO DEVE SER FEITA
//1 3 2 SA 1 2 3 (1)suficiente
//2 3 1 RA 1 2 3 (1) suficiente
//2 1 3 SA 2 3 1 -> RA 1 2 3 (2) suficiente
//3 1 2 RRA 1 3 2 (1) suficiente
//3 2 1 RA 1 3 2 SA 1 2 3 (2) suficiente
//1 -1 0 RA -1 1 0 SA -1 0 1


//Testes adicional
//1 1 2
//-1 -1 -2
//2 2 2

//Misto positivo e negativo
//1 -2 3 SA RA
//-1 2 -3 RA
//2 -1 1 RRA

//Minimo e maximo INT
//-2147483648 2147483647 0 SA
//2147483647 -2147483648 1 RRA
//-2147483647 2147483646 0 SA


//invalidos
//1 2 a
//-1 b 3
//1.5 2 3



void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	// Caso já ordenado: 1 2 3 (nenhuma operação necessária)
	if (a > b && a > c && b > c) // 3 > 2 && 3 > 1 && 2 > 1
		return;
	//-2 -3 -1 SA -2 -1 -3 RA -3 -2 -1 (2) suficiente
	else if (a > b && a > c && c > b)
	{
		sa(stack);
		display(stack);
		ra(stack, 1);
		display(stack);
	}
	//-3 -1 -2 
	// 1 3 2 SA 1 2 3 (1)suficiente
	else if (a < b && a > c && b > c) // 2 < 3 && 2 > 1 && 3 > 1
	{
		sa(stack);
		display(stack);
	}
	//2 3 1 RA 1 2 3 (1) suficiente
	else if (a < b && a < c && b > c) // 1 < 3 && 1 < 2 && 3 > 2
	{
		ra(stack, 1);
		display(stack);
	}
	//2 1 3 RRA 1 3 2 -> SA 1 2 3 (2) suficiente
	else if (a > b && a > c && b < c) // 3 > 1 && 3 > 2 && 1 < 2
	{
		rra(stack, 1); //####
		display(stack);
		sa(stack);
		display(stack);
	}
	//3 1 2 RRA 1 3 2 (1) suficiente
	else if (a > b && a < c && b < c) // 2 > 1 && 2 < 3 && 1 < 3
	{
		rra(stack, 1);
		display(stack);
	}
	//-1 -2 -3  RA -3 -1 -2 -> SA -3 -2 -1 (2) suficiente
	//3 2 1 RA 1 3 2 SA 1 2 3 (2) suficiente
	else if (a < b && a < c && b < c) // 1 < 2 && 1 < 3 && 2 < 3
	{
		ra(stack, 1);
		display(stack);
		sa(stack);
		display(stack);
	}
}