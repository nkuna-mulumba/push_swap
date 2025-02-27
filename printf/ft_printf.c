/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 13:15:29 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/30 18:24:35 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(va_list args, const char format, int *count)
{
	if (format == 'c')
		ft_handle_char(va_arg(args, int), count);
	else if (format == 's')
		ft_handle_strings(va_arg(args, const char *), count);
	else if (format == 'p')
		ft_handle_void_pointer(va_arg(args, void *), count);
	else if (format == 'd' || format == 'i')
		ft_handle_int_dcml(va_arg(args, int), count);
	else if (format == 'u')
		ft_handle_unsigned_int(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_handle_hex_lower(va_arg(args, unsigned int), count);
	else if (format == 'X')
		ft_handle_hex_upper(va_arg(args, unsigned int), count);
	else if (format == '%')
		ft_handle_char('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_format(args, *format, &count);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{

	//TESTAR CARACTERES E STRINGS
	ft_printf("Caracteres: %c\n", 'A');
	ft_printf("String: %s\n", "Helo, world");

	//TESTAR INTEIROS
	ft_printf("Numero inteiro: %d\n", 42);
	ft_printf("Nmero negativo: %i\n", -42);

	//TESTAR INTEIROS SEM SINAL
	ft_printf("Numero sem sinal: %u\n", 3000000000u);

	//TESTAR NUMEROS HEXADECIMAIS
	ft_printf("Hexadecimal minusculo: %x\n", 255);
	ft_printf("Hexadecimal maisculo: %X\n", 255);

	//TESTAR PONTEIROS
	int	var = 42;
	int	*ptr = &var;
	ft_printf("Ponteiro: %p\n", (void*)ptr);

	//TESTAR SIMBOLO DE PORCENTAGEM
	ft_printf("Porcentagem: %%\n");


	return 0;
}
*/
