/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:53:57 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-16 16:53:57 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"
/*
	Implementaçao de algoritimo de ordeçao Radix Sort
 	Adaptado para numeros negativos e positivos
*/

/*
	*Objetivo: Ordenar os números na pilha usando Radix Sort.
	*int max = get_max(stack, n - 1): Encontra o maior valor na pilha.
	*while (max / exp > 0): Loop através de cada posição decimal (unidades,
	dezenas, centenas, etc.).
      - count_digits: Conta os dígitos na posição exp.
      - adjust_positions: Ajusta as posições e organiza os números.
*/
void	radix_sort(Stacks *stacks, int stack[], int n)
{
	int	max_val;
	int	exp;
	int	output[n]; //Array de saida para armazenar resultado ordenado
	int	count[10]; //Declarar array de contagem
	
	max_val = get_max(stacks);// Chamada ajustada para usar o objeto Stacks
	// Se max_val for 0 e todos os elementos de stack forem 0, não há necessidade de ordenar
	if (max_val == 0)
	{
		return;
	}
	
	/*
		Inicializar 'exp' com 1 para começar com as unidades.
		'exp' extrai o dígito específico de cada elemento.
	*/
	exp = 1;
	while (max_val / exp > 0)
	{
		/*
			Inicializar array de contagem em cada iteraçao com 0 em cada posiçao 
			para armazenar a contagem dos dígitos (0-9)
		*/
		ft_bzero(count, sizeof(count));
		
		// Contar dígitos na posição decimal atual (exp) na pilha positiva
		count_digits(stack, n - 1, exp, count);
		// Ajustar posições e organizar os elementos
		adjust_positions(stack, output, n - 1, exp, count);
		// Atualizar "exp" próxima posição decimal (dezenas, centenas, etc.)
		exp *= 10;
	}
}

/*
	*Objetivo: Ordenar os números positivos.
	*if (stacks->pos_top >= 0): Verifica se há números positivos na pilha.
	  - radix_sort: Ordena a pilha de números positivos.
*/
void	sort_positives(Stacks *stacks)
{
	//Acessar elemento - index pos_top, verificando se ha numeros positivos
	if (stacks->pos_top >= 0)
	{
		//Ordenar valor positivos na pilha de numeros positivos, ajustando tamanho exacto de elementos
		radix_sort(stacks, stacks->pos_stack, stacks->pos_top + 1);
	}
}

/*
	*Objetivo: Ordenar os números negativos e convertê-los de volta para valores negativos.
	*if (stacks->neg_top >= 0): Verifica se há números negativos na pilha.
	  - radix_sort: Ordena a pilha de números negativos.
	  - while (i <= stacks->neg_top): Converte os valores absolutos de volta para negativos.
*/
void	sort_negatives(Stacks *stacks)
{
	int	i;
	// Verificar se há elementos na pilha de números negativos
	if (stacks->neg_top >= 0)
	{
		// Ordenar os valores absolutos na pilha de números negativos, ajustando tamanho exacto de elementos
		radix_sort(stacks, stacks->neg_stack, stacks->neg_top + 1);
		// Reverter os valores absolutos de volta para negativos
		i = 0;
		while (i <= stacks->neg_top)
		{
			stacks->neg_stack[i] = -stacks->neg_stack[i];
			i++;
		}
	}
}

/*
	*Objetivo: Combinar todos os passos anteriores para ordenar o array 
			   stack com números positivos e negativos.
	*separate_numbers: Separa os números em positivos e negativos.
	*sort_positives: Ordena a pilha de números positivos.
	*sort_negatives: Ordena a pilha de números negativos.
	*Combinar Resultados: Combina as pilhas ordenadas de volta no array stack.
*/
void combined_radix_sort(int stack[], int n)
{
	/*
		Declarar uma instância da estrutura Stacks usada para armazenar 
		e organizar os números positivos e negativos em pilhas separadas.
	*/
	Stacks	stacks;
	int	i;
	int	j;

	// Separar números positivos e negativos
	separate_number(stack, n - 1, &stacks);
	// Ordenar números positivos
	sort_positives(&stacks);
	// Ordenar números negativos e revertê-los para negativos
	sort_negatives(&stacks);

	i = 0;
	// Adicionar números negativos revertidos à pilha original
	while (stacks.neg_top >= 0)
	{
		// Adicionar valores negativos ordenados ao início da stack
		stack[i++] = stacks.neg_stack[stacks.neg_top--];
	}
	j = 0;
	while (j <= stacks.pos_top)
	{
		// Adicionar valores positivos ordenados após os negativos
		stack[i++] = stacks.pos_stack[j++];
	}	
}
// Imprimir elementos de [A] e [B] vazio
/*
	 * Indexar -> 
	 * 
	 * Primero verifico si el tamaño de elementos es 3
	 * 
	 * Segundo si es menor a 7 elementos y mayor a 3 elementos
	 * { }
	 * y ultimo si es mayor a 7
	 * { Voy a aplicar un algorimo de ordenacion para push_swapX }

// TESTAR RADIX SORT
int main()
{
	//int stack[] = {170, -45, 75, -90, 802, 24, -2, 66};
	int stack[] = 
	{34, -2, 45, -32, 11, -78, 99, 27, -48, 62, 0, -5, 3,
	-12, 87, 45, -33, 56, -1, 88, -92, 33, -6, 55, -15, 23,
	-17, 77, -90, 29, 18, -36, 61, -10, 12, -40, 71, -14, 93,
	-9, 44, -25, 32, -8, 57, -4, 16, -13, 81, -7, 2, 50, -39,
	35, -19, 63, -23, 14, -29, 75, -21, 66, -34, 28, -11, 59,
	-20, 79, -42, 17, -3, 22, -44, 30, -22, 47, -30, 24, -27,
	67, -18, 37, -24, 46, -26, 20, -41, 73, -38, 9, -49, 40,
	-31, 69, -28, 60, -43, 25, -35, 7, -46, 19, -16, 51, -47,
	41, -45, 21};
	int top;
	int	i;


	// Ajusta para usar 'top' como índice exato de stack[]
	top = sizeof(stack) / sizeof(stack[0]);
	i = 0;

	// Imprimir o array inicial
	//ft_printf("Array inicial: \n");
	while (i < top)
	{
		//ft_printf("%d ", stack[i]);
		i++;
	}
	//ft_printf("\n");
	
	// Chama a função de ordenação
	combined_radix_sort(stack, top);

	// Imprimir a pilha ordenado
	//ft_printf("Pilha ordenada:\n");
	i = 0;
	while (i < top)
	{
		//ft_printf("%d ", stack[i]);
		i++;
	}
	//ft_printf("\n");

	return 0;
}
*/