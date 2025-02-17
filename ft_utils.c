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
	Função para contar o número de elementos na stack_a
*/
int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack)// Verifica se a pilha é nula
		return (0);
	current = stack->top;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/*
	Função para verificar se a string representa um 
	número válido dentro do intervalo de int e retornar o valor convertido
*/
long	ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Erro: Argumento '%s' está fora dos limites de int\n", str);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	return (int)num;
}

/*
	Função para verificar se um número já está presente 
	na pilha e gerar mensagem de erro
*/ 
void	check_duplicate(t_stack *stack, int num)
{
	t_node	*current;
	
	current = stack->top;
	while (current != NULL)
	{
		if (current->value == num)
		{
			ft_printf("Erro: Número duplicado '%d'\n", num);
			exit(1);
		}
		current = current->next;
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
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1); // Encerra o programa se um dígito inválido for encontrado
		}
		num = ft_is_valid_number(args[i], stack_a, stack_b);
		// Verificar duplicatas antes de empilhar
		check_duplicate(temp_stack, num);
		// Armazenar temporariamente os valores na ordem correta
		push(temp_stack, num);
		i++;
	}
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
		ft_printf("Error: Delimitador '%s' sem dígitos\n", arg);
		ft_freememoria(args);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); // Encerra o programa se a divisão falhar
	}
	// Validar e empilhar números
	validate_and_push(args, temp_stack, stack_a, stack_b);
	ft_freememoria(args);
}
