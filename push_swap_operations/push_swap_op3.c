/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 09:50:54 by jcongolo          #+#    #+#             */

//Função para rodar os elementos da pilha "A" e "B" para baixo simultaneamente

#include "../push_swap.h"

void	rrr(int stack_a[], int top_a, int stack_b[], int top_b)
{
	rra(stack_a, top_a);
	rrb(stack_b, top_b);
}