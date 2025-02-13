//#include <stdio.h>
#include "push_swap.h"

/*
//Main para testar a funçao (pop)
int main()
{
    t_stack stack;
    stack.top = NULL; // Inicializa a pilha vazia

    // Empilhar valores na pilha
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Topo da pilha: %d\n", stack.top->value); // Deve imprimir 30

    // Desempilhar valores da pilha
    int value = pop(&stack);
    printf("Valor desempilhado: %d\n", value); // Deve imprimir 30
    printf("Novo topo da pilha: %d\n", stack.top->value); // Deve imprimir 20

    return 0;
}
*/

/*
	//Main para verificar as funçoes (peek, is_empty e display)
int main()
{
    t_stack stack;
    stack.top = NULL; // Inicializa a pilha vazia

    // Verificar se a pilha está vazia
    printf("A pilha está vazia? %d\n\n", is_empty(&stack)); // Deve imprimir 1 (verdadeiro)

    // Empilhar valores na pilha
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Exibir os elementos da pilha
    display(&stack); // Deve imprimir: 30 20 10

    // Verificar o valor no topo da pilha
    printf("Valor no topo da pilha: %d\n", peek(&stack)); // Deve imprimir 30

    // Desempilhar valores da pilha
    int value = pop(&stack);
    printf("Valor desempilhado: %d\n", value); // Deve imprimir 30
    printf("\nNovo topo da pilha: %d\n", peek(&stack)); // Deve imprimir 20

    // Exibir os elementos da pilha
    display(&stack); // Deve imprimir: 20 10

    return 0;
}
*/

/*
	// Main para testar as funçoes: init_stack, push, display, sa, sb, ss, free_stack
	int main(int argc, char **argv)
	{
		// Declarar as pilhas A e B
		t_stack *stack_a;
		t_stack *stack_b;
		//Declarar a variavel 'i'para receber 2º argumento na posiçao um.
		int	i;

		// Verifica se há pelo menos um argumento além do executável na posiçao zero
		if (argc < 2)
		{
			ft_printf("Numero de argumentos insuficiente\n");
			return (1);
		}
		//Inicializa as pilhas A e B com valor NULL no top
		stack_a = init_stack();
		stack_b = init_stack();

		// Empilha valores na pilha A (primeiros três argumentos, se houver)
		i = 1;
		while (i <= 3 && i < argc)
		{
			// Converter valor atual de string para inteiro e empilhar na pilha A
			push(stack_a, ft_atoi(argv[i]));
			// Incrementar para o próximo valor
			i++;
		}
		// Empilha valores na pilha B (próximos três argumentos, se houver)
		while (i <= 6 && i < argc)
		{
			// Converter valor atual de string para inteiro e empilhar na pilha B
			push(stack_b, atoi(argv[i]));
			// Incrementar para o próximo valor
			i++;
		}

		// Imprime as pilhas antes da troca
		ft_printf("Pilha A antes de 'sa':\n");
		display(stack_a);
		ft_printf("\nPilha B antes de 'sb':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		// Testa a função sa
		ft_printf("\nPilha A depois de (sa):\n");
		sa(stack_a);
		display(stack_a);
		// Testa a função sb
		ft_printf("\nPilha B depois de sb:\n");
		sb(stack_b);
		display(stack_b);
		ft_printf("______________________________\n");

		// Testa a função ss
		ft_printf("\nPilha A e B depois de ss:\n");
		ss(stack_a, stack_b);
		display(stack_a);
		display(stack_b);
		ft_printf("______________________________\n");
	
	// Libera a memória das pilhas
		free_stack(stack_a);
		free_stack(stack_b);

		return 0;
	}
*/


