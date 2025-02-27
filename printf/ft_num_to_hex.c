/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:58:11 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 20:53:39 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_num_to_hex(unsigned long num, const char *hex_digits)
{
	char	*buffer;
	int		i;

	buffer = malloc(17 * sizeof(char));
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = hex_digits[num % 16];
			num = num / 16;
		}
	}
	buffer[i] = '\0';
	ft_reverse_str(buffer, i);
	return (buffer);
}
