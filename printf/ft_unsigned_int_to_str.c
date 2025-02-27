/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:55 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 20:41:27 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_int_to_str(unsigned int num)
{
	char	*buffer;
	int		i;

	buffer = malloc(12 * sizeof(char));
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num = num / 10;
		}
	}
	buffer[i] = '\0';
	ft_reverse_str(buffer, i);
	return (buffer);
}
