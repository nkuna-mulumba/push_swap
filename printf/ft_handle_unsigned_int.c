/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:52:11 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 19:00:30 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_unsigned_int(unsigned int num, int *count)
{
	char	*buffer;
	int		length;

	buffer = ft_unsigned_int_to_str(num);
	if (buffer)
	{
		length = ft_strlen(buffer);
		write(1, buffer, length);
		*count += length;
		free(buffer);
	}
}
