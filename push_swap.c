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
long	ft_atol(const char *nptr)
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
	long	value = ft_atol(str);
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
	return (ft_atol(arg));
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





/*
	Implementaçao de algoritimo de ordeçao Radix Sort
 	Adaptado para numeros negativos e positivos
*/
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

/*
	*Objetivo: Ordenar os números na pilha usando Radix Sort.
	*int max = get_max(stack, n - 1): Encontra o maior valor na pilha.
	*while (max / exp > 0): Loop através de cada posição decimal (unidades,
	dezenas, centenas, etc.).
      - count_digits: Conta os dígitos na posição exp.
      - adjust_positions: Ajusta as posições e organiza os números.
*/
void	radix_sort(Stacks *stacks, int stack[], int n)
{
	int	max_val;
	int	exp;
	int	output[n]; //Array de saida para armazenar resultado ordenado
	
	max_val = get_max(stacks);// Chamada ajustada para usar o objeto Stacks
	// Se max_val for 0 e todos os elementos de stack forem 0, não há necessidade de ordenar
	if (max_val == 0)
	{
		return;
	}
	
	/*
		Inicializar 'exp' com 1 para começar com as unidades.
		'exp' extrai o dígito específico de cada elemento.
	*/
	exp = 1;
	while (max_val / exp > 0)
	{
		/*
			Inicializar array de contagem em cada iteraçao com 0 em cada posiçao 
			para armazenar a contagem dos dígitos (0-9)
		*/
		int count[10] = {0};
		
		// Contar dígitos na posição decimal atual (exp) na pilha positiva
		count_digits(stack, n - 1, exp, count);
		// Ajustar posições e organizar os elementos
		adjust_positions(stack, output, n - 1, exp, count);
		// Atualizar "exp" próxima posição decimal (dezenas, centenas, etc.)
		exp *= 10;
	}
}

/*
	*Objetivo: Ordenar os números positivos.
	*if (stacks->pos_top >= 0): Verifica se há números positivos na pilha.
	  - radix_sort: Ordena a pilha de números positivos.
*/
void	sort_positives(Stacks *stacks)
{
	//Acessar elemento - index pos_top, verificando se ha numeros positivos
	if (stacks->pos_top >= 0)
	{
		//Ordenar valor positivos na pilha de numeros positivos, ajustando tamanho exacto de elementos
		radix_sort(stacks, stacks->pos_stack, stacks->pos_top + 1);
	}
}

/*
	*Objetivo: Ordenar os números negativos e convertê-los de volta para valores negativos.
	*if (stacks->neg_top >= 0): Verifica se há números negativos na pilha.
	  - radix_sort: Ordena a pilha de números negativos.
	  - while (i <= stacks->neg_top): Converte os valores absolutos de volta para negativos.
*/
void	sort_negatives(Stacks *stacks)
{
	int	i;
	// Verificar se há elementos na pilha de números negativos
	if (stacks->neg_top >= 0)
	{
		// Ordenar os valores absolutos na pilha de números negativos, ajustando tamanho exacto de elementos
		radix_sort(stacks, stacks->neg_stack, stacks->neg_top + 1);
		// Reverter os valores absolutos de volta para negativos
		i = 0;
		while (i <= stacks->neg_top)
		{
			stacks->neg_stack[i] = -stacks->neg_stack[i];
			i++;
		}
	}
}

/*
	*Objetivo: Combinar todos os passos anteriores para ordenar o array 
			   stack com números positivos e negativos.
	*separate_numbers: Separa os números em positivos e negativos.
	*sort_positives: Ordena a pilha de números positivos.
	*sort_negatives: Ordena a pilha de números negativos.
	*Combinar Resultados: Combina as pilhas ordenadas de volta no array stack.
*/
void combined_radix_sort(int stack[], int n)
{
	/*
		Declarar uma instância da estrutura Stacks usada para armazenar 
		e organizar os números positivos e negativos em pilhas separadas.
	*/
	Stacks	stacks;
	int	i;
	int	j;

	// Separar números positivos e negativos
	separate_number(stack, n - 1, &stacks);
	// Ordenar números positivos
	sort_positives(&stacks);
	// Ordenar números negativos e revertê-los para negativos
	sort_negatives(&stacks);

	i = 0;
	// Adicionar números negativos revertidos à pilha original
	while (stacks.neg_top >= 0)
	{
		// Adicionar valores negativos ordenados ao início da stack
		stack[i++] = stacks.neg_stack[stacks.neg_top--];
	}
	j = 0;
	while (j <= stacks.pos_top)
	{
		// Adicionar valores positivos ordenados após os negativos
		stack[i++] = stacks.pos_stack[j++];
	}	
}





//Funçao para imprimir as dois pilhas A e B
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b)
{
	// Ordenar as pilhas antes de imprimir
	 combined_radix_sort(stack_a, top_a + 1);
	 combined_radix_sort(stack_b, top_b + 1);

	// Imprimir as pilhas ordenadas
	ft_printf("Stack[A]:\n");
	print_stack(stack_a, top_a);
	ft_printf("\n");
	ft_printf("Stack[B]:\n");
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

// // TESTAR RADIX SORT
// int main()
// {
// 	//int stack[] = {170, -45, 75, -90, 802, 24, -2, 66};
// 	int stack[] = 
// 	{34, -2, 45, -32, 11, -78, 99, 27, -48, 62, 0, -5, 3,
// 	-12, 87, 45, -33, 56, -1, 88, -92, 33, -6, 55, -15, 23,
// 	-17, 77, -90, 29, 18, -36, 61, -10, 12, -40, 71, -14, 93,
// 	-9, 44, -25, 32, -8, 57, -4, 16, -13, 81, -7, 2, 50, -39,
// 	35, -19, 63, -23, 14, -29, 75, -21, 66, -34, 28, -11, 59,
// 	-20, 79, -42, 17, -3, 22, -44, 30, -22, 47, -30, 24, -27,
// 	67, -18, 37, -24, 46, -26, 20, -41, 73, -38, 9, -49, 40,
// 	-31, 69, -28, 60, -43, 25, -35, 7, -46, 19, -16, 51, -47,
// 	41, -45, 21};
// 	int top;
// 	int	i;


// 	// Ajusta para usar 'top' como índice exato de stack[]
// 	top = sizeof(stack) / sizeof(stack[0]);
// 	i = 0;

// 	// Imprimir o array inicial
// 	ft_printf("Array inicial: \n");
// 	while (i < top)
// 	{
// 		ft_printf("%d ", stack[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
	
// 	// Chama a função de ordenação
// 	combined_radix_sort(stack, top);

// 	// Imprimir a pilha ordenado
// 	ft_printf("Pilha ordenada:\n");
// 	i = 0;
// 	while (i < top)
// 	{
// 		ft_printf("%d ", stack[i]);
// 		i++;
// 	}
// 	ft_printf("\n");

// 	return 0;
// }

/*
Resumo:
Array (int stack[]): Aloca memória dinamicamente 
e permite inicializar com uma lista de valores.

Ponteiro (int *stack): Precisa de alocação de memória 
separada e não pode ser inicializado diretamente com 
uma lista de valores.
*/

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



	
	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);
	
	// Iniciliazar [A] com elementos e [B] vazio
	ft_printf("Stacks inicializada, [A] com elementos e [B] sem elementos\n");
	//print_stack(stack_a, top_a);
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