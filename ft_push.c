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
void	push(t_stack *stack, int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;// Guarda o valor no campo value
	new_node->next = stack->top;// Aponta para o nó atualmente no topo da pilha
	new_node->index = index; // Atribui o índice ao campo index
	stack->top = new_node;
}

/*
	Nueva POP ajustada ayer (RANDOLPH)
	que Retorna el INDEX de valor
*/
int	pop_index(t_stack *stack, int *index)
{
	t_node	*temp;
	int		value;
	// int		index;

	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
		return (-1);
	}
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	// index = temp->index;
	*index = temp->index;
	free(temp);
	return (value);
}

/*
	Função para desempilhar (pop) ANTERIOR um valor da pilha
	ou Remove o nó do topo da pilha e retorna o valor desse nó
	(usado em PA e PB)#########
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
	int index;

	index = 0;//Inicializar a variavel
	
	if (is_empty(stack_b))
	{
		ft_printf("Error\n");
	}
	value = pop(stack_b);
	push(stack_a, value,index);
	ft_printf("pa\n");
}

/*
	Função para empilhar (push) elemento da pilha A para a pilha B
	com paramtero de tipo local ou membros
*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	int	value;
	int index;

	if (is_empty(stack_a))
	{
		ft_printf("Error\n");
		return ;
	}
	value = pop_index(stack_a,&index);
	push(stack_b, value,index);
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
