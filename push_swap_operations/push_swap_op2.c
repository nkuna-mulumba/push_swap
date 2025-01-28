/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 10:17:09 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-17 10:17:09 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2025-01-17 09:50:54 by jcongolo         ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */

#include "../push_swap.h"

//Função para rodar todos os elementos da pilha A para cima
void	ra(int stack_a[], int top_a)

{
	int	first;
	int	i;

	if (top_a > 0) // Verifica se há pelo menos dois elementos na pilha
	{
		first = stack_a[top_a]; // Armazena o valor do topo da pilha em "first"
		i = top_a;
		while (i > 0) // Desloca todos os elementos da pilha uma posição para cima
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[0] = first;// Coloca o valor original do topo na base da pilha
		ft_printf("ra\n"); // Imprime a operação "ra"
	}
}

//Função para rodar todos os elementos da pilha "B" para cima
void	rb(int stack_b[], int top_b)
{
	int	first;

	if (top_b > 0)
	{
		first = stack_b[top_b];
		while (top_b > 0)
		{
			stack_b[top_b] = stack_b[top_b - 1];
			top_b--;
		}
		stack_b[0] = first;
		ft_printf("rb\n"); // Imprime a operação "rb"
	}
}

//Função para rodar os elementos da pilha "A" e "B" para cima simultaneamente
void	rr(int stack_a[], int top_a, int stack_b[], int top_b)
{
	ra(stack_a, top_a);
	rb(stack_b, top_b);
	ft_printf("rr\n"); // Imprime a operação "rr"
}

// Função para rodar todos os elementos da pilha "A" para baixo
void	rra(int stack_a[], int top_a)
{
	int	last;
	int	i;

	if (top_a > 0) // Verifica se há pelo menos dois elementos na pilha
	{
		last = stack_a[0]; // Armazena o valor da base da pilha em "last"
		i = 0;
		while (i < top_a) // Desloca todos os elementos da pilha uma posição para baixo
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[top_a] = last; // Coloca o valor original da base no topo da pilha
		ft_printf("rra\n"); // Imprime a operação "rra"
	}
}

// Função para rodar todos os elementos da pilha "B" para baixo
void	rrb(int stack_b[], int top_b)
{
	int	last;
	int	i;

	if (top_b > 0)
	{
		last = stack_b[0];
		i = 0;
		while (i < top_b)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[top_b] = last;
		ft_printf("rrb\n"); // Imprime a operação "rrb"
	}
}