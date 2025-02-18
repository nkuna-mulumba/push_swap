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

/**/
int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int length_elements;

	stack_a = NULL;
	stack_b = NULL;
	(void)argc;  // Ignora o parâmetro argc para evitar avisos

	// Inicializa as pilhas com os valores dos argumentos
	length_elements = initialize_stacks(argv, &stack_a, &stack_b);

	// Verifica se a inicialização foi bem-sucedida
	if (length_elements <= 0)
	{
		ft_printf("Error\n");
		free_stack(stack_a);  // Libera a pilha A
		free_stack(stack_b);  // Libera a pilha B
		return (1);
	}

	//Exibe o estado inicial das pilhas
	// ft_printf("Estado inicial da pilha A:\n");
	// display(stack_a);
	// ft_printf("Estado inicial da pilha B:\n");
	// display(stack_b);

	// Chama as funções de ordenação com base no número de elementos
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
			sort_large(stack_a, stack_b, length_elements);
	}

	//Exibe o estado final das pilhas
	// ft_printf("______________________________\n");
	// ft_printf("Estado final da pilha A:\n");
	// display(stack_a);
	// ft_printf("Estado final da pilha B:\n");
	// display(stack_b);

	// Libera a memória alocada para as pilhas
	free_stack(stack_a);
	free_stack(stack_b);

	return (0);
}



	// CHEQUEAR
	// % ARG="1 99 3 4 0"; ./push_swap $ARG | ./checker_linux $ARG
	// % ARG="4 67 3 87 23"; ./push_swap "4 67 3 87 23"
	// Erro: Argumento '4 67 3 87 23' contém caracteres inválidos
	// jcongolo@c2r8s6 ~/Desktop/push_swap
	// % ARG="4 67 3 87 23"; ./push_swap 4 6 2 | ./checker_linux 4 6 2

	//  % ./push_swap " 1 3  2  " "  4-5  " should give an error (OK)
	//   % ./push_swap " 1 3  54-33" retornar error              (OK)
	//   ./push_swap 5 4 3 2 1 "" string null retornar error     (OK)

