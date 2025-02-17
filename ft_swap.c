/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:57:16 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:57:16 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Funçao para trocar os dois elementos
*/
void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	// `first`aponta ou armazena o valor do nó do topo da pilha 
	first = stack->top;
	// `second` aponta ou armazena o valor do nó logo abaixo do topo da pilha 
	second = stack->top->next;
	// `first` agora aponta para o nó que estava originalmente depois de `second`
	first->next = second->next;
	// Atualiza o topo da pilha para `second`, que agora é o novo topo
	second->next = first;
	// Atualiza o topo da pilha para `second`, que agora é o novo topo
	stack->top = second;
}

// Função que verifica se a pilha tem pelo menos dois elementos
int	can_swap(t_stack *stack)
{
	// Retornar verdadeiro se a pilha tem pelo menos dois elementos
	return (stack->top != NULL && stack->top->next != NULL);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [A]
int	sa(t_stack *stack_a)
{
	// Verifica se há pelo menos dois elementos na pilha usando can_swap
	if (!can_swap(stack_a))
	{
		// Não há elementos suficientes para trocar
		return (0);
	}
	// Chamar 'swap' para trocar as posições dos dois primeiros valores de [A]
	swap(stack_a);
	// Imprime a operação realizada
	ft_printf("sa\n");
	return (1);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [B]
int	sb(t_stack *stack_b)
{
	// Verifica se há pelo menos dois elementos na pilha usando can_swap
	if (!can_swap(stack_b))
	{
		// Não há elementos suficientes para trocar
		return (0);
	}
	// Chamar 'swap' para trocar as posições dos dois primeiros valores de [B]
	swap(stack_b);
	// Imprime a operação realizada
	ft_printf("sb\n");
	return (1);
}

//Funçao para trocar simultaneamente 2 primeiro elementos de [A] e [B]
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	/*
		Declarar variaveis que recebera a funçao (can_swap) para verificar 
		se a pilha tem pelomenos dois elelemntos para trocar
	*/
	int	can_swap_a;
	int	can_swap_b;

	//Chamar a funçao (can_swap)
	can_swap_a = can_swap(stack_a);
	can_swap_b = can_swap(stack_b);
	/*
		Validar se na pilha A foi encontrada pelomenos dois 
		valores na pilha chama (swap) para trocar as posiçoes
	*/
	if (can_swap_a)
		//chamar (swap) para trocar as posiçoes
		swap(stack_a);
	/*
		Validar se na pilha B foi encontrada pelomenos dois 
		valores na pilha chama (swap) para trocar as posiçoes
	*/
	if (can_swap_b)
		//chamar (swap) para trocar as posiçoes
		swap(stack_b);
	//Se as duas pilha contem pelomenos dois valor é imprimido a operaçao
	if (can_swap_a && can_swap_b)
		ft_printf("ss\n");
}