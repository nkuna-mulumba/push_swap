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
	// Declarar variável local que servirá para adicionar valor em cada nó na pilha
	t_node	*new_node;

	// Alocar a memória para um novo nó
	new_node = malloc(sizeof(t_node));
	// Verifica se a alocação de memória falhou
	if (!new_node)
	{
		return;
	}
	/*
		Atribuir valor do parâmetro 'value' para 
		o campo 'value' do novo nó
    */
	new_node->value = value;

	// O próximo nó do novo nó é o nó atual no topo da pilha
	new_node->next = stack->top;
	// Atualizar o topo da pilha para o novo nó
	stack->top = new_node;
}

/*
    Função para desempilhar (pop) um valor da pilha
    ou Remove o nó do topo da pilha e retorna o valor desse nó
	(usado em PA e PB)
*/
int	pop(t_stack *stack)
{
	// Declarar variáveis locais que vão armazenar o valor do topo e o nó temporário
	t_node *temp;
	int	value;

	// Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
		// Retorna um valor indicador de erro (pode ser ajustado conforme necessário)
		return (-1);
	}
	// Armazena o nó atual no topo da pilha em uma variável temporária
	temp = stack->top;

	// Armazena o valor do nó a ser removido
	value = temp->value;

 	// Atualiza o topo da pilha para o próximo nó
	stack->top = stack->top->next;

	// Libera a memória do nó removido
	free(temp);

	 // Retorna o valor do nó removido
	return (value);
}
/*
    Função para empilhar (push) elemento da pilha B para a pilha A
	com paramtero de tipo local ou membros
*/
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	//Declarar variavel que armazenara o nó do topo da pilha B
	int	value;

	//Validar se a pilha B esta vazia antes de mover o nó do topo
	if (is_empty(stack_b))
	{
		ft_printf("Pilha B está vazia, não é possível empilhar para A\n");
		return;
	}
	// Armazenar o valor do nó movido
	value = pop(stack_b);
	// Adicionar o nó movido no topo da pilha A
	push(stack_a, value);
	//Imprimir a operaçao
	ft_printf("Op:[pa]\n");
}

/*
    Função para empilhar (push) elemento da pilha A para a pilha B
	com paramtero de tipo local ou membros
*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	//Declarar variavel que armazenara o nó do topo da pilha A
	int	value;

	//Validar se a pilha A esta vazia antes de mover o nó do topo
	if (is_empty(stack_a))
	{
		ft_printf("Pilha A está vazia, não é possível empilhar para B\n");
		return;
	}
	// Armazenar o valor do nó movido
	value = pop(stack_a);
	// Adicionar o nó movido no topo da pilha B
	push(stack_b, value);
	//Imprimir a operaçao
	ft_printf("Op:[pb]\n");
}
