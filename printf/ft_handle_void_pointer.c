/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_void_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:56:33 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 18:42:28 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_void_pointer(void *ptr, int *count)
{
	char	*buffer;
	int		length;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write(1, "0x", 2);
	*count += 2;
	buffer = ft_num_to_hex((unsigned long)ptr, "0123456789abcdef");
	if (buffer)
	{
		length = ft_strlen(buffer);
		write(1, buffer, length);
		*count += length;
		free(buffer);
	}
}
