/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 10:13:35 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-17 10:13:35 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Função para trocar os dois primeiros elementos da pilha "A"
void	sa(int stack_a[], int top_a)
{
	int	temp;

	if (top_a > 0)
	{
		temp = stack_a[top_a];
		stack_a[top_a] = stack_a[top_a -1];
		stack_a[top_a - 1] = temp;
		ft_printf("sa\n"); // Imprime a operação "sa"
	}
}
//Função para trocar os dois primeiros elementos da pilha "B"
void	sb(int stack_b[], int top_b)
{
	int	temp;

	if (top_b > 0)
	{
		temp = stack_b[top_b];
		stack_b[top_b] = stack_b[top_b - 1];
		stack_b[top_b - 1] = temp;
		ft_printf("sb\n"); // Imprime a operação "sb"
	}
}
//Função para trocar simultaneamente os dois primeiros elementos da pilha "A" e "B"
void	ss(int stack_a[], int top_a, int stack_b[], int top_b)
{
	sa(stack_a, top_a);
	sb(stack_b, top_b);
	ft_printf("ss\n"); // Imprime a operação "ss"
}
// Função para mover o primeiro elemento da pilha "B" para a pilha "A"
void	pa(int stack_a[], int *top_a, int stack_b[], int *top_b)
{
	if (*top_b >= 0)
	{
		stack_a[++(*top_a)] = stack_b[(*top_b)--];
	}
	ft_printf("pa\n"); // Imprime a operação "pa"
}
//Funçao para mover o primeiro elemento da pilha "A" para a pilha "B"
void	pb(int stack_a[], int *top_a, int stack_b[], int *top_b)
{
	if (*top_a >= 0)
	{
		stack_b[++(*top_b)] = stack_a[(*top_a)--];
		ft_printf("pb\n"); // Imprime a operação "pb"
	}
}