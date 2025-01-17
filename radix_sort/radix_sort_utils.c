/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 17:00:46 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-16 17:00:46 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

/*
*Objetivo: Separar números positivos e negativos em duas pilhas diferentes.
*stacks->pos_top = -1; stacks->neg_top = -1; Inicializa os índices do topo das pilhas.
*while (i <= top): Loop através de todos os elementos da pilha.
  - if (stack[i] >= 0): Adiciona números positivos à pilha pos_stack.
  - else: Adiciona números negativos (como valores absolutos) à pilha neg_stack.
*/
void	separate_number(int	stack[], int top, Stacks *stacks)
{
	int	i;

/*
	Inicializamos pos_top e neg_top com -1 para indicar que as pilhas 
	estão inicialmente vazias. Permitindo incrementar antes de acessar a posição, 
	garantindo que adicionamos o primeiro elemento na posição 0.
*/
	stacks->pos_top = -1; //Inicializada com valor negativo para indicar que a pila esta vazia
	stacks->neg_top = -1;
	i = 0;
	while (i <= top)
	{
		if (stack[i] >= 0)
		{
			stacks->pos_stack[++(stacks->pos_top)] = stack[i];
		}
		else
		{
			//Converte o valor para seu valor absoluto, facilitando a ordenação com Radix Sort.
			stacks->neg_stack[++(stacks->neg_top)] = -stack[i];
		}
		i++;
	}
}
//Obter maior elemento da pila e identificar sua magnitude.
/*
* Objetivo: Encontrar o maior valor nas pilhas.
* int max = stack[0]: Inicializa max com o primeiro elemento da pilha.
* while (i <= top): Loop através de todos os elementos da pilha.
  * if (stack[i] > max): Atualiza max se encontrar um elemento maior.
*return max: Retorna o maior valor encontrado.
*/
int	get_max(Stacks *stacks)
{
	int	max;
	int	i;

	if (stacks->pos_top >= 0)
	{
		max = stacks->pos_stack[0];
		i = 1;
		while (i <= stacks->pos_top)
		{
			if (stacks->pos_stack[i] > max)
			{
				max = stacks->pos_stack[i];
			}
			i++;
		}
	}
	else if (stacks->neg_top >= 0)
	{
		max = stacks->neg_stack[0];
		i = 1;
		while (i <= stacks->neg_top)
		{
			if (stacks->neg_stack[i] > max)
			{
				max = stacks->neg_stack[i];
			}
			i++;
		}
	}
	else
	{
		max = 0;
	}
	return max;
}

//Contar digitos com posiçao de expoente iniciado com 1 , 10 , 100
/*
	*Objetivo: Contar os dígitos isolada na posição exp.
	*int i = 0; while (i <= top): Loop que percorre todos os elementos do array até o índice top.
	*count[(stack[i] / exp) % 10]++: Conta a ocorrência de cada dígito na posição exp.
*/
void 	count_digits(int stack[], int top, int exp, int count[])
{
	int	i;

	i = 0;
	while (i <= top)
	{
		/*
			Encontrar digito isolada de cada elemento iniciando da base
			da pila na posiçao decimal especificada pelo valor de exp
		*/
		count[stack[i] / exp % 10]++; 
		i++;
	}
}

/*
	*Objetivo: Ajustar as posições acumuladas e organizar os números no array output.
	*while (i < 10): Ajusta as posições acumuladas.
	  - count[i] += count[i - 1]: Atualiza count com posições acumuladas.
	*while (i >= 0): Coloca os números na posição correta em output.
	  - int digit = (stack[i] / exp) % 10: Calcula o dígito relevante.
	  - output[count[digit] - 1] = stack[i]: Coloca o número na posição correta em output.
	  - count[digit]--: Decrementa a contagem.
	*while (i <= top): Copia os números ordenados de output para stack.
*/
// PARAMETRO:
// int stack[]: Array de números a serem ajustados.
// int output[]: Array temporário para armazenar o resultado da ordenação parcial.
// int top: Índice do último elemento do array.
// int exp: A posição decimal atual (unidades, dezenas, centenas, etc.).
// int count[]: Array de contagem que armazena a ocorrência dos dígitos.
void	adjust_positions(int stack[], int output[], int top, int exp, int count[])
{
	int	i;
	int	digit;

	/*
		O primeiro loop ajusta indice de count_digits, sumando valor 
		da 2ª posiçao de indice de count_digits ao valor da 1ª posiçao.
	*/
	i = 0;
	while (i < 9)
	{
		// Indice actualizado e ajustada com valores acumuladas
		count[i + 1] += count[i];
		i++;
	}
	
	i = top;
	while (i >= 0)
	{
		// Isolar o dígito de cada elemento começando de top.
		digit = (stack[i] / exp) % 10; 
		// Ajustar índice com count, subtrair 1, colocar no output
		output[count[digit] - 1] = stack[i]; 
		count[digit]--;
		i--;
	}
	//stack = {170, 75, 802, 24, 66}
	//count = {1, 1, 2, 2, 3, 4, 5, 5, 5, 5} , 170 , 802 , 75 , 24, 66
	//count = {1, 0, 1, 0, 1, 1, 1, 0, 0, 0}

	/*
		Copiar os elementos do array output de volta para o array stack, 
		atualizando stack com os valores ordenados.
	*/
	i = 0;
	while (i <= top)
	{
		stack[i] = output[i];
		i++;
	}
}