/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:06:37 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/27 22:16:08 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_hex_upper(unsigned int num, int *count)
{
	char	*buffer;
	int		length;

	buffer = ft_num_to_hex(num, "0123456789ABCDEF");
	if (buffer)
	{
		length = ft_strlen(buffer);
		write(1, buffer, length);
		*count += length;
		free(buffer);
	}
}
