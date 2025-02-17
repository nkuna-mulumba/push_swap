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

/*
	Funçao para ordenara dois valor no stack_a
*/
void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	// Verifica se a pilha tem pelo menos dois elementos
	if (!stack || !stack->top || !stack->top->next)
		return;// Retorna sem fazer nada se não houver pelo menos 2 elementos
	a = stack->top->value; //Aponta para o topo da pilha
	b = stack->top->next->value;//Aponta para o segundo elemento da pilha
	if (a > b)//Verifica se o primeiro elemento é maior que o segundo
		sa(stack);//Chama a função swap
}

/*
	Função para ordenar três valores na stack_a
*/
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->top || !stack->top->next || !stack->top->next->next)
		return ;//Retorna se a pilha não tiver pelo menos 3 elementos
	a = stack->top->value;// Aponta para o topo da pilha
	b = stack->top->next->value;// Aponta para o segundo elemento da pilha
	c = stack->top->next->next->value;// Aponta para o terceiro elemento da pilha
	if (a < b && b < c)// 1 < 2 && 2 < 3
		return ;
	if (a > b && b > c)// 3 > 2 && 2 > 1
	{
		(sa(stack), rra(stack, 1));
	}
	else if (a < b && b > c && a > c) // 2 < 3 && 3 > 1 && 2 > 1
		rra(stack, 1);
	else if (a > b && b < c && a < c)// 2 > 1 && 1 < 3 && 2 < 3 
		sa(stack);
	else if (a < b && b > c && a < c) 
	{
		(sa(stack), ra(stack, 1));
	}
	else if (a > b && b < c && a > c)// 3 > 1 && 1 < 2 && 3 > 2 
		ra(stack, 1);
}

/*
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);//Encontra a posição do menor valor na pilha A
	if (min_pos == 1)
		ra(stack_a, 1);
	else if (min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (min_pos == 3)
		rra(stack_a, 1);
	if (!is_sorted(stack_a))
	{
		pb(stack_b, stack_a);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

/*
    Função para ordenar cinco valores na stack_a 
*/
void	sort_five(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	min_pos;

	while (count++ < 1)
	{
		min_pos = find_min_position(stack_a);//Posiçao menor da pilgha A
		if (min_pos == 1)
			ra(stack_a, 1);
		else if (min_pos == 2)
		{
			ra(stack_a, 1);
			ra(stack_a, 1);
		}
		else if (min_pos == 3)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		else if (min_pos == 4)
			rra(stack_a, 1);
		if (!is_sorted(stack_a))
			pb(stack_b, stack_a);
	}
	sort_four(stack_a, stack_b);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b);
}

/*
	Função para ordenar um grande número de elementos na stack_a 
	utilizando a stack_b como pilha auxiliar.
	Esta função utiliza uma combinação de divisão e conquista e funções 
	auxiliares para garantir a ordenação eficiente dos elementos.
	* stack_a: Pilha principal que contém os elementos a serem ordenados.
	* stack_b: Pilha auxiliar usada durante o processo de ordenação.
	* total_elements: Número total de elementos na stack_a.
*/
void	sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements)
{
	// Mover menores valores para a pilha b
	move_to_stack_b(stack_a, stack_b, &total_elements);
	// Ordenação final e mesclagem
	finalize_sort(stack_a, stack_b, total_elements);
}





// 1 5 4 3 2
// 4 2 5 1 3
//ELIMINAR 4 linhas desnecessarias
//teste 5:
// 2 3 4 5 1 ## (1)rra 1 2 3 4 5
// 2 3 4 1 5 ## (5)rra 5 2 3 4 1 rra 1 5 2 3 4 pb 5 2 3 4 ra 2 3 4 5 pa 12345
// 2 3 1 4 5 ## (6)ra 3 1 4 5 2 ra 1 4 5 2 3 pb 4 5 2 3 ra 5 2 3 4 ra 2 3 4 5 pa 1 2 3 4 5
// 2 1 3 4 5 ## (4)ra 1 3 4 5 2 pb 3 4 5 2 rra 2 3 4 5 pa 1 2 3 4 5
/*
	Conjuntos de Teste:
	Valores Crescentes:
	1 2 3 4 5 (já ordenado)
	2 3 4 5 1
	Valores Decrescentes:
	5 4 3 2 1
	4 3 2 1 5
	Mistos:
	3 1 4 5 2
	2 5 3 1 4
	1 3 5 2 4
	4 2 5 3 1
	3 5 1 4 2
	Valores Negativos e Positivos:
	-1 2 -2 3 1
	2 -1 3 -2 1
	1 -1 2 -2 3
	-2 -1 1 2 3
	Valores com Zero:
	0 1 2 3 4
	2 1 0 -1 -2
	-1 0 1 -2 2
	1 0 -1 2 -2
	Teste Extra:
	Valores Máximos e Mínimos Inteiros:
	2147483647 -2147483648 0 1 -1
	Teste de Valores Repetidos (Caso de Erro):
	1 2 2 3 4 (deve ser tratado como erro)
	Teste de Valores Aleatórios:
	4 2 5 3 1
	3 4 1 5 2
	5 1 3 4 2
*/
