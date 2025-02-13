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
	Função auxiliar para verificar se a pilha está ordenada	
*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (is_empty(stack) || stack->top == NULL)// Pilha não existe ou não possui pelo menos dois valores
		return (1);
	current = stack->top;// Aponta para o topo da pilha
	while (current->next != NULL)// Para no último elemento
	{
		if (current->value > current->next->value)// Verifica se o valor atual é maior que o próximo
			return (0);// Pilha não está ordenada
		current = current->next;// Avança para o próximo elemento
	}
	return (1);// Pilha está ordenada
}

//com dois valores:
// 1 2 Ordenada
// -1 1 Ordenada
// -2 -1 Ordenada
// -2 2  Ordenada
// 2 1 SA
// -1 -2 SA

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

//TESTE COM 3 VALORES:
//1 2 3 NEHUMA OPERAÇAO DEVE SER FEITA
//1 3 2 SA 3 1 2 rra 1 2 3 (2)suficiente
//2 3 1 RRA 1 2 3 (1) suficiente
//2 1 3 SA 1 2 3 (1) suficiente
//3 1 2 RA 1 2 3 (1) suficiente
//3 2 1 SA 2 3 1 RRA 1 2 3 (2) suficiente
//1 -1 0 RA -1 0 1 (1) suficiente


//Testes adicional:
//1 1 2
//-1 -1 -2
//2 2 2

//Misto positivo e negativo:
//1 -2 3 SA 
//-1 2 -3 RA
//2 -1 1 RA

//Minimo e maximo INT :
//-2147483648 2147483647 0 SA RA
//2147483647 -2147483648 1 RA
//-2147483647 2147483646 0 RA


//invalidos:
//1 2 a
//-1 b 3
//1.5 2 3


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

// ra(stack_a, 1); //Ordenar o menor elemento na posição correta
// display(stack_a);


// 1 2 3 4 Ordenada
// 1 2 4 3 ## 4 pb 2 4 3 sort_three sa 4 2 3 ra 2 3 4 pa 1 2 3 4 (4)
// 1 4 3 2 ## 4 
// 1 4 2 3 ## 3
// 1 3 2 4 ## 3
// 1 3 4 2 ## 3
// 1 4 3 2 ## 4
// 2 3 1 4 ## 5
// 2 3 4 1 ## 1
// 2 4 3 1 ## 5
// 2 4 1 3 ## 5
// 2 1 3 4 ## 4
// 2 1 4 3 ## 5
// 3 1 2 4 ## 5
// 3 1 4 2 ## 4
// 3 4 1 2 ## 2
// 3 4 2 1 ## 4
// 3 2 1 4 ## 6
// 3 2 4 1 ## 4
// 4 1 3 2 ## 4
// 4 1 2 3 ## 1
// 4 3 1 2 ## 6
// 4 3 2 1 ## 5
// 4 2 1 3 ## 5
// 4 2 3 1 ## 4

// -1 2 -2 1 ## 5
// -1 2 1 -2 ## 5
// -1 -2 2 1 ## 5
// -1 -2 1 2 ## 4
// 1 -1 2 -2 ## 4
// 1 -1 -2 2 ## 6
// 1 -2 -1 2 ## 5
// 1 -2 2 -1 ## 4
// 1 2 -1 -2 ## 4
// 1 2 -2 -1 ## 4
// 2 -1 -2 1 ## 5
// 2 -1 1 -2 ## 4
// 2 -2 -1 1 ## 1
// 2 -2 1 -1 ## 4
// 2 1 -2 -1 ## 6
// 2 1 -1 -2 ## 5
// -2 -1 2 1 ## 4
// -2 -1 1 2 ## Pilha ordenada
// -2 2 -1 1 ## 3
// -2 2 1 -1 ## 4
// -2 1 -1 2 ## 3
// -2 1 2 -1 ## 3

/*
    Função para ordenar cinco valores na stack_a 
*/
void	sort_five(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	min_pos;

	while (count++ < 2)
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
	sort_three(stack_a);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b);
}

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
