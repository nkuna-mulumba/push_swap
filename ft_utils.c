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
long ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	long num;

	(void)stack_a;
	(void)stack_b;
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		// ft_printf("Erroryyyy\n");
		// free_stack(stack_a);
		// free_stack(stack_b);
		// exit(1);
		num = 2147483648;
		return (num);
	}
	return ((int)num);
}

/*
	Função para verificar se um número já está presente
	na pilha e gerar mensagem de erro
*/
int check_duplicate(t_stack *stack, int num)
{
	t_node *current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->value == num)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
	Função para validar os valores e empilhá-los
	void	validate_and_push(char **args, t_stack *temp_stack, t_stack
	*stack_a, t_stack *stack_b)
*/

static void	free_all(char **args, t_stack *tmp, t_stack *a, t_stack *b)
{
	ft_printf("Error\n");
	free_stack(a);
	free_stack(b);
	free_stack(tmp);
	ft_freememoria(args);
	exit(1);
}

void validate_and_push(char **args, t_stack *tmp, t_stack *a, t_stack *b)
{
	int i;
	long num;

	i = 0;
	while (args[i] != NULL)
	{
		if (!ft_digit_valid(args[i]))
			free_all(args, tmp, a, b);
		num = ft_is_valid_number(args[i], a, b);
		if (num == 2147483648)
			free_all(args, tmp, a, b);
		if (!check_duplicate(tmp, num))
			free_all(args, tmp, a, b);
		push(tmp, num);
		i++;
	}
}

/*
	Função para dividir a string em substrings e
	validar os valores
	void	process_arguments(char *arg, t_stack *temp_stack,
	t_stack *stack_a, t_stack *stack_b)
*/
void process_arguments(char *arg, t_stack *tmp, t_stack *a, t_stack *b)
{
	char **args;

	args = ft_split(arg, ' ');
	if (!args || args[0] == NULL)
	{
		ft_printf("Error\n");
		ft_freememoria(args);
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	validate_and_push(args, tmp, a, b);
	ft_freememoria(args);
}

/*
	Funçao para validar argumentos ou parceiro
*/
int validate_args(char **argv, t_stack *tmp, t_stack *a, t_stack *b)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_printf("Error\n");
			free_stack(a);
			free_stack(b);
			free_stack(tmp);
			return (0);
			// exit(1);
		}
		process_arguments(argv[i], tmp, a, b);
		i++;
	}
	return (1);
}
