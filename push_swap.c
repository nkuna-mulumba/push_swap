/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 13:38:10 by jcongolo          #+#    #+#             */
/*   Updated: 2024-12-27 13:38:10 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funçao para inicializar os Stacks
void	init_stacks(int *top_a, int *top_b)
{
	*top_a = -1;
	*top_b = -1;
}
//Funçao para imprimir a pilha (para depuraçao)
void	print_stack(int stack[], int top)
{
	while (top >= 0)
	{
		printf("%d\n", stack[top]);
		top--;
	}
}
//Funçao para imprimir as pilhas A e B
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b)
{
	//printf("Stack A:\n");
	print_stack(stack_a, top_a);
	//printf("Stack B:\n");
	print_stack(stack_b, top_b);
}

//Função para trocar os dois primeiros elementos da pilha "A"
void	sa(int stack_a[], int top_a)
{
	int	temp;

	if (top_a > 0)
	{
		temp = stack_a[top_a];
		stack_a[top_a] = stack_a[top_a -1];
		stack_a[top_a - 1] = temp;
	}
}
//Função para trocar os dois primeiros elementos da pilha "B"
void	sb(int stack_b[], int top_b)
{
	int	temp;

	if (top_b > 0)
	{
		temp = stack_b[top_b];
		stack_b[top_b] = stack_b[top_b - 1];
		stack_b[top_b - 1] = temp;
	}
}
//Função para trocar simultaneamente os dois primeiros elementos da pilha "A" e "B"
void	ss(int stack_a[], int top_a, int stack_b[], int top_b)
{
	sa(stack_a, top_a);
	sb(stack_b, top_b);
}
// Função para mover o primeiro elemento da pilha "B" para a pilha "A"
void	pa(int stack_a[], int *top_a, int stack_b[], int *top_b)
{
	if (*top_b >= 0)
	{
		stack_a[++(*top_a)] = stack_b[(*top_b)--];
	}
}
//Funçao para mover o primeiro elemento da pilha "A" para a pilha "B"
void	pb(int stack_a[], int *top_a, int stack_b[], int *top_b)
{
	if (*top_a >= 0)
	{
		stack_b[++(*top_b)] = stack_a[(*top_a)--];
	}
}
//Função para rodar todos os elementos da pilha A para cima
void	ra(int stack_a[], int top_a)
{
	int	first;

	if (top_a > 0) // Verifica se há pelo menos dois elementos na pilha
	{
		first = stack_a[top_a]; // Armazena o valor do topo da pilha em "first"
		while (top_a > 0) // Desloca todos os elementos da pilha uma posição para cima
		{
			stack_a[top_a] = stack_a[top_a - 1];
			top_a--;
		}
		stack_a[0] = first;// Coloca o valor original do topo na base da pilha
	}
}
//Função para rodar todos os elementos da pilha "B" para cima
void	rb(int stack_b[], int top_b)
{
	int	first;

	if (top_b > 0)
	{
		first = stack_b[top_b];
		while (top_b > 0)
		{
			stack_b[top_b] = stack_b[top_b - 1];
			top_b--;
		}
		stack_b[0] = first;
	}
}
//Função para rodar os elementos da pilha "A" e "B" para cima simultaneamente
void	rr(int stack_a[], int top_a, int stack_b[], int top_b)
{
	ra(stack_a, top_a);
	rb(stack_b, top_b);
}
// Função para rodar todos os elementos da pilha "A" para baixo
void	rra(int stack_a[], int top_a)
{
	int	last;
	int	i;

	if (top_a > 0) // Verifica se há pelo menos dois elementos na pilha
	{
		last = stack_a[0]; // Armazena o valor da base da pilha em "last"
		i = 0;
		while (i < top_a) // Desloca todos os elementos da pilha uma posição para baixo
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[top_a] = last; // Coloca o valor original da base no topo da pilha
	}
}
// Função para rodar todos os elementos da pilha "B" para baixo
void	rrb(int stack_b[], int top_b)
{
	int	last;
	int	i;

	if (top_b > 0)
	{
		last = stack_b[0];
		i = 0;
		while (i < top_b)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[top_b] = last;
	}
}
//Função para rodar os elementos da pilha "A" e "B" para baixo simultaneamente
void	rrr(int stack_a[], int top_a, int stack_b[], int top_b)
{
	rra(stack_a, top_a);
	rrb(stack_b, top_b);
}





/*
//#########TESTAR A FUNÇAO = ra = PARA RODAR TODOS OS ELEMENTOS DA PILHA "A" PARA CIMA
int main()
{
	int stack_a[MAX_SIZE] = {10,20,30,40,50};
	int	top_a = 4;

	print_stack(stack_a, top_a);
	printf("\n\n\n");

	ra(stack_a, top_a);
	print_stack(stack_a, top_a);
	return (0);
}
*/

