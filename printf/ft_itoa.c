/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:12:16 by jcongolo          #+#    #+#             */
/*   Updated: 2024/10/27 17:24:07 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nbr(int n)
{
	int	length_nbr;

	length_nbr = 0;
	if (n <= 0)
		length_nbr = 1;
	else
		length_nbr = 0;
	while (n != 0)
	{
		n = n / 10;
		length_nbr++;
	}
	return (length_nbr);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*int_to_str;
	long	num;

	length = ft_count_nbr(n);
	int_to_str = malloc((length + 1) * sizeof(char));
	if (!int_to_str)
		return (NULL);
	int_to_str[length] = '\0';
	num = n;
	if (num == 0)
		int_to_str[0] = '0';
	if (num < 0)
	{
		int_to_str[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		int_to_str[--length] = (num % 10) + '0';
		num = num / 10;
	}
	return (int_to_str);
}

/*
int main() {
    int number = -2147483648;
    char *int_to_str = ft_itoa(number);

    if (!int_to_str) {
        return (1); // Retorna 1 em caso de falha na alocação de memória
    } else {
        printf("%s\n", int_to_str); // Imprime o resultado
        free(int_to_str); // Libera a memória alocada
    }
    return 0; // Retorna 0 em caso de sucesso
}
*/
