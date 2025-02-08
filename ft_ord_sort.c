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

//com dois valores
// 1 2 Ordenada
// -1 1 ordenada
// -2 -1 ordenada
// -2 2  ordenada
// 2 1 SA
// -1 -2 SA

/*
	Funçao para ordenara dois valor no stack_a
*/
void	sort_two(t_stack *stack)
{
	int a;
	int b;

	a = stack->top->value;
	b = stack->top->next->value;
	if (a > b)
	{
		return;
		display(stack);
	}
	else if (a < b)
	{
		sa(stack);
		display(stack);
	}
}
//1 2 3 NEHUMA OPERAÇAO DEVE SER FEITA
//1 3 2 SA 1 2 3 (1)suficiente
//2 3 1 RA 1 2 3 (1) suficiente
//2 1 3 SA 2 3 1 -> RA 1 2 3 (2) suficiente
//3 1 2 RRA 1 3 2 (1) suficiente
//3 2 1 RA 1 3 2 SA 1 2 3 (2) suficiente
//1 -1 0 RA -1 1 0 SA -1 0 1


//Testes adicional
//1 1 2
//-1 -1 -2
//2 2 2

//Misto positivo e negativo
//1 -2 3 SA RA
//-1 2 -3 RA
//2 -1 1 RRA

//Minimo e maximo INT
//-2147483648 2147483647 0 SA
//2147483647 -2147483648 1 RRA
//-2147483647 2147483646 0 SA


//invalidos
//1 2 a
//-1 b 3
//1.5 2 3


/*
	Funçao para ordenara tres valor no stack_a
*/
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	
	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	// Caso já ordenado: 1 2 3 (nenhuma operação necessária)
	if (a > b && a > c && b > c) // 3 > 2 && 3 > 1 && 2 > 1
		return;
	//-2 -3 -1 SA -2 -1 -3 RA -3 -2 -1 (2) suficiente #####
	else if (a > b && a > c && c > b)
	{
		sa(stack);
		display(stack);
		ra(stack, 1);
		display(stack);
	}
	//-3 -1 -2 
	// 1 3 2 SA 1 2 3 (1)suficiente
	else if (a < b && a > c && b > c) // 2 < 3 && 2 > 1 && 3 > 1
	{
		sa(stack);
		display(stack);
	}
	//2 3 1 RA 1 2 3 (1) suficiente
	else if (a < b && a < c && b > c) // 1 < 3 && 1 < 2 && 3 > 2
	{
		ra(stack, 1);
		display(stack);
	}
	//2 1 3 RRA 1 3 2 -> SA 1 2 3 (2) suficiente
	else if (a > b && a > c && b < c) // 3 > 1 && 3 > 2 && 1 < 2 #####
	{
		rra(stack, 1);
		display(stack);
		sa(stack);
		display(stack);
	}
	//3 1 2 RRA 1 3 2 (1) suficiente
	else if (a > b && a < c && b < c) // 2 > 1 && 2 < 3 && 1 < 3
	{
		rra(stack, 1);
		display(stack);
	}
	//-1 -2 -3  RA -3 -1 -2 -> SA -3 -2 -1 (2) suficiente
	//3 2 1 RA 1 3 2 SA 1 2 3 (2) suficiente
	else if (a < b && a < c && b < c) // 1 < 2 && 1 < 3 && 2 < 3
	{
		ra(stack, 1);
		display(stack);
		sa(stack);
		display(stack);
	}
}

/*
	Função auxiliar de (sort_four) para 
    encontrar o índice do menor valor na stack_a
*/
int	find_min_position(t_stack *stack)
{
	t_node	*currente;
	int		min;
	int		min_pos;
	int		i;

	currente = stack->top; //apunta ao topo da pilha
	min = currente->value; //Armazena o valor do topo como o mínimo inicial
	min_pos = 0; //Inicializa a posição do mínimo
	i = 0; //Inicializa o índice
	while (currente)// Percorre a pilha até o final
	{
		if (currente->value < min)//Verifica se o valor atual é menor que o mínimo
		{
			min = currente->value;//Atualiza o mínimo
			min_pos = i;//Atualiza a posição do mínimo
		}
		currente = currente->next;//Avança para o próximo elemento da pilha
		i++;//Incrementa o índice 1, 2, 3
	}
	return (min_pos);//Retorna a posição do menor valor (3)
}

/*
// Função auxiliar para verificar se a pilha está ordenada
int	is_sorted(t_stack *stack)
{
	t_node *current;
	int	i;

	current = stack->top;
	if (current->value > current->next->value // 4 > 3 
		&& current->value > current->next->next->value // 4 > 2
		&& current->value > current->next->next->next->value // 4 > 1
		&& current->next->value > current->next->next->value // 3 > 2
		&& current ->next->value > current->next->next->next->value // 3 > 1
		&& current->next->next->value > current->next->next->next->value) // 2 > 1
	{
		i = 1; // A pilha está ordenada
	}
	else
	{
		i = 0; // A pilha não está ordenada
	}
	return (i);
}
*/