/*
	//Main para testar pa e pb
	int main(int argc, char **argv)
	{
		t_stack *stack_a; // Declarar a pilha A
		t_stack *stack_b; // Declarar a pilha B
		int i; // Declara a variável 'i' para iteração

		// Verifica se há pelo menos um argumento além do executável
		if (argc < 2)
		{
			ft_printf("Numero de argumentos insuficiente\n");
			return (1);
		}

		// Inicializar as pilhas A e B
		stack_a = init_stack();
		stack_b = init_stack();
		i = 1;

		// Empilhar valores na pilha A (primeiros três argumentos, se houver)
		while (i <= 3 && i < argc)
		{
			push(stack_a, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Empilha valores na pilha B (próximos três argumentos, se houver)
		while (i <= 6 && i < argc)
		{
			push(stack_b, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Imprime as pilhas antes de 'pb'
		ft_printf("Pilha A antes de 'pb':\n");
		display(stack_a);
		ft_printf("\nPilha B antes de 'pb':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		// Testa a função 'pb'
		ft_printf("\nPilha A depois de 'pb':\n");
		pb(stack_b, stack_a);
		display(stack_a);
		ft_printf("\nPilha B depois de 'pb':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		// Testa a função 'pa'
		ft_printf("\nPilha A depois de 'pa':\n");
		pa(stack_a, stack_b);
		display(stack_a);
		ft_printf("\nPilha B depois de 'pa':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		// Libera a memória das pilhas
		free_stack(stack_a);
		free_stack(stack_b);

		return (0);
	}
*/

/*
	// Main para testar ra, rb e rr
	int main(int argc, char **argv)
	{
		t_stack	*stack_a; // Declarar a pilha A
		t_stack	*stack_b; // Declarar a pilha B
		int i; // Declara a variável 'i' para iteração

		// Verifica se há pelo menos um argumento além do executável
		if (argc < 2)
		{
			ft_printf("Numero de argumentos insuficiente\n");
			return (1);
		}

		// Inicializar a pilha A
		stack_a = init_stack();
		stack_b = init_stack();
		i = 1;

		// Empilhar valores na pilha A (primeiros três argumentos, se houver)
		while (i <= 3 && i < argc)
		{
			push(stack_a, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Empilha valores na pilha B (próximos três argumentos, se houver)
		while (i <= 6 && i < argc)
		{
			push(stack_b, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Imprime a pilha antes de 'ra'
		ft_printf("Pilha A antes de 'ra':\n");
		display(stack_a);
		ft_printf("Pilha B antes de 'rb':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		
		// Imprime a pilha depois de 'ra'
		ft_printf("\nPilha A depois de 'ra':\n");
		// Testa a função 'ra'
		ra(stack_a, 1);
		display(stack_a);

		ft_printf("\nPilha B depois de 'rb':\n");
		// Testa a função 'rb'
		rb(stack_b, 1);
		display(stack_b);
		ft_printf("______________________________\n");


		// Imprime A e B depois de 'rr'
		ft_printf("\nPilha A depois de 'rr':\n");
		// Testa a função 'rr'
		rr(stack_a, stack_b);
		display(stack_a);
		ft_printf("\nPilha B depois de 'rr':\n");
		display(stack_b);
		ft_printf("______________________________\n");

		// Libera a memória da pilha
		free_stack(stack_a);
		free_stack(stack_b);

		return (0);
	}
*/

/*
	// Main para testar 
	int main(int argc, char **argv)
	{
		t_stack	*stack_a; // Declarar a pilha A
		t_stack	*stack_b; // Declarar a pilha B
		int i; // Declara a variável 'i' para iteração

		// Verifica se há pelo menos um argumento além do executável
		if (argc < 2)
		{
			ft_printf("Numero de argumentos insuficiente\n");
			return (1);
		}

		// Inicializar a pilha A
		stack_a = init_stack();
		stack_b = init_stack();
		i = 1;

		// Empilhar valores na pilha A (primeiros três argumentos, se houver)
		while (i < argc)
		{
			push(stack_a, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Empilha valores na pilha B (próximos três argumentos, se houver)
		while (i <= 6 && i < argc)
		{
			push(stack_b, ft_atoi(argv[i])); // Converte string para inteiro e empilha
			i++;
		}

		// Imprime a pilha antes de operaçoes
		ft_printf("Pilha A antes de operaçoes:\n");
		display(stack_a);
		ft_printf("Pilha B antes de operaçoes:\n");
		display(stack_b);
		ft_printf("______________________________\n");

		
		// Imprime a pilha depois de operaçoes
		ft_printf("\nPilha A depois de seguintes operaçoes:\n");
		rra(stack_a, 1);
		sa(stack_a);
		ra(stack_a, 1);
		pb(stack_b, stack_a);
		pb(stack_b, stack_a);
		pb(stack_b, stack_a);
		display(stack_a);


		ft_printf("\nPilha B depois de seguintes operaçoes:\n");
		rrb(stack_b, 1);
		sb(stack_b);
		rb(stack_b, 1);
		display(stack_b);
		ft_printf("______________________________\n");


		// Imprime A e B depois
		ft_printf("\nPilha A depois de seguintes operaçoes:\n");
		// Testa a função 'rrr'
		pa(stack_a, stack_b);
		rr(stack_a, stack_b);
		rrr(stack_a, stack_b);
		display(stack_a);
		ft_printf("\nPilha B depois de seguintes operaçoes:\n");
		display(stack_b);
		ft_printf("______________________________\n");


		// Libera a memória da pilha
		free_stack(stack_a);
		free_stack(stack_b);

		return (0);
}
*/

