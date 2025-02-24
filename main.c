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

/* */
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
// display(stack_a);
// 	 	 ft_printf("____________________\n");
	// Verifica se a inicialização foi bem-sucedida
	if (length_elements <= 0)
	{
		ft_printf("Error\n");
		free_stack(stack_a);  // Libera a pilha A
		free_stack(stack_b);  // Libera a pilha B
		return (1);
	}

	//Exibe o estado inicial das pilhas
	//  ft_printf("Estado inicial da pilha A:\n");
	//  display(stack_a);
	//  ft_printf("Estado inicial da pilha B:\n");
	//  display(stack_b);
	 

	 assig_indice(stack_a);
	//  display(stack_a);
	//  ft_printf("____________________\n");

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
		{
			ksort(stack_a, stack_b);
			// ksort_part_one(&stack_a,&stack_b,length_elements);
			// ksort_part_two(&stack_a,&stack_b,length_elements);
		}
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
	// ARG="1 99 3 4 0"; ./push_swap $ARG | ./checker_linux $ARG
	// ARG="4 67 3 87 23"; ./push_swap "4 67 3 87 23"
	
	// jcongolo@c2r8s6 ~/Desktop/push_swap
	// ARG="4 67 3 87 23"; ./push_swap 4 6 2 | ./checker_linux 4 6 2

	
	//"" "c"
	//ARG=$(shuf -i 1-1000000 -n 10 | tr '\n' ' '); ./push_swap $ARG | wc -l

	// ARG=$(seq 1 10 | sort -R | tr '\n' ' '); ./push_swap $ARG | wc -l
	/*
		comando para gerar sequencias de numeros
		seq 1 10 | sort -R | paste -sd ' ' -
	*/

/*
	./push_swap 63 95 20 46 1 54 68 85 8 4 34 11 51 48 72 78 16 93 47 26 82 75 6 18 81 14 5 99 38 74 90 58 9 33 67 49 71 89 60 86 43 69 96 30 100 31 94 41 27 62 40 37 98 22 2 79 19 52 64 32 13 45 17 92 28 70 42 83 61 15 24 7 77 91 12 80 50 76 21 55 39 97 36 66 25 53 10 44 88 56 3 87 84 29 73 23 59 57 35 65 | wc -l
	(604)
	./push_swap 94 20 39 43 11 87 25 57 97 31 82 23 33 8 38 17 47 92 37 86 91 44 100 50 40 34 72 73 36 30 4 84 53 90 80 14 6 5 81 71 10 66 3 2 35 64 51 69 59 42 27 54 9 65 28 12 75 63 83 13 52 98 60 88 15 76 56 29 74 48 19 70 21 78 18 24 85 1 32 45 46 77 22 49 61 62 95 93 89 58 68 16 41 55 99 26 79 7 96 67 | wc -l
	(582)
	./push_swap 91 22 96 12 49 8 66 43 76 6 32 26 79 14 35 88 13 48 63 4 90 82 64 25 36 58 2 65 100 39 16 44 99 74 84 85 80 37 34 29 5 69 47 98 73 38 7 11 97 27 92 68 15 21 46 94 83 62 20 52 3 18 61 17 57 70 23 42 56 28 60 31 71 1 50 78 55 87 24 41 72 81 54 93 59 19 89 95 33 86 10 45 75 30 67 51 53 9 77 40 | wc -l
	(575)
	./push_swap 83 23 73 60 31 65 20 87 12 92 43 48 6 77 47 68 69 76 81 78 37 59 35 62 29 85 86 51 9 38 55 56 13 79 57 7 98 34 74 11 18 66 49 1 3 95 19 72 100 75 44 33 10 58 30 36 90 54 22 16 97 32 91 2 70 99 94 4 50 71 84 26 21 8 15 63 88 96 41 42 67 46 25 24 80 5 64 52 17 89 61 27 93 82 45 39 14 28 53 40 | wc -l	
	(588)
	./push_swap 60 17 5 1 97 84 81 45 85 65 16 47 35 38 70 54 83 10 30 41 55 40 26 90 24 8 32 3 52 69 89 93 21 50 48 29 68 87 99 43 53 7 49 76 86 22 72 39 15 66 46 42 94 82 33 6 56 34 12 67 19 11 23 9 100 28 73 74 63 57 37 77 58 71 75 18 92 59 79 91 96 78 44 61 2 98 64 27 25 95 13 31 20 36 88 51 4 14 62 80 | wc -l
	(566)
	./push_swap 69 79 70 52 62 41 54 66 96 15 29 4 81 88 3 18 87 59 77 19 92 55 53 10 33 76 56 82 65 68 22 97 50 90 7 83 16 28 35 46 91 49 20 40 57 100 51 93 8 25 21 61 71 47 34 11 24 64 5 58 9 63 31 6 74 44 86 30 99 45 42 73 75 43 13 95 80 89 37 32 36 48 1 14 98 12 39 85 67 2 94 60 26 84 78 17 27 72 38 23 | wc -l
	(562)
*/