int is_sorted(t_stack *stack) {
    if (!stack || !stack->top) // Pilha não existe ou está vazia
        return 1;

    t_node *current = stack->top;
    while (current->next != NULL) { // Pare no último elemento
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

/*
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
    int	min_pos;
	
	int	sim = is_sorted(stack_a);
	printf("\nVALOR: ##(%d)##\n", sim);

	if (is_sorted(stack_a))//Verifica se a pilha está ordenada
		return;// Se já estiver ordenada, retorne sem fazer nada

	min_pos = find_min_position(stack_a); // Encontra a posição do menor elemento
	printf("POSITION %d\n", min_pos);
    // Mover o menor elemento para stack_b
	if (min_pos == 0)
	{
		ra(stack_a, 1);
		display(stack_a);
		exit (1);
	}
	else if (min_pos == 1)//Se o índice do valor mínimo é igual a 1
	{
		ra(stack_a, 1);
		display(stack_a);
	}
	else if (min_pos == 2)//Se o índice do valor mínimo é igual a 2
	{
		ra(stack_a, 1);
		display(stack_a);
		ra(stack_a, 1);
		display(stack_a);
	}
	else if (min_pos == 3)//Se o índice do valor mínimo é igual a 3
	{
		rra(stack_a, 1);
		display(stack_a);
	}
	pb(stack_b, stack_a);//Move o menor elemento para stack_b
	display(stack_a);
	display(stack_b);
	sort_three(stack_a);//Chama a função para ordenar os três elementos restantes em stack_a
	display(stack_a);
	pa(stack_a, stack_b);//Move o menor elemento de volta para stack_a
	ra(stack_a, 1); //Ordenar o menor elemento na posição correta
	display(stack_a);
}
// 1 2 3 4 Ordenada
// 1 2 4 3 ## 5 ra 3 1 2 4 pb 3 1 2 rra 1 2 3 pa 1 2 3 4 (4)
// 1 4 3 2 ## 6 rra 4 3 2 1 rra 3 2 1 4 pb 3 2 1 ra 1 3 2 sa 1 2 3 pa 1 2 3 4 (6)
// 1 4 2 3 ## 5 rra 4 2 3 1 rra 2 3 1 4 pb 2 3 1 ra 1 2 3 pa 1 2 3 4 (5)
// 1 3 2 4 ## 6 pb 1 3 2 sa 1 2 3 pa 1 2 3 4 (3)
// 1 3 4 2 ## 5 
// 1 4 3 2 ## 6
// 2 3 1 4 ## 5
// 2 3 4 1 ## 3  ra 1 2 3 4(1)
// 2 4 3 1 ## 4 
// 2 4 1 3 ## 6
// 2 1 3 4 ## 6
// 2 1 4 3 ## 7  ra 3 2 1 4 pb 3 2 1 ra 1 3 2 sa 1 2 3 pa 1 2 3 4 (5)
// 3 1 2 4 ## 6
// 3 1 4 2 ## 6
// 3 4 1 2 ## 4
// 3 4 2 1 ## 4
// 3 2 1 4 ## 6
// 3 2 4 1 ## 5
// 4 1 3 2 ## 7
// 4 1 2 3 ## 5
// 4 3 1 2 ## 5
// 4 3 2 1 ## 5
// 4 2 1 3 ## 5
// 4 2 3 1 ## 4

// -1 2 -2 1 ## 6
// -1 2 1 -2 ## 4
// -1 -2 2 1 ## 7  ra 1 -1 -2 2 pb 1 -1 -2 ra -2 1 -1 sa -2 -1 1 pa -2 -1 1 2 (5)
// -1 -2 1 2 ## 5
// 2 -1 -2 1 ## 5
// 2 -1 1 -2 ## 4
// 2 -2 -1 1 ## 5
// 2 -2 1 -1 ## 7
// 2 1 -2 -1 ## 5
// 2 1 -1 -2 ## 5
// -2 -1 2 1 ## 5
// -2 -1 1 2 ## Pilha ordenada
// -2 2 -1 1 ## 6
// -2 2 1 -1 ## 6
// -2 1 -1 2 ## 6
// -2 1 2 -1 ## 5
// 1 -1 2 -2 ## 5
// 1 -1 -2 2 ## 6
// 1 2 -1 -2 ## 4
// 1 2 -2 -1 ## 4
// 1 -2 2 -1 ## 6
// 1 -2 -1 2 ## 6

