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
#include "../printf/ft_printf.h"

//Funçao para DIGITOS
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
//String valido para DIGITOS
int	ft_digit_valid(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
//Convert Alpa to Integre com long
long	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	convert;

	i = 0;
	while (((unsigned char)nptr[i] >= 9 && (unsigned char)nptr[i] <= 13)
		|| ((unsigned char)nptr[i] == 32))
		i++;
	sign = 1;
	if (((unsigned char)nptr[i] == 43) || ((unsigned char)nptr[i] == 45))
	{
		if ((unsigned char)nptr[i] == 45)
			sign = -1;
		i++;
	}
	convert = 0;
	while (ft_isdigit((unsigned char)nptr[i]))
	{
		convert = (convert * 10) + ((unsigned char)nptr[i] - 48);
		i++;
	}
	return (sign * convert);
}
//Validar limites de inteiros
int	ft_valid_integer(const char *str)
{	
	long	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		return (0); // Fora do intervalo permitido
	}
    return (1); // É um inteiro válido
}
//Funçao para CHEQUEAR elementos UNICO
int	ft_check_element(int stack[], int top)
{
	int	i;
	int	j;

	i = 0;
	while (i <= top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (stack[i] == stack[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
//Funçao para validar e converter strings para long
long	ft_validate_and_convert(const char *arg)
{
	if (!ft_digit_valid(arg))
	{
		ft_printf("ERROR 'VALOR CONTÉM CARACTERES NÃO NUMÉRICOS'\n");
		exit (1);
	}
	if (!ft_valid_integer(arg))
	{
		ft_printf("ERROR 'VALOR INVÁLIDO: %s'\n", arg);
		exit (1);
	}
	return (ft_atoi(arg));
}
//Funçao para inicializar os Stacks
void	init_stacks(int *top_a, int *top_b)
{
	*top_a = -1;
	*top_b = -1;
}

//Funçao para inicializar Stack com valores de ARGV convertidos e validos
void	init_stack(int stack[], int *top, int argc, char **argv)
{
	int	i;

	i = 1; // Começamos do índice 1 para ignorar o nome do programa
	*top = -1; // *top é inicializado para -1 para indicar que a pilha está vazia.
	while(i < argc)
	{
		stack[++(*top)] = (int)ft_validate_and_convert(argv[i]); //Inserir valor na Pila convertido para INT
		if (!ft_check_element(stack, *top)) // Verifica a unicidade dos elementos na pilha stack_a
		{
			ft_printf("ERROR 'VALORES DUPLICADOS'\n");
			exit (1);
		}
		i++;
	}
}
// Setup de Inicialização de Stacks e sua conversão
void	setup_stacks(int stack_a[], int *top_a, int *top_b, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("ERROR 'NUMERO DE ARGUMENTO INSUFIENTE'\n");
		exit (1);
	}

	init_stacks(top_a, top_b); // Inicializa as variáveis top_a e top_b	
	init_stack(stack_a, top_a, argc, argv);// Inicializa a pilha A com os valores fornecidos
}


//Funçao para imprimir a pilha (para depuraçao)
void	print_stack(int stack[], int top)
{
	while (top >= 0)
	{
		ft_printf("%d\n", stack[top]);
		top--;
	}
}
//Funçao para imprimir as dois pilhas A e B
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b)
{
	print_stack(stack_a, top_a);
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
	Implementaçao de algoritimo de ordeçao Radix Sort
	Adaptado para numeros negativos e positivos
*/
//Obter maior elemento da pila e identificar sua magnitude.
int	get_max(int stack[], int top)
{
	int	max;
	int	i;
	
	max = stack[0]; //Primeiro valor da pila
	i = 1; //Iciar com valor da segunda posiçao da pila
	while (i <= top)
	{
		if (stack[i] > max)
		{
			max = stack[i];
		} 
		i++;
	}
	return max; //Retornar o maior valor
}
//Contagem ordenada
void	count_sort(int stack[], int output[], int top, int exp)
{
	int	count[10] = {0}; //Contagem de digitos
	int	i;
	int	digit;

	// Primeiro Loop: Conta os dígitos na posição `exp`
	i = 0;
	while (i <= top)
	{
		count[(stack[i] / exp) % 10]++;
		i++;
	}

	// Segundo Loop: Ajusta as posições acumuladas no array `count`
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	// Terceiro Loop: Constrói o array `output` colocando os números na posição correta
	i = top;
	while (i >= 0)
	{
		digit = (stack[i] / exp) % 10;
		output[count[digit] - 1] = stack[i];
		count[digit]--;
		i--;
	}
	// Copia os números ordenados de volta para `stack`
	i = 0;
	while (i <= top)
	{
		stack[i] = output[i];
		i++;
	}
}
// Função para separar números positivos e negativos
void separate_numbers(int stack[], int top, int pos_stack[], int *pos_top, int neg_stack[], int *neg_top)
{
	int i;

	*pos_top = -1;
	*neg_top = -1;
	i = 0;

	while (i <= top)
	{
		if (stack[i] >= 0)
		{
			pos_stack[++(*pos_top)] = stack[i];
		}
		else
		{
			neg_stack[++(*neg_top)] = -stack[i]; // Armazena o valor absoluto
		}
		i++;
	}
}
//Funçao principal controlar o proceso de ordenaçao e definir expoente
void	radix_sort(int stack[], int n)
{
	int	output[n];
	int	max;
	int	exp;

	// Aplica count_sort para cada posição decimal (unidades, dezenas, centenas, etc.)
	max = get_max(stack, n - 1);
	exp = 1;
	while (max / exp > 0)
	{
		count_sort(stack, output, n - 1, exp);
		exp *= 10; // Atualiza exp para a próxima posição dos dígitos
	}
}
// Função para ordenar e combinar números positivos e negativos
void	combined_radix_sort(int stack[], int n)
{
	int	pos_stack[n];
	int	neg_stack[n];
	int	pos_top;
	int	neg_top;
	int	i;
	int j;
	
	separate_numbers(stack, n - 1, pos_stack, &pos_top, neg_stack, &neg_top);
	
	if (pos_top >= 0)
	{
		radix_sort(pos_stack, pos_top + 1);
	}
	if (neg_top >= 0)
	{
		radix_sort(neg_stack, neg_top + 1);
		i = 0;
		while (i <= neg_top)
		{
			neg_stack[i] = -neg_stack[i]; // Converte de volta para negativo
			i++;
		}
	}
	i = 0;
	while (neg_top >= 0)
	{
		stack[i++] = neg_stack[neg_top--];
	}
	j = 0;
	while (j <= pos_top)
	{
		stack[i++] = pos_stack[j++];
	}
}


int main(int argc,	char **argv)
{
	int	stack_a[MAX_SIZE];
	int	stack_b[MAX_SIZE];
	int	top_a;
	int	top_b;

	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);
	

	/**
	 * Indexar -> 
	 * 
	 * Primero verifico si el tamaño de elementos es 3
	 * 
	 * Segundo si es menor a 7 elementos y mayor a 3 elementos
	 * { }
	 * y ultimo si es mayor a 7
	 * { Voy a aplicar un algorimo de ordenacion para push_swapX }
	 */
	// Imprimir elementos de [A] e [B] vazio



	
	ft_printf("\nStack [A] com elementos\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack [B] vazio:\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após 1º'pb':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack[B] após o 1º'pb':\n");
	print_stack(stack_b, top_b);
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após o 2º'pb':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack[B] após o 2º'pb':\n");
	print_stack(stack_b, top_b);
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após o 3º'pb':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack[B] após o 3º'pb':\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [A] e [B]
	ss(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] após 'ss':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack [B] após 'ss':\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] e [B] para CIMA
	rr(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] após rr:\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack [B] após rr:\n");rr(stack_a, top_a, stack_b, top_b);
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[B] para top[A]
	pa(stack_a,&top_a, stack_b, &top_b);
	ft_printf("\nStack[B] após o 1º'pa':\n");
	print_stack(stack_b, top_b);
	ft_printf("\nStack[A] após 1º'pa':\n");
	print_stack(stack_a, top_a);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] para BAIXO
	rra(stack_a,top_a);
	ft_printf("\nStack [A] após rra:\n");
	print_stack(stack_a, top_a);rr(stack_a, top_a, stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após 4º'pb':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack[B] após o 4º'pb':\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	//Rodar elementos de [A] e [B] para BAIXO
	rrr(stack_a, top_a, stack_b, top_b);
	ft_printf("\nStack [A] após rrr:\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack [B] após rrr:\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[A] para top[B]
	pb(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[B] após o 5º'pb':\n");
	print_stack(stack_b, top_b);
	ft_printf("\nStack[A] após o 5º'pb':\n");
	print_stack(stack_a, top_a);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [B]
	sb(stack_b, top_b);
	ft_printf("\nStack [B] após 'sb':\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

	// Trocar os 2 primeiro elementos de [A]
	sa(stack_a, top_a);
	ft_printf("\nStack [A] após 'sa':\n");
	print_stack(stack_a, top_a);
	ft_printf("\n______________________________\n");

	// Mover elemento do top[B] para top[A]
	pa(stack_a, &top_a, stack_b, &top_b);
	ft_printf("\nStack[A] após 2º'pa':\n");
	print_stack(stack_a, top_a);
	ft_printf("\nStack[B] após 2º'pa':\n");
	print_stack(stack_b, top_b);
	ft_printf("\n______________________________\n");

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