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
	Função para validar os valores e empilhá-los
*/
void	validate_and_push(char **args, t_stack *temp_stack, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	num;

	i = 0;
	while (args[i] != NULL) // Validar números
	{
		if (!ft_digit_valid(args[i]))
		{
			ft_printf("Erro: Caractere '%s' é um dígito inválido\n", args[i]);
			//ft_freememoria(args);
			free_stack(stack_a);
			free_stack(stack_b);
			return;
		}
		num = ft_is_valid_number(args[i], stack_a, stack_b);

		// Verificar duplicatas antes de empilhar
		check_duplicate(temp_stack, num);
		// Armazenar temporariamente os valores na ordem correta
		push(temp_stack, num);
		i++;
	}
	//ft_freememoria(args);
}

/*
	Função para dividir a string em substrings e 
	validar os valores
*/
void	process_arguments(char *arg, t_stack *temp_stack, t_stack *stack_a, t_stack *stack_b)
{
	char	**args;

	// Divide cada argumento em substrings
	args = ft_split(arg, ' ');
	if (!args || args[0] == NULL) // Verifica se a divisão falhou
	{
		ft_printf("Erro: Delimitador '%s' sem dígitos\n", arg);
		ft_freememoria(args);
		free_stack(stack_a);
		free_stack(stack_b);
		return;
	}
	// Validar e empilhar números
	validate_and_push(args, temp_stack, stack_a, stack_b);
	ft_freememoria(args);
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

