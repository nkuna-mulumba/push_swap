/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 09:45:45 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-17 09:45:45 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//String valido para DIGITOS
int	ft_digit_valid(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

//Validar limites de inteiros
int	ft_valid_integer(const char *str)
{	
	long	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		return (0); // Fora do intervalo permitido
	}
    return (1); // É um inteiro válido
}
//Funçao para CHEQUEAR elementos UNICO
int	ft_check_element(int stack[], int top)
{
	int	i;
	int	j;

	i = 0;
	while (i <= top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (stack[i] == stack[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
//Funçao para validar e converter strings para long
long	ft_validate_and_convert(const char *arg)
{
	if (!ft_digit_valid(arg))
	{
		ft_printf("ERROR 'VALOR CONTÉM CARACTERES NÃO NUMÉRICOS'\n");
		exit (1);
	}
	if (!ft_valid_integer(arg))
	{
		ft_printf("ERROR 'VALOR INVÁLIDO: %s'\n", arg);
		exit (1);
	}
	return (ft_atol(arg));
}