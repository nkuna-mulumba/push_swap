/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ord_sort_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 18:17:18 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-14 18:17:18 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Função auxiliar para verificar se a pilha está ordenada	
*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (is_empty(stack) || stack->top == NULL)// Pilha não existe ou não possui pelo menos dois valores
		return (1);
	current = stack->top;// Aponta para o topo da pilha
	while (current->next != NULL)// Para no último elemento
	{
		if (current->value > current->next->value)// Verifica se o valor atual é maior que o próximo
			return (0);// Pilha não está ordenada
		current = current->next;// Avança para o próximo elemento
	}
	return (1);// Pilha está ordenada
}

/*
	Função auxiliar de (sort_four) para 
	encontrar o índice do menor valor na stack_a
*/
int	find_min_position(t_stack *stack)
{
	t_node	*currente;
	int		min;
	int		min_pos;
	int		i;

	if (!stack || !stack->top)
		return (-1);// Retorna -1 se a pilha estiver vazia
	currente = stack->top;//apunta ao topo da pilha
	min = currente->value;//Armazena o valor do topo como o mínimo inicial
	min_pos = 0;//Inicializa a posição do mínimo
	i = 0;//Inicializa o índice
	while (currente)// Percorre a pilha até o final
	{
		if (currente->value < min)//Verifica se o valor atual é menor que o mínimo
		{
			min = currente->value;//Atualiza o mínimo 
			min_pos = i;//Atualiza a posição do mínimo 1
		}
		currente = currente->next;//Avança para o próximo elemento da pilha
		i++;//Incrementa o índice
	}
	return (min_pos);//Retorna a posição do menor valor (3)
}

/*
	Funçao para mover elementos menores 
	ate stack_a ter apenas 5 elementos
*/
void	move_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *total_elements)
{
	int	min_pos;

	while (*total_elements > 5)
	{
		min_pos = find_min_position(stack_a);
		if (min_pos <= *total_elements / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			while (++min_pos <= *total_elements)
				rra(stack_a, 1);
		}
		pb(stack_b, stack_a);
		(*total_elements)--;
	}
}
/*
	Funçao para ordenar e mesclagem de 
	valores removidos
*/
void	finalize_sort(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
	if (total_elements == 5)
		sort_five(stack_a, stack_b, 0);
	else if (total_elements == 4)
		sort_four(stack_a, stack_b);
	else if (total_elements == 3)
		sort_three(stack_a);
	else if (total_elements == 2)
		sort_two(stack_a);
	//Devolver valores removido
	while (!is_empty(stack_b))
		pa(stack_a, stack_b);
	//Ultima verificaçao se esta ordenada
	while (!is_sorted(stack_a))
		ra(stack_a, 1);
}
