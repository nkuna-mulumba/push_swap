/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 13:15:16 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/29 14:59:20 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

void	ft_handle_char(char c, int *count);
void	ft_handle_strings(const char *str, int *count);
void	ft_reverse_str(char *buffer, int length);
char	*ft_num_to_hex(unsigned long num, const char *hex_digits);
size_t	ft_strlen(const char *s);
char	*ft_unsigned_int_to_str(unsigned int num);
void	ft_handle_void_pointer(void *ptr, int *count);
char	*ft_itoa(int n);
void	ft_handle_int_dcml(int num, int *count);
void	ft_handle_unsigned_int(unsigned int num, int *count);
void	ft_handle_hex_lower(unsigned int num, int *count);
void	ft_handle_hex_upper(unsigned int num, int *count);
int		ft_printf(const char *format, ...);

#endif