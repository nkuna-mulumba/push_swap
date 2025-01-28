/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:01:42 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-16 16:01:42 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,	char **argv)
{
	int	stack_a[MAX_SIZE]; //Tamanho fixo ou estatica
	int	stack_b[MAX_SIZE]; //Tamanho fixo ou estatica
	int	top_a;
	int	top_b;

	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);

	// Ordena a pilha A usando a função sort_stack_a
    sort_stack_a(stack_a, &top_a);

	// Imprime as pilhas A e B após a ordenação
	print_stacks(stack_a, top_a, stack_b, top_b);

	return (0);
}
/*
		// Iniciliazar [A] com elementos e [B] vazio
		ft_printf("Stacks inicializada, [A] com elementos e [B] sem elementos\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		
		// Mover elemento do top[A] para top[B]
		pb(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] após 1º'pb'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		pb(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] após o 2º'pb'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		pb(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] após o 3º'pb'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Trocar os 2 primeiro elementos de [A] e [B] TENHO QUE VER ISSO
		ss(stack_a, top_a, stack_b, top_b);
		ft_printf("\nStack [A] e [B] após 'ss'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		//Rodar elementos de [A] e [B] para CIMA
		rr(stack_a, top_a, stack_b, top_b);
		ft_printf("\nStack [A] e [B] após 'rr'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Mover elemento do top[B] para top[A]
		pa(stack_a,&top_a, stack_b, &top_b);
		ft_printf("\nStack[B] e [A] após o 1º'pa':\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		//Rodar elementos de [A] para BAIXO
		rra(stack_a,top_a);
		ft_printf("\nStack [A] após 'rra'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Mover elemento do top[A] para top[B]
		pb(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] e [B] após 4º'pb':\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		//Rodar elementos de [A] e [B] para BAIXO
		rrr(stack_a, top_a, stack_b, top_b);
		ft_printf("\nStack [A] após 'rrr'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Mover elemento do top[A] para top[B]
		pb(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] e [B]após o 5º'pb'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Trocar os 2 primeiro elementos de [B]
		sb(stack_b, top_b);
		ft_printf("\nStack [B] e [A] após 'sb'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Trocar os 2 primeiro elementos de [A]
		sa(stack_a, top_a);
		ft_printf("\nStack [A] e [B] após 'sa'\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");

		// Mover elemento do top[B] para top[A]
		pa(stack_a, &top_a, stack_b, &top_b);
		ft_printf("\nStack[A] e [B] após 2º'pa':\n");
		print_stacks(stack_a, top_a, stack_b, top_b);
		ft_printf("\n______________________________\n");
	*/	