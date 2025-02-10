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
	t_node *current;

	if (is_empty(stack) || stack->top == NULL)// Pilha não existe ou não possui pelo menos dois valores
		return 1;
	current = stack->top; // Aponta para o topo da pilha
	while (current->next != NULL)// Para no último elemento
	{
		if (current->value > current->next->value) // Verifica se o valor atual é maior que o próximo
			return 0; // Pilha não está ordenada
		current = current->next;// Avança para o próximo elemento
    }
    return 1; // Pilha está ordenada
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
	int a;
	int b;

	a = stack->top->value; //Aponta para o topo da pilha
	b = stack->top->next->value; //Aponta para o segundo elemento da pilha
	if (a > b) //Verifica se o primeiro elemento é maior que o segundo
	{
		sa(stack); //Chama a função swap
		display(stack); //Exibe a pilha
		return;
	}
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

	a = stack->top->value; // Aponta para o topo da pilha
	b = stack->top->next->value; // Aponta para o segundo elemento da pilha
	c = stack->top->next->next->value; // Aponta para o terceiro elemento da pilha

	// Caso já ordenado: 1 2 3 (0)
	if (a < b && b < c) // 1 < 2 && 2 < 3
		return;
    // Caso 3 2 1: (2) 
	if (a > b && b > c) // 3 > 2 && 2 > 1
	{
		sa(stack); // Troca os dois primeiros
		display(stack);
		rra(stack, 1); // Rotaciona para ajustar a ordem
		display(stack);
	}
	// Caso 2 3 1: (1)
	else if (a < b && b > c && a > c) // 2 < 3 && 3 > 1 && 2 > 1
	{
		rra(stack, 1); // Rotaciona para ajustar a ordem
		display(stack);
	}
	// Caso 2 1 3: (1)
	else if (a > b && b < c && a < c) // 2 > 1 && 1 < 3 && 2 < 3 
	{
		sa(stack); // Troca os dois primeiros
		display(stack);
	}
	// Caso 1 3 2: (2)
	else if (a < b && b > c && a < c) 
	{
		sa(stack); // Troca os dois primeiros
		display(stack);
		ra(stack, 1); // Rotaciona para ajustar a ordem
		display(stack);
	}
	// Caso 3 1 2: (1)
	else if (a > b && b < c && a > c) // 3 > 1 && 1 < 2 && 3 > 2 
	{
		ra(stack, 1); // Rotaciona para ajustar a ordem
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
			min_pos = i;//Atualiza a posição do mínimo 1
		}
		currente = currente->next;//Avança para o próximo elemento da pilha
		i++;//Incrementa o índice
	}
	return (min_pos);//Retorna a posição do menor valor (3)
}


/*
	Funçao para ordenara quatro valores na stack_a
*/
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	// Encontra a posição do menor valor na pilha A
    min_pos = find_min_position(stack_a);

	// Move o menor elemento para o topo de A
	if (min_pos == 1)// Posição 1: Faz 1 rotação para cima (RA)
	{
		ra(stack_a, 1);
		display(stack_a);
	}
	else if (min_pos == 2)// Posição 2: Faz 2 rotações inversas (RRA)
	{
		ra(stack_a, 1);
		display(stack_a);
		ra(stack_a, 1);
		display(stack_a);
	}
	else if (min_pos == 3) // Posição 3: Faz 1 rotação inversa (RRA)
	{
		rra(stack_a, 1);
		display(stack_a);
	}
	// Verifica se a pilha está ordenada após mover o menor elemento para o topo
	if (!is_sorted(stack_a))
	{
		// Move o menor elemento para B (PB)
		pb(stack_b, stack_a);
		display(stack_a);
		ft_printf("Pilha B:\n");
		display(stack_b);

		// Ordena os 3 elementos restantes em A
		sort_three(stack_a);

		// Traz o elemento de volta para A (PA)
		pa(stack_a, stack_b);
		display(stack_a);
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
// 1 -1 2 -2 ## 4
// 1 -1 -2 2 ## 6
// 1 2 -1 -2 ## 4
// 1 2 -2 -1 ## 4
// 1 -2 2 -1 ## 4
// 1 -2 -1 2 ## 5

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
