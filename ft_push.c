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

/*
	Função para empilhar (push) ou adicionar
    um novo valor no topo da pilha
	(usado em PA e PB)
*/
void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

/*
	Função para desempilhar (pop) um valor da pilha
	ou Remove o nó do topo da pilha e retorna o valor desse nó
	(usado em PA e PB)
*/
int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
		return (-1);
	}
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

	if (is_empty(stack_b))
	{
		ft_printf("Error\n");
	}
	value = pop(stack_b);
	push(stack_a, value);
	ft_printf("pa\n");
}

/*
	Função para empilhar (push) elemento da pilha A para a pilha B
	com paramtero de tipo local ou membros
*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	int	value;

	if (is_empty(stack_a))
	{
		ft_printf("Error\n");
	}
	value = pop(stack_a);
	push(stack_b, value);
	ft_printf("pb\n");
}

/*
	Função para verificar se a string representa um
	número válido dentro do intervalo de int e retornar o valor convertido
*/
long	ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	long	num;

	(void)stack_a;
	(void)stack_b;
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		num = 2147483648;
		return (num);
	}
	return ((int)num);
}
