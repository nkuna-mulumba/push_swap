/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 18:02:08 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 18:02:08 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Função para empilhar (push) ou adicionar
 * um novo valor no topo da pilha junto com um índice.
 * (usado em PA e PB)
 * 
 * @param stack: Ponteiro para a pilha onde o valor será adicionado.
 * @param value: O valor a ser adicionado ao topo da pilha.
 * @param index: O índice associado ao valor a ser adicionado.
 */
void	push(t_stack *stack, int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	new_node->index = index;
	stack->top = new_node;
}

/*
	Função para desempilhar ou remover
	o valor do topo da pilha e retornar o índice associado.
*/
int	pop_index(t_stack *stack, int *index)
{
	t_node	*temp;
	int		value;

	if (is_empty(stack))
		return (-1);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	*index = temp->index;
	free(temp);
	return (value);
}

/*
	Função para desempilhar um valor da pilha
	ou Remove o nó do topo da pilha e retorna o valor desse nó
	(usado em PA e PB)
*/
int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (is_empty(stack))
		return (-1);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	return (value);
}

/*
	Função para empilhar (push) elemento da pilha B para a pilha A
	com paramtero de tipo local ou membros
*/
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;
	int	index;

	index = 0;
	if (is_empty(stack_b))
		return ;
	value = pop(stack_b);
	push(stack_a, value, index);
	ft_printf("pa\n");
}

/*
	Função para empilhar (push) elemento da pilha A para a pilha B
	com paramtero de tipo local ou membros
*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	int	value;
	int	index;

	if (is_empty(stack_a))
		return ;
	value = pop_index(stack_a, &index);
	push(stack_b, value, index);
	ft_printf("pb\n");
}
