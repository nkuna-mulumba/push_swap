/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuna <nkuna@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 09:41:47 by nkuna             #+#    #+#             */
/*   Updated: 2025-02-05 09:41:47 by nkuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Funçao para ordenara dois valor no stack_a
*/
void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	a = stack->top->value;
	b = stack->top->next->value;
	if (a > b)
		sa(stack);
}



/*
	Função para ordenar três valores na stack_a
*/
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->top || !stack->top->next || !stack->top->next->next)
		return ;
	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		(sa(stack), rra(stack, 1));
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		(sa(stack), ra(stack, 1));
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
}



/*
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);
	if (min_pos == 1)
		ra(stack_a, 1);
	else if (min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (min_pos == 3)
		rra(stack_a, 1);
	if (!is_sorted(stack_a))
	{
		pb(stack_b, stack_a);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}



/*
	Função para ordenar cinco valores na stack_a 
*/
void	sort_five(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	min_pos;

	while (count++ < 1)
	{
		min_pos = find_min_position(stack_a);
		if (min_pos == 1)
			ra(stack_a, 1);
		else if (min_pos == 2)
		{
			ra(stack_a, 1);
			ra(stack_a, 1);
		}
		else if (min_pos == 3)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		else if (min_pos == 4)
			rra(stack_a, 1);
		if (!is_sorted(stack_a))
			pb(stack_b, stack_a);
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b);
}



/*
	Função para ordenar um grande número de elementos na stack_a 
	utilizando a stack_b como pilha auxiliar.
	Esta função utiliza uma combinação de divisão e conquista e funções 
	auxiliares para garantir a ordenação eficiente dos elementos.
	* stack_a: Pilha principal que contém os elementos a serem ordenados.
	* stack_b: Pilha auxiliar usada durante o processo de ordenação.
	* total_elements: Número total de elementos na stack_a.

void	sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
	move_to_stack_b(stack_a, stack_b, &total_elements);
	finalize_sort(stack_a, stack_b, total_elements);
}
//1000000000000000000000000000000000000000000000000000000000000000
*/


/*
 * Função para separar números positivos e negativos
 * stack_a: Pilha original com todos os números
 * stack_pos: Pilha para armazenar números positivos
 * stack_neg: Pilha para armazenar números negativos
 */
void separate_numbers(t_stack *stack_a, t_stack *stack_pos, t_stack *stack_neg)
{
    while (!is_empty(stack_a))
    {
        int value = pop(stack_a);
        if (value < 0)
            push(stack_neg, value);
        else
            push(stack_pos, value);
    }
}
/*
 * Função para encontrar o maior número na pilha
 * stack: Pilha a ser examinada
 * Retorna o maior valor encontrado na pilha
 */
int get_max(t_stack *stack)
{
    int max;
    t_node *current;

    if (is_empty(stack))
        return (0);
    current = stack->top;
    max = current->value;
    while (current != NULL)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

/*
 * Função de ordenação por dígitos (Radix Sort) para números positivos
 * stack_a: Pilha de entrada
 * stack_b: Pilha auxiliar
 * exp: Dígito atual a ser ordenado (1, 10, 100, ...)
 */
void count_sort(t_stack *stack_a, t_stack *stack_b, int exp)
{
    int count[10] = {0};
    int i;
    t_node *current;

    // Contagem da frequência dos dígitos
    current = stack_a->top;
    while (current != NULL)
    {
        count[(current->value / exp) % 10]++;
        current = current->next;
    }

    // Transformar contagem em posição
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }

    // Mover elementos para stack_b baseado no dígito atual
    int size = stack_size(stack_a);
    while (size > 0)
    {
        int digit = (stack_a->top->value / exp) % 10;
        if (digit < 5)
        {
            pb(stack_b, stack_a);  // Movimento para stack_b
        }
        else
        {
            ra(stack_a, 1);  // Movimento dentro da stack_a
        }
        size--;
    }

    // Mover de volta para stack_a
    size = stack_size(stack_b);
    while (size > 0)
    {
        pa(stack_a, stack_b);  // Movimento de volta para stack_a
        size--;
    }
}




/*
 * Função de ordenação por dígitos (Radix Sort) para números negativos
 * stack_a: Pilha de entrada
 * stack_b: Pilha auxiliar
 * exp: Dígito atual a ser ordenado (1, 10, 100, ...)
 */
void count_sort_negatives(t_stack *stack_a, t_stack *stack_b, int exp)
{
    (void)stack_b; // Ignorar o parâmetro não utilizado
    int count[10] = {0};
    int i;
    t_node *current;

    // Contagem da frequência dos dígitos
    current = stack_a->top;
    while (current != NULL)
    {
        count[(abs(current->value) / exp) % 10]++;
        current = current->next;
    }

    // Transformar contagem em posição
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }

    // Construir a pilha ordenada
    int size = stack_size(stack_a);
    int output[size];
    current = stack_a->top;
    i = size - 1;
    while (i >= 0)
    {
        output[--count[(abs(current->value) / exp) % 10]] = current->value;
        current = current->next;
        i--;
    }

    // Mover os elementos de volta para stack_a
    while (!is_empty(stack_a))
        pop(stack_a);
    i = 0;
    while (i < size)
    {
        push(stack_a, output[i]);
        i++;
    }
}


/*
 * Função principal do Radix Sort para ordenar números positivos e negativos
 * stack_a: Pilha principal a ser ordenada
 * stack_b: Pilha auxiliar usada durante a ordenação
 */
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *stack_pos = init_stack();
    t_stack *stack_neg = init_stack();
    
    // Separar números positivos e negativos
    separate_numbers(stack_a, stack_pos, stack_neg);

    // Ordenar números positivos
    int max = get_max(stack_pos);
    int exp = 1;
    while (max / exp > 0)
    {
        count_sort(stack_pos, stack_b, exp);
        exp *= 10;
    }

    // Ordenar números negativos
    max = abs(get_max(stack_neg));
    exp = 1;
    while (max / exp > 0)
    {
        count_sort_negatives(stack_neg, stack_b, exp);
        exp *= 10;
    }

    // Combinar resultados
    while (!is_empty(stack_neg))
        push(stack_a, pop(stack_neg));
    while (!is_empty(stack_pos))
        push(stack_a, pop(stack_pos));
    
    // Libera a memória das pilhas temporárias
    free_stack(stack_pos);
    free_stack(stack_neg);
}


/*
 * Função para ordenar um grande número de elementos na stack_a
 * utilizando o Radix Sort adaptado para lidar com números negativos
 * e positivos.
 * stack_a: Pilha principal que contém os elementos a serem ordenados.
 * stack_b: Pilha auxiliar usada durante o processo de ordenação.
 * total_elements: Número total de elementos na stack_a.
 */
void sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
    (void)total_elements; // Ignorar o parâmetro não utilizado
    radix_sort(stack_a, stack_b);
}