/*
//#########TESTAR A FUNÇAO = pa = REMOVER TOP DO "B" PARA TOP "A"
int main()
{
	int	stack_a[MAX_SIZE] = {1,2,3,4,5,6};
	int	stack_b[MAX_SIZE] = {11,12,13,14,15,16};
	int	top_a = 5;
	int	top_b = 5;

	printf("Pilha A e B ANTES de remover valor TOP B:\n");
	print_stacks(stack_a, top_a, stack_b, top_b);

	printf("\n\nPilha A e B DEPOIS de remover TOP B para TOP A:\n");
	pa(stack_a, &top_a, stack_b, &top_b);
	print_stacks(stack_a, top_a, stack_b, top_b);
	return 0;
}
*/

/*
//#########TESTAR A FUNÇAO ss TROCAR SIMULTANEAMENTE DE "A e B"
int main()
{
	int	stack_a[MAX_SIZE] = {1,2,3,4,5,6};
	int	stack_b[MAX_SIZE] = {11,12,13,14,15,16};
	int	top_a = 5;
	int	top_b = 5;

	printf("Pilha A e B ANTE da troca simultânea com ss:\n");
	print_stacks(stack_a, top_a, stack_b, top_b);

	printf("Pilha A e B DEPOIS da troca simultânea com ss:\n");
	ss(stack_a, top_a, stack_b, top_b);
	print_stacks(stack_a, top_a, stack_b, top_b);
	return 0;
}
*/

/*
//#########TESTAR A FUNÇAO sa PARA TROCAR OS 2 PRIMEIROS ELEMENTOS DA PILHA
int main()
{
	int	stack_a[MAX_SIZE] = {1,2,3,4,5,6};
	int	top_a = 5;

	printf("Pilha A antes da troca:\n");
	print_stack(stack_a, top_a);

	printf("Pilha A depois da troca:\n");
	sa(stack_a, top_a);
	print_stack(stack_a, top_a);

	return (0);
}
*/

/*
//#########TESTAR A FUNÇAO print_stacks "A e B"
int main()
{
	int	stack_a[MAX_SIZE] = {1,2,3,4,5,6};
	int	stack_b[MAX_SIZE] = {11,12,13,14,15,16};
	int	top_a = 5;
	int	top_b = 5;

	print_stacks(stack_a, top_a, stack_b, top_b);
	
	return 0;
}
*/

/*
//#########TESTAR A FUNÇAO print_stack
int main()
{
	int	stack_a[MAX_SIZE] = {1,2,3,4,5,6};
	int	top_a = 5;

	print_stack(stack_a, top_a);
	return (0);
}

TESTAR MAIN COM ARGUMENTOS SEM A FUNÇAO print_stack
int main(int argc, char *argv[])
{
    // Verifica se há argumentos suficientes
    if (argc < 2)
	{
        printf("Fornece argumento.\n");
        return 1; // Sai do programa se não houver argumentos suficientes
    }

    printf("Argumentos na ordem inversa (Topo para base):\n");

    int i = argc - 1; // Inicializa i com o índice do último argumento

    // Loop para imprimir os argumentos na ordem inversa
    while (i > 0)
	{
        printf("%s\n", argv[i]); // Imprime o argumento atual
        i--; // Decrementa i para passar ao próximo argumento
    }
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
*/

/*
//#########TESTAR INICIALIZAÇAO DE STACKS
int main()
{
	int	top_a;
	int	top_b;

	init_stacks(&top_a, &top_b);
	if (top_a == -1 && top_b == -1)
	{
		printf("Pilhas inicilizadas correctamente\n stack_A[%d]\n stack_B[%d]", top_a, top_b);
	}
	else
	{
		printf("Erro na inicializaçao das pilhas\n");
	}
	return (0);
}
*/