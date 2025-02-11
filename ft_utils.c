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

	// Verifica se a string contém apenas dígitos válidos
	if (!ft_digit_valid(str))
	{
		ft_printf("Erro: Argumento '%s' contém caracteres inválidos\n", str);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); // Encerra o programa se a string não for válida
	}
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
	t_node	*current; //Declarar variavel que vai receber ńo do topo da pilha
	
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
