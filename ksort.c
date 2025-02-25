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
 * ft_sqrt - Calcula a raiz quadrada inteira de um número.
 * @num: O número para o qual calcular a raiz quadrada.
 *
 * Esta função retorna a raiz quadrada inteira de um número dado.
 * Se o número não tem uma raiz quadrada inteira, a função retorna 0.
 *
 * Retorna: A raiz quadrada inteira de num ou 0 se não for uma raiz
   quadrada perfeita.
 */
int	ft_sqrt(int num)
{
	int	n;

	n = 1;
	if (num < 0)
		return (0);
	while (n * n <= num)
	{
		if (n * n == num)
			return (n);
		n++;
	}
	return (n);
}

/**
 * count_r - Conta o número de nós até encontrar o índice especificado.
 * @stack: Ponteiro para o nó inicial da pilha.
 * @index: Índice a ser encontrado na pilha.
 *
 * Esta função percorre a pilha a partir do nó dado e conta quantos nós são
 * percorridos até encontrar um nó com o índice especificado. Se o índice não
 * for encontrado, a função retornará o número de nós até o final da pilha.
 *
 * Retorna: O número de nós percorridos até encontrar o índice 
   ou até o final da pilha.
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
 * para stack_b com base em seus índices. O intervalo de movimentação é 
   determinado
 * pela raiz quadrada do tamanho da pilha multiplicada por 1.4 (14/10).
   Dependendo
 * do índice do nó no topo de stack_a, ele é movido para stack_b e possivelmente
 * rotacionado, ou stack_a é rotacionada.
 *
 * - Se o índice do nó no topo de stack_a for menor ou igual a i, o nó é movido
 *   para stack_b e stack_b é rotacionada.
 * - Se o índice do nó no topo de stack_a for menor ou igual a i + range, o nó
 *   é movido para stack_b.
 * - Caso contrário, stack_a é rotacionada.
   ### K_SORT 1 Move os elementos de stack_a para stack_b, 
   organizando parcialmente####
 */
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->top)
	{
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
	}
}

/**
 * k_sort2 - Transfere elementos de stack_b para stack_a em ordem específica.
 * @stack_a: Ponteiro para a pilha que receberá os elementos.
 * @stack_b: Ponteiro para a pilha de onde os elementos serão transferidos.
 * @length: Tamanho da pilha stack_b.
 *
 * Esta função implementa um algoritmo que transfere elementos de stack_b para
 * stack_a, ordenando-os de acordo com seus índices. A função utiliza 
   duas contagens:
 * - rb_count: Número de rotações para cima (rb) necessárias para trazer o nó 
   com o índice desejado para o topo.
 * - rrb_count: Número de rotações para baixo (rrb) necessárias para trazer o 
   nó com o índice desejado para o topo.
 *
 * Dependendo de qual contagem é menor, a função decide se deve rotacionar para 
   cima ou para baixo até que o nó
 * desejado esteja no topo de stack_b, e então transfere-o para stack_a.
 #### R_SORT2 Retorna os elementos para stack_a na ordem correta, minimizando 
  rotações###
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
				rb(stack_b, 1);
			pa(stack_a, stack_b);
			length--;
		}
		else
		{
			while (stack_b->top->index != length - 1)
			{
				rrb(stack_b, 1);
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
 */
void	ksort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_size(stack_a);
	k_sort1(stack_a, stack_b, size);
	k_sort2(stack_a, stack_b, size);
}