/*

// Validar numero
int main(int argc, char **argv)
{
	t_stack	*stack_a; // Declarar a pilha A
	t_stack	*stack_b; // Declarar a pilha B
	int		i; // Declara a variável 'i' para iteração
	int		num;

	// Verifica se há pelo menos um argumento além do executável
	if (argc < 2)
	{
		printf("Numero de argumentos insuficiente\n");
		return (1);
	}

	// Inicializar as pilhas
	stack_a = init_stack();
	stack_b = init_stack();

	// Empilhar os valores convertidos na pilha A
	i = 1;
	while (i < argc)
	{
		// Validação do número
		num = ft_is_valid_number(argv[i], stack_a, stack_b);

		// Verifica se o número já está presente na pilha e gera mensagem de erro se necessário
		check_duplicate(stack_a, num);

		// Empilha o valor validado na pilha A
		push(stack_a, (int)num);
		i++;
	}

	// Imprime a pilha antes das operações
	ft_printf("Pilha A antes das operações:\n");
	display(stack_a);
	ft_printf("Pilha B antes das operações:\n");
	display(stack_b);
	ft_printf("______________________________\n");

	// Executa algumas operações nas pilhas (exemplo de operações)
	ft_printf("\nPilha A depois das seguintes operações:\n");
	rra(stack_a, 1);
	sa(stack_a);
	ra(stack_a, 1);
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	display(stack_a);

	ft_printf("\nPilha B depois das seguintes operações:\n");
	rrb(stack_b, 1);
	sb(stack_b);
	rb(stack_b, 1);
	display(stack_b);
	ft_printf("______________________________\n");

	// Executa mais operações nas pilhas (exemplo de operações)
	ft_printf("\nPilha A depois das seguintes operações:\n");
	pa(stack_a, stack_b);
	rr(stack_a, stack_b);
	rrr(stack_a, stack_b);
	display(stack_a);

	ft_printf("\nPilha B depois das seguintes operações:\n");
	display(stack_b);
	ft_printf("______________________________\n");

	// Libera a memória das pilhas
	free_stack(stack_a);
	free_stack(stack_b);

	return (0);
}
*/


/*
	// Testar preparaçao das pilha e validaçao de valores
	int main(int argc, char **argv)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;

		// Inicializar e validar as pilhas
		initialize_stacks(argc, argv, &stack_a, &stack_b);

		// Imprime a pilha antes das operações
		ft_printf("Pilha A antes das operações:\n");
		display(stack_a);
		// ft_printf("Pilha B antes das operações:\n");
		// display(stack_b);
		ft_printf("______________________________\n");

		// Executa algumas operações nas pilhas (exemplo de operações)
		ft_printf("\nPilha A depois das seguintes operações:\n");
		sa(stack_a);
		display(stack_a);
		ra(stack_a, 1);
		display(stack_a);
		rra(stack_a, 1);
		display(stack_a);
		pb(stack_b, stack_a);
		display(stack_a);
		display(stack_b);
		pb(stack_b, stack_a);
		display(stack_a);
		display(stack_b);
		pb(stack_b, stack_a);
		display(stack_a);
		display(stack_b);

		ft_printf("\nPilha B depois das seguintes operações:\n");
		rrb(stack_b, 1);
		display(stack_b);
		sb(stack_b);
		display(stack_b);
		rb(stack_b, 1);
		display(stack_b);
		ft_printf("______________________________\n");

		// Executa mais operações nas pilhas (exemplo de operações)
		ft_printf("\nPilha A depois das seguintes operações:\n");
		pa(stack_a, stack_b);
		display(stack_a);
		display(stack_b);
		ft_printf("\nPilha A e B:\n");
		pb(stack_b, stack_a);
		display(stack_a);
		display(stack_b);
		ft_printf("\nPilha A e B:\n");
		rr(stack_a, stack_b);
		display(stack_a);
		display(stack_b);
		ft_printf("\nPilha A e B:\n");
		rrr(stack_a, stack_b);
		display(stack_a);
		display(stack_b);
		ft_printf("\nPilha A e B:\n");
		ss(stack_a, stack_b);
		display(stack_a);
		display(stack_b);
		ft_printf("______________________________\n");

		free_stack(stack_a);
		free_stack(stack_b);

		return 0;
	}
*/






