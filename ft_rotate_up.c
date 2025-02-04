/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:49:00 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:49:00 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Função para rotacionar a pilha A, movendo o primeiro elemento para o final
*/
void ra(t_stack *stack_a, int print)
{
	// Declarar a variável local que armazenará o novo nó a ser adicionado na base da pilha A
	t_node	*new_node;
	// Declarar a variável local para percorrer a pilha
	t_node	*current;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return;

	// O ponteiro para o nó de topo é armazenado na variável (new_node)
	new_node = stack_a->top;

	// Atualizar o topo da pilha para ser o segundo nó
	stack_a->top = stack_a->top->next;
	// Definir o próximo nó do nó armazenado em (new_node) como NULL
	new_node->next = NULL;

	// Atualizar `current` para apontar para o novo topo da pilha
	current = stack_a->top;
	// Percorrer a pilha até o último elemento
	while (current->next != NULL)
	{
		current = current->next;
	}

	// Adicionar o nó armazenado ao final da pilha
	current->next = new_node;
	// Verifico se (print) é diferente a zero, imprimir a operação realizada
	if (print != 0)
	{
		ft_printf("Op:[ra]\n");
	}
}

/*
	Função para rotacionar a pilha B, movendo o primeiro elemento para o final
*/
void rb(t_stack *stack_b, int print)
{
	// Declarar a variável local que armazenará o nó a ser movido para o final da pilha A
	t_node *new_node;
	// Declarar a variável local para percorrer a pilha
	t_node *current;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return;

    // O ponteiro para o nó de topo é armazenado na variável (new_node)
	new_node = stack_b->top;
	// Atualizar o topo da pilha para ser o segundo nó
	stack_b->top = stack_b->top->next;
	// Definir o próximo nó do nó armazenado em (new_node) como NULL
	new_node->next = NULL;

	// Atualizar `current` para apontar para o novo topo da pilha
	current = stack_b->top;

	// Percorrer a pilha até o último elemento
	while (current->next != NULL)
	{
		current = current->next;
	}
	// Adicionar o nó removido ao final da pilha
	current->next = new_node;

	// Verifico se (print) é diferente a 0, imprimir a operação realizada
	if (print)
		ft_printf("Op:[rb]\n");
}

/*
    Função para rotacionar ambas as pilhas A e B, movendo o primeiro elemento de cada pilha para o final
*/
void rr(t_stack *stack_a, t_stack *stack_b)
{
	//Declarar variaveis de verificaçao se as pilhas contem pelomenos dois valores
	int	can_rotate_a;
	int	can_rotate_b;

	// Verifica se ambas as pilhas têm pelo menos dois elementos
	can_rotate_a = (stack_a->top != NULL && stack_a->top->next != NULL);
	can_rotate_b = (stack_b->top != NULL && stack_b->top->next != NULL);

	// Validar se foi encontrado dois valores nas pilhas
	if (can_rotate_a && can_rotate_b)
	{
		ra(stack_a, 0); // Rotaciona a pilha A sem imprimir
		rb(stack_b, 0); // Rotaciona a pilha B sem imprimir
		ft_printf("Op:[rr]\n"); // Imprime a operação realizada
	}
}
