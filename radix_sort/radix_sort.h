/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:55:41 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-16 16:55:41 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_SORT_H
# define RADIX_SORT_H

#  include "../push_swap.h"

/*
	Definir uma constante com tamanho fixo, para definir o tamanho máximo dos 
	arrays em tempo de compilação, ou seja, durante a compilação do código pelo 
	compilador C. Isso significa que o espaço de memória é alocado de forma 
	ESTATICA, que não muda durante a execução do programa.
*/
#  ifndef MAX_SIZE //Inicio de tamanho de pilas
#   define MAX_SIZE 1024 //Quantidade maximo de elementos a armazenar na pilha
#  endif //fim de tamanho de pilas

//################ INICIO DE RADIX SORT ################
/*
	Implementaçao de algoritimo de ordeçao Radix Sort
	Adaptado para numeros negativos e positivos
*/
/*
 A estrutura Stacks é usada para armazenar separadamente 
 os números positivos e negativos da pilha original.
 Também armazena os índices do topo dessas duas pilhas.
*/



typedef struct
{
	int	pos_stack[MAX_SIZE]; //Usando MAX_SIZE para definir o tamanho maximo
	int	neg_stack[MAX_SIZE]; //Armazena os números negativos da pilha original (como valores absolutos inicialmente).
	int	pos_top; // Índice do topo da pilha de positivos
	int	neg_top; // Índice do topo da pilha de negativos
} Stacks;

//Função para separar números positivos e negativos
void	separate_number(int	stack[], int top, Stacks *stacks);

//Função para obter o maior número no array
int		get_max(Stacks *stacks);

//Função auxiliar de (radix_sort) para contar digitos na posiçao exp:
void	count_digits(int stack[], int top, int exp, int count[]);

//Função auxiliar de (radix_sort) para ajustar valor acumulados de digitos na posiçao de exp:
void	adjust_positions(int stack[], int output[], int top, int exp, int count[]);

//Função principal do Radix Sort para ordenar numeros positivos e absoluto(negativo convertido)
void	radix_sort(Stacks *stacks, int stack[], int n);

//Função para ordenar números positivos
void	sort_positives(Stacks *stacks);

//Função para ordenar números negativos
void	sort_negatives(Stacks *stacks);

//Função combinada para ordenar e combinar resultados
void	combined_radix_sort(int stack[], int n);
//######### FIM DE RADIX SORT#########
#endif