/*
*/
// Main para testa algoritimo de ordenaçao
// int main(int argc, char **argv)
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;

// 	initialize_stacks(argc, argv, &stack_a, &stack_b);

// 	// Exibir a pilha A antes das operações
// 	//ft_printf("Pilha A antes das operações:\n");
// 	//display(stack_a);
// 	//ft_printf("______________________________\n");

// 	if (is_sorted(stack_a))
// 	{
// 		free_stack(stack_a);
// 		free_stack(stack_b);
// 		return 0;
// 	}
	
// 	// Chamar a função de ordenação adequada com base no número de elementos
// 	if (argc == 3) // Garantir que temos exatamente 2 elementos
// 	{
// 		sort_two(stack_a);
// 	}
// 	// Testar operação sort_three
// 	else if (argc == 4)// Garantir que temos exatamente 3 elementos
// 	{
// 		sort_three(stack_a);
// 	}
// 	else if (argc == 5)// Garantir que temos exatamente 4 elementos
// 	{
// 		sort_four(stack_a, stack_b);
// 	}
// 	else if (argc == 6)// Garantir que temos exatamente 5 elementos
// 	{
// 		sort_five(stack_a, stack_b, 0);
// 	}
	
// 	/*
// 	//Exibir a pilha A depois das operações
// 	ft_printf("Pilha A depois das operações:\n");
// 	display(stack_a);
// 	ft_printf("______________________________\n");
// 	*/

// 	// Limpar a memória das pilhas
// 	free_stack(stack_a);
// 	free_stack(stack_b);

// 	return 0;
	
// }



int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	total_elements;

	(void)argc; // Evitar aviso de parâmetro não utilizado

	initialize_stacks(argv, &stack_a, &stack_b);

	// Exibir a pilha A antes das operações
	ft_printf("Pilha A antes das operações:\n");
	display(stack_a);
	ft_printf("______________________________\n");

	// Verificar se a pilha já está ordenada
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}

	// Calcular o número total de elementos na pilha
	total_elements = stack_size(stack_a);

	// Chamar a função de ordenação adequada com base no número de elementos
	if (total_elements == 2)
	{
		sort_two(stack_a);
	}
	else if (total_elements == 3)
	{
		sort_three(stack_a);
	}
	else if (total_elements == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if (total_elements == 5)
	{
		sort_five(stack_a, stack_b, 0);
	}

	// Limpar a memória das pilhas
	free_stack(stack_a);
	free_stack(stack_b);

	return 0;
}






/*
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap "4 67 3 87 23"
	Erro: Argumento '4 67 3 87 23' contém caracteres inválidos
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap 4 6 2 | ./checker_linux 4 6 2
	OK
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap 4 6 2 79 | ./checker_linux 4 6 2 79
	OK
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap 4 6 2 79 -5 | ./checker_linux 4 6 2 79 -5
	OK
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap 4 6 2 79 -5 6 | ./checker_linux 4 6 2 79 -5 6
	Error
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ARG="4 67 3 87 23"; ./push_swap 4 6 2 79 -5 6 | ./checker_linux 4 6 2 79 -5 6C
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ./push_swap 45 6 5 6
	Erro: Número duplicado '6'
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ./push_swap "55 66 66 444"  44  5
	Erro: Argumento '55 66 66 444' contém caracteres inválidos
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ./push_swap "55 66 66 444"       
	Erro: Argumento '55 66 66 444' contém caracteres inválidos
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% 55
	zsh: command not found: 55
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% 66
	zsh: command not found: 66
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% 66
	zsh: command not found: 66
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% 44
	zsh: command not found: 44
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% ./push_swap 55 66 66 444 
	Erro: Número duplicado '66'
	jcongolo@c2r8s6 ~/Desktop/push_swap
	% 
*/


