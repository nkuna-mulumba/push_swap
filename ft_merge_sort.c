/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuna <nkuna@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 09:41:47 by nkuna             #+#    #+#             */
/*   Updated: 2025-02-05 09:41:47 by nkuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Prototipagem da função de combinação (merge)
void merge(int *arr, int left, int mid, int right);




/*
	Passo 1: Função de Divisão do Array com Ponteiros Duplos
	
	left - índice de inteiro representando posição inicial do subarray.
	No início da recursão, left será 0.

	right - índice de inteiro representando a posição final do subarray.
	No início da recursão, right será o índice do último elemento do array.
*/
void	merge_sort(int *arr, int left, int right)
{
	// Verifica se o array contém mais de um elemento
	if (left < right)
	{
		int	mid = left + (right - left) / 2;
		// Chama recursivamente merge_sort para a primeira metade
		merge_sort(arr, left, mid);

		// Chama recursivamente merge_sort para a segunda metade
		merge_sort(arr, mid + 1, right);

		// Chama a função de combinação (merge)
		merge(arr, left, mid, right);
	}
}