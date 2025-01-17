/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:01:42 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-16 16:01:42 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// incluir los include de librerias
// INCLUDES = libft.a 
// $(CC) .... -I $(INCLUDES) 

#include "push_swap.h"
/*
	TESTAR MAIN PUSH_SWAP
*/
int main(int argc,	char **argv)
{
	int	stack_a[MAX_SIZE]; //Tamanho fixo ou estatica
	int	stack_b[MAX_SIZE]; //Tamanho fixo ou estatica
	int	top_a;
	int	top_b;

	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);
	


	//Bucle hasta ordenar el stack a y b, whie(has_sorted())
	combined_radix_sort(stack_a, top_a + 1);
	combined_radix_sort(stack_b, top_b + 1);
	//FUncion que envie los valores del stack_b al stack_a

	/* 
	// Iniciliazar [A] com elementos e [B] vazio
	ft_printf("Stacks inicializada, [A] com elementos e [B] sem elementos\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após 1º'pb'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após o 2º'pb'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após o 3º'pb'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [A] e [B] TENHO QUE VER ISSO
	ss(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] e [B] após 'ss'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] e [B] para CIMA
	rr(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] e [B] após 'rr'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[B] para top[A]
	pa(stack_a,&top_a, stack_b, &top_b);
	ft_printf("\nStack[B] e [A] após o 1º'pa':\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] para BAIXO
	rra(stack_a,top_a);
	ft_printf("\nStack [A] após 'rra'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] e [B] após 4º'pb':\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] e [B] para BAIXO
	rrr(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] após 'rrr'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] e [B]após o 5º'pb'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [B]
	sb(stack_b, top_b);
	ft_printf("\nStack [B] e [A] após 'sb'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [A]
	sa(stack_a, top_a);
	ft_printf("\nStack [A] e [B] após 'sa'\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[B] para top[A]
	pa(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] e [B] após 2º'pa':\n");
	print_stacks(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");
 */
	return (0);
}



/*
Para ordenar elementos em pilhas (stacks) no contexto do projeto push_swap, a escolha do algoritmo adequado dependerá de vários fatores, incluindo eficiência, facilidade de implementação e o número de operações permitidas. Aqui estão algumas opções que podem ser particularmente eficazes para trabalhar com pilhas:

1. Radix Sort:
Vantagens:

Eficiência: Pode ordenar grandes conjuntos de números inteiros rapidamente.

Estável: Mantém a ordem relativa dos elementos iguais.

Desvantagens:

Complexidade de Implementação: Pode ser mais complicado de implementar, especialmente com a necessidade de gerenciar múltiplas passagens.

Uso no push_swap: Adapta bem ao contexto de push_swap, onde você pode usar operações de push e pop para dividir elementos em diferentes "baldes" e ordená-los.

2. Greedy Algorithms:
Vantagens:

Simplicidade: Fácil de implementar e entender.

Minimização de Operações: Foca em realizar a melhor escolha local em cada etapa para alcançar uma solução global.

Desvantagens:

Não Garantido Ótimo: Pode não sempre encontrar a solução globalmente ótima.

Uso no push_swap: Pode ser útil para selecionar as operações de movimentação (sa, sb, pa, pb, etc.) que movam a pilha de forma mais eficiente em direção à ordem final.

3. Dynamic Programming:
Vantagens:

Eficiência: Pode evitar cálculos repetitivos, armazenando resultados intermediários.

Ótimo para Problemas com Subestruturas: Adequado para problemas onde a solução envolve várias etapas interdependentes.

Desvantagens:

Complexidade de Implementação: Pode ser mais difícil de implementar corretamente.

Uso no push_swap: Pode ser usado para memorizar resultados de subproblemas de ordenação e otimizar o processo de ordenação.

Estratégia Combinada:
Dividir e Conquistar: Utilizar uma combinação de técnicas para dividir a pilha em partes menores, ordená-las separadamente e então combiná-las.

Heurísticas Personalizadas: Desenvolver heurísticas específicas para minimizar o número total de operações, considerando o estado atual da pilha.

Recomendação:
Para o projeto push_swap, Radix Sort é uma escolha eficiente e popular, pois pode ser adaptado para trabalhar bem com operações de pilha e é capaz de ordenar grandes conjuntos de dados rapidamente. Algoritmos Greedy e Dynamic Programming podem ser usados para otimizar ainda mais o número de operações e garantir uma solução eficiente.

*/

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

/*
pa
pa
pb
ra
rr
rra

wc -l = contar numero de lineas, quiere decir numero de movimientos 
para 100 numeros el min tiene que ser 700, para 500 serán 5500 minimo
*/