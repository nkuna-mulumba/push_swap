/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:48 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/28 19:09:53 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse_str(char *buffer, int length)
{
	int		j;
	char	temp;

	j = 0;
	while (j < length / 2)
	{
		temp = buffer[j];
		buffer[j] = buffer[length - j - 1];
		buffer[length - j - 1] = temp;
		j++;
	}
}
