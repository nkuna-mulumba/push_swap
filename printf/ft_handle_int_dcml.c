/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_dcml.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:22 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 20:47:05 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_int_dcml(int num, int *count)
{
	char	*buffer;
	int		length;

	buffer = ft_itoa(num);
	if (buffer)
	{
		length = ft_strlen(buffer);
		write(1, buffer, length);
		*count += length;
		free(buffer);
	}
}
