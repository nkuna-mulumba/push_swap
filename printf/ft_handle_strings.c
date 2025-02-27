/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:41:16 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/30 18:24:39 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_strings(const char *str, int *count)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}
