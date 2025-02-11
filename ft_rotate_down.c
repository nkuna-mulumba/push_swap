/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:49:44 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:49:44 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Função para rotacionar a pilha [A] ao contrário, movendo o último elemento para o topo
*/
void	rra(t_stack *stack_a, int print)
{
	// Declarar variáveis locais para percorrer a pilha
	t_node	*last;
	t_node	*second_last;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return;
	// Inicializar last e second_last
	last = stack_a->top;
	second_last = NULL;
	// Percorrer a pilha até o último elemento, iterando subsequente no while:
	while (last->next != NULL)//Verificar se nó anterior é diferente ao NULL
	{
		second_last = last; // second_last aponta para o nó atual
		last = last->next; // last avança para o próximo nó da pilha
	}
	last->next = stack_a->top; // Conecta o último nó ao antigo topo da pilha
	stack_a->top = last; // Atualiza o topo da pilha para o último nó percorrido no while
	second_last->next = NULL; // Penúltimo nó (second_last) agora é o último nó
	// Imprimir a operação realizada se print for diferente de zero
	if (print != 0)
		ft_printf("rra\n");
}

/*
    Função para rotacionar a pilha [B] ao contrário, movendo o último elemento para o topo
*/
void	rrb(t_stack *stack_b, int print)
{
	// Declarar variáveis locais para percorrer a pilha
	t_node	*last;
	t_node	*second_last;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return;
	// Inicializar last e second_last
	last = stack_b->top;
	second_last = NULL;
	// Percorrer a pilha até o último elemento, iterando subsequente no while:
	while (last->next != NULL)//Verificar se nó anterior é diferente ao NULL
	{
		second_last = last; // second_last aponta para o nó atual
		last = last->next; // last avança para o próximo nó da pilha
	}
	last->next = stack_b->top; // Conecta o último nó ao antigo topo da pilha
	stack_b->top = last; // Atualiza o topo da pilha para o último nó percorrido no while
	second_last->next = NULL; // Penúltimo nó (second_last) agora é o último nó
	// Imprimir a operação realizada se print for diferente de zero
	if (print != 0)
		ft_printf("rrb\n");
	
}

/*
	Função para rotacionar ambas as pilhas [A] e [B] ao contrário (rrr)
*/
void	rrr(t_stack *stack_a, t_stack *stack_b)
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
		rra(stack_a, 0); // Rotacionar a pilha [A] ao contrario
		rrb(stack_b, 0); // Rotacionar a pilha [B] ao contrario
		ft_printf("rrr\n"); // Imprime a operação realizada para os dois
	}
}
