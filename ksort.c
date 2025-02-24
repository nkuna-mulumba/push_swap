/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-22 16:21:33 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-22 16:21:33 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * count_r - Conta o número de nós até encontrar o índice especificado.
 * @stack: Ponteiro para o nó inicial da pilha.
 * @index: Índice a ser encontrado na pilha.
 *
 * Esta função percorre a pilha a partir do nó dado e conta quantos nós são
 * percorridos até encontrar um nó com o índice especificado. Se o índice não
 * for encontrado, a função retornará o número de nós até o final da pilha.
 *
 * Retorna: O número de nós percorridos até encontrar o índice ou até o final da pilha.
 */
int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

/**
 * k_sort1 - Ordena a pilha stack_a transferindo elementos para stack_b.
 * @stack_a: Ponteiro para a pilha a ser ordenada.
 * @stack_b: Ponteiro para a pilha auxiliar usada na ordenação.
 * @length: Tamanho da pilha stack_a.
 *
 * Esta função implementa um algoritmo de ordenação que move elementos de stack_a
 * para stack_b com base em seus índices. O intervalo de movimentação é determinado
 * pela raiz quadrada do tamanho da pilha multiplicada por 1.4 (14/10). Dependendo
 * do índice do nó no topo de stack_a, ele é movido para stack_b e possivelmente
 * rotacionado, ou stack_a é rotacionada.
 *
 * - Se o índice do nó no topo de stack_a for menor ou igual a i, o nó é movido
 *   para stack_b e stack_b é rotacionada.
 * - Se o índice do nó no topo de stack_a for menor ou igual a i + range, o nó
 *   é movido para stack_b.
 * - Caso contrário, stack_a é rotacionada.
 */
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	// display(stack_a);
	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	// ft_printf("------>lengyt%d",length);
	// exit(0);
	// int count = 0;
	// while (stack_a->top && count <= 20)
	while (stack_a->top)
	{
		// ft_printf("indexA->%d value a->%d\n",stack_a->top->index, stack_a->top->value);
		if (stack_a->top->index <= i)
		{
			pb(stack_b, stack_a);
			rb(stack_b, 1);
			i++;
		}
		else if (stack_a->top->index <= i + range)
		{

			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a, 1);
			
		// count++;
	}
	// exit(0);
}

/**
 * k_sort2 - Transfere elementos de stack_b para stack_a em ordem específica.
 * @stack_a: Ponteiro para a pilha que receberá os elementos.
 * @stack_b: Ponteiro para a pilha de onde os elementos serão transferidos.
 * @length: Tamanho da pilha stack_b.
 *
 * Esta função implementa um algoritmo que transfere elementos de stack_b para
 * stack_a, ordenando-os de acordo com seus índices. A função utiliza duas contagens:
 * - rb_count: Número de rotações para cima (rb) necessárias para trazer o nó com o índice desejado para o topo.
 * - rrb_count: Número de rotações para baixo (rrb) necessárias para trazer o nó com o índice desejado para o topo.
 *
 * Dependendo de qual contagem é menor, a função decide se deve rotacionar para cima ou para baixo até que o nó
 * desejado esteja no topo de stack_b, e então transfere-o para stack_a.
 */
void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->top, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->top->index != length - 1)
				rb(stack_b,1);
			pa(stack_a, stack_b);
			length--;
		}
		else
		{
			// int count = 0;
			while (stack_b->top->index != length - 1)
			{
				// ft_printf("B---->%d ---->%d",stack_b->top->index,stack_b->top->value);
				rrb(stack_b, 1);
				// count++;
				// if (count == 5)
				// 	exit(0);
			}
				
			pa(stack_a, stack_b);
			length--;
		}
	}
}

/**
 * ksort - Ordena uma grande pilha usando duas funções de ordenação.
 * @stack_a: Ponteiro para a pilha principal a ser ordenada.
 * @stack_b: Ponteiro para a pilha auxiliar usada na ordenação.
 *
 * Esta função implementa um algoritmo de ordenação para pilhas grandes. Primeiro,
 * calcula o tamanho da pilha stack_a. Em seguida, utiliza duas funções de ordenação
 * `k_sort1` e `k_sort2` para mover e ordenar os elementos entre stack_a e stack_b.
 * - `k_sort1`: Move elementos de stack_a para stack_b com base em índices.
 * - `k_sort2`: Move elementos de stack_b de volta para stack_a em uma ordem específica.
 */
void	ksort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	
	size = stack_size(stack_a);//Tamanho de nuumero da pilha
	k_sort1(stack_a, stack_b, size); //Ordena parcialmente movendo elementos de stack_a para stack_b
	k_sort2(stack_a, stack_b, size);//Completa a ordenação movendo elementos de stack_b de volta para stack_a
}
