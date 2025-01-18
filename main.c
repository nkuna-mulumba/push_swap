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

// incluir header do projecto
#include "push_swap.h"

//Contador para operadores
int	count_pb = 0;
int	count_pa = 0;
int	count_sa = 0;
int	count_sb = 0;
int	count_ss = 0;
int	count_ra = 0;
int	count_rb = 0;
int	count_rr = 0;
int	count_rra = 0;
int	count_rrb = 0;
int	count_rrr = 0;

// Defina um array com as operações
char	*operation[] = {"pb", "pa", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr"};
int		num_operation = sizeof(operation) / sizeof(operation[0]);
int		i = 0;

//FUnçao para decidir operaçao beseada no array
char	*decide_next_operation()
{
	if (i < num_operation)
	{
		return operation[i++];
	}
	else
	{
		return NULL;
	}
}

int main(int argc,	char **argv)
{
	int	stack_a[MAX_SIZE]; //Tamanho fixo ou estatica
	int	stack_b[MAX_SIZE]; //Tamanho fixo ou estatica
	int	top_a;
	int	top_b;

	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);






	
	/*
	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pb\n");
	count_pb++;
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pb\n");
	count_pb++;
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pb\n");
	count_pb++;
	// Trocar os 2 primeiro elementos de [A] e [B] TENHO QUE VER ISSO
	ss(stack_a, top_a, stack_b, top_b);
	ft_printf("ss\n");
	count_ss++;
	//Rodar elementos de [A] e [B] para CIMA
	rr(stack_a, top_a, stack_b, top_b);
	ft_printf("rr\n");
	count_rr++;
	// Mover elemento do top[B] para top[A]
	pa(stack_a,&top_a, stack_b, &top_b);
	ft_printf("pa\n");
	count_pa++;
	//Rodar elementos de [A] para BAIXO
	rra(stack_a,top_a);
	ft_printf("rra\n");
	count_rra++;
	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pb\n");
	count_pb++;
	//Rodar elementos de [A] e [B] para BAIXO
	rrr(stack_a, top_a, stack_b, top_b);
	ft_printf("rrr\n");
	count_rrr++;
	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pb\n");
	count_pb++;
	// Trocar os 2 primeiro elementos de [B]
	sb(stack_b, top_b);
	ft_printf("sb\n");
	count_sb++;
	// Trocar os 2 primeiro elementos de [A]
	sa(stack_a, top_a);
	ft_printf("sa\n");
	count_sa++;
	// Mover elemento do top[B] para top[A]
	pa(stack_a, &top_a, stack_b, &top_b);
	ft_printf("pa\n");
	count_pa++;

	//Imprimir o numero total de operaçoes realizada:
	ft_printf("Total de operaçoes realizada:\n");
	ft_printf("sa: %d\n", count_sa);
	ft_printf("sb: %d\n", count_sb);
	ft_printf("ss: %d\n", count_ss);
	ft_printf("pa: %d\n", count_pa);
	ft_printf("pb: %d\n", count_pb);
	ft_printf("ra: %d\n", count_ra);
	ft_printf("rb: %d\n", count_rb);
	ft_printf("rr: %d\n", count_rr);
	ft_printf("rra: %d\n", count_rra);
	ft_printf("rrb: %d\n", count_rrb);
	ft_printf("rrr: %d\n", count_rrr);
	*/

// //Bucle hasta ordenar el stack a y b, while(has_sorted())
	// combined_radix_sort(stack_a, top_a + 1);
	// combined_radix_sort(stack_b, top_b + 1);
	// //Funcion que envie los valores del stack_b al stack_a


//IMPRESAO COM VAALORES

	/* 

	combined_radix_sort(stack_a, top_a + 1);
	combined_radix_sort(stack_b, top_b + 1);

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
	return (0);
}