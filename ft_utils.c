/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 17:30:20 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-04 17:30:20 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Função para acessar (peek) o valor no topo da pilha
    Retorna o valor do nó no topo da pilha sem removê-lo
*/
//(OBS) Depois ver se é necessario continuar com a funçao (peek)
int	peek(t_stack *stack)
{
	//Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia.\n");
		// Retorna um valor indicador de erro (pode ser ajustado conforme necessário)
		return (-1);
	}
	// Retorna o valor do nó no topo da pilha
	return (stack->top->value);
}

/*
	Função para verificar se a string representa um 
	número válido dentro do intervalo de int e retornar o valor convertido
*/
long	ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	long	num; // Variável para armazenar o número convertido

	// Converte a string para número usando ft_atoi
	num = ft_atol(str);
	// Verifica se o número está dentro dos limites de int
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Erro: Argumento '%s' está fora dos limites de int\n", str);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); // Encerra o programa se o número estiver fora dos limites de int
	}
	//return (num); // Retorna o número convertido se for válido
	return (int)num; // Retorna o número convertido se for válido
}

/*
	Função para verificar se um número já está presente 
	na pilha e gerar mensagem de erro
*/ 
void	check_duplicate(t_stack *stack, int num)
{
	t_node	*current;
	
	 // O nó do topo da pilha é armazenado em 'current'
	current = stack->top;
	// Percorre a pilha até encontrar o final (NULL)
	while (current != NULL)
	{
		// Verifica se o valor do nó atual é igual ao número fornecido
		if (current->value == num)
		{
			ft_printf("Erro: Número duplicado '%d'\n", num);
			exit(1); // Encerra o programa se o número já estiver presente
		}
		current = current->next; //Apontar  para seguinte nó
	}
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
	Função para contar o número de elementos na stack_a
*/
int	stack_size(t_stack *stack)
{
	int	size = 0;
	t_node *current = stack->top;

	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

