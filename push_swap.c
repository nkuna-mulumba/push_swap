/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 13:38:10 by jcongolo          #+#    #+#             */
/*   Updated: 2024-12-27 13:38:10 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funçao para inicializar os Stacks
void	init_stacks(int *top_a, int *top_b)
{
	*top_a = -1;
	*top_b = -1;
}

//Funçao para inicializar Stack com valores de ARGV convertidos e validos
void	init_stack(int stack[], int *top, int argc, char **argv)
{
	int	i;

	i = 1; // Começamos do índice 1 para ignorar o nome do programa
	*top = -1; // *top é inicializado para -1 para indicar que a pilha está vazia.
	while(i < argc)
	{
		stack[++(*top)] = (int)ft_validate_and_convert(argv[i]); //Inserir valor na Pila convertido para INT
		if (!ft_check_element(stack, *top)) // Verifica a unicidade dos elementos na pilha stack_a
		{
			ft_printf("ERROR 'VALORES DUPLICADOS'\n");
			exit (1);
		}
		i++;
	}
}
// Setup de Inicialização de Stacks e sua conversão
void	setup_stacks(int stack_a[], int *top_a, int *top_b, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("ERROR 'NUMERO DE ARGUMENTO INSUFIENTE'\n");
		exit (1);
	}

	init_stacks(top_a, top_b); // Inicializa as variáveis top_a e top_b	
	init_stack(stack_a, top_a, argc, argv);// Inicializa a pilha A com os valores fornecidos
}


//Funçao para imprimir a pilha (para depuraçao)
void	print_stack(int stack[], int top)
{
	int	i = top - 1;
	while (i >= 0)
	{
		ft_printf("%d\n", stack[i]);
		i--;
	}
}
void	sort_stack_a(int stack_a[], int *top_a)
{
	if (*top_a == 2)
	{
		// 0 1 2 op: (Nao retorna nada porque ja esta ordenadas)
		if (stack_a[2] > stack_a[1] && stack_a[1] > stack_a[0])
		{
			return;
		}
		// 2 0 1 op: 
		if (stack_a[2] > stack_a[1] && stack_a[1] < stack_a[0] && stack_a[0] > stack_a[2])
		{
			sa(stack_a, *top_a); // 2 1 0
    		ra(stack_a, *top_a); // 1 0 2
    		sa(stack_a, *top_a); // 0 1 2
		}
		// 2 1 0 op: 
		else if (stack_a[2] > stack_a[1] && stack_a[1] > stack_a[0])
		{
			ra(stack_a, *top_a); //021
			sa(stack_a, *top_a); //012

		}
		// 1 0 2 op:
		else if (stack_a[2] < stack_a[1] && stack_a[1] < stack_a[0])
		{
			rra(stack_a, *top_a); //021
			sa(stack_a, *top_a); //012
		}
		
		// 1 2 0 op:
		else if (stack_a[2] < stack_a[1] && stack_a[0] < stack_a[1] && stack_a[2] < stack_a[0])
		{
			ra(stack_a, *top_a); // 120
		}
		// 0 2 1 op:
		else if (stack_a[2] < stack_a[1] && stack_a[2] > stack_a[0] && stack_a[1] > stack_a[0])
		{
			sa(stack_a, *top_a); // 021
		}
	}
}

//Funçao para imprimir as dois pilhas A e B
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b)
{
	// Imprimir as pilhas ordenadas
	ft_printf("Stack[A]:\n");
	print_stack(stack_a, top_a + 1);
	ft_printf("\n");
	ft_printf("Stack[B]:\n");
	print_stack(stack_b, top_b + 1);
}
// Ordenar as pilhas antes de imprimir
//combined_radix_sort(stack_a, top_a + 1);
//combined_radix_sort(stack_b, top_b + 1);
