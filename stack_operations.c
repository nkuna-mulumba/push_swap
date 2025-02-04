//Depois ver se é necessario continuar com funçoes peek e pop
#include "push_swap.h"

/*
	Função para inicializar a pilha vazia com valor 
	NULL no top, sem nenhum parametro
*/
t_stack	*init_stack()
{
	// Declarar variável local para a estrutura da pilha
	t_stack	*stack;
	
	// Aloca memória para a estrutura de dados da pilha (membro stack)
	stack = (t_stack *)malloc(sizeof(t_stack));
	//Em caso que alocaçao da memoria do membro falhar, retorna NULL
	if (!stack)
	{
		// Retorna NULL em caso de falha na alocação de memória
		return (NULL);
	}
	// Inicializa o membro com o topo da pilha como NULL, indicando que a pilha está vazia
	stack->top = NULL;
	// Retornar o membro apontada para a estrutura da pilha recém-criada
	return stack;
}

/*
	Função para empilhar (push) ou adicionar
    um novo valor no topo da pilha
	(usado em PA e PB)
*/ 
void	push(t_stack *stack, int value)
{
	// Declarar variável local que servirá para adicionar valor em cada nó na pilha
	t_node	*new_node;

	// Alocar a memória para um novo nó
	new_node = malloc(sizeof(t_node));
	// Verifica se a alocação de memória falhou
	if (!new_node)
	{
		return;
	}
	/*
		Atribuir valor do parâmetro 'value' para 
		o campo 'value' do novo nó
    */
	new_node->value = value;

	// O próximo nó do novo nó é o nó atual no topo da pilha
	new_node->next = stack->top;
	// Atualizar o topo da pilha para o novo nó
	stack->top = new_node;
}

/*
    Função para verificar se a pilha está vazia
    Retorna 1 se a pilha está vazia, caso contrário retorna 0
*/
int	is_empty(t_stack *stack)
{
	//Verificar se a pilha esta vazia
	if (stack->top == NULL)
	{
		//Retornar 1 se nao tiver valor
		return (1);
	}
	else
	{
		//Retornar 0 se tiver valor
		return(0);
	}
}

/*
    Função para exibir todos os elementos da pilha
*/
void	display(t_stack *stack)
{
	// Declarar variável local que vai receber o valor do topo da pilha
	t_node	*current;

	// Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
		return;
	}

	// Inicializa a variável local 'current' com o valor do topo da pilha
	current = stack->top;
	
	ft_printf("Elementos da pilha: ");
	// Percorre a pilha e imprime cada valor
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		// Avança para o próximo nó na pilha
		current = current->next;
	}
	ft_printf("\n");
}

/*
    Função para desempilhar (pop) um valor da pilha
    ou Remove o nó do topo da pilha e retorna o valor desse nó
	(usado em PA e PB)
*/
int	pop(t_stack *stack)
{
	// Declarar variáveis locais que vão armazenar o valor do topo e o nó temporário
	t_node *temp;
	int	value;

	// Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia\n");
		// Retorna um valor indicador de erro (pode ser ajustado conforme necessário)
		return (-1);
	}
	// Armazena o nó atual no topo da pilha em uma variável temporária
	temp = stack->top;

	// Armazena o valor do nó a ser removido
	value = temp->value;

 	// Atualiza o topo da pilha para o próximo nó
	stack->top = stack->top->next;

	// Libera a memória do nó removido
	free(temp);

	 // Retorna o valor do nó removido
	return (value);
}

/*
	Função para acessar (peek) o valor no topo da pilha
    Retorna o valor do nó no topo da pilha sem removê-lo
*/
int	peek(t_stack *stack)
{
	// Verifica se a pilha está vazia
	if (is_empty(stack))
	{
		ft_printf("Pilha vazia.\n");
		// Retorna um valor indicador de erro (pode ser ajustado conforme necessário)
		return (-1);
	}
	// Retorna o valor do nó no topo da pilha
	return (stack->top->value);	
}

/*
	Funçao para trocar os dois elementos
*/
void	swap(t_stack *stack)
{
	// Declarar membros que vão armazenar valor do topo e do nó abaixo do topo
	t_node	*first;
	t_node	*second;

	// Inicializa os ponteiros para os dois primeiros nós
	// `first`aponta ou armazena o valor do nó do topo da pilha 
	first = stack->top;
	// `second` aponta ou armazena o valor do nó logo abaixo do topo da pilha 
	second = stack->top->next;

	// Realiza a troca dos nós
	// `first` agora aponta para o nó que estava originalmente depois de `second`
	first->next = second->next;
	// Atualiza o topo da pilha para `second`, que agora é o novo topo
	second->next = first;
	// Atualiza o topo da pilha para `second`, que agora é o novo topo
	stack->top = second;
}

// Função que verifica se a pilha tem pelo menos dois elementos
int	can_swap(t_stack *stack)
{
	// Retornar verdadeiro se a pilha tem pelo menos dois elementos
	return (stack->top != NULL && stack->top->next != NULL);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [A]
int	sa(t_stack *stack_a)
{
	// Verifica se há pelo menos dois elementos na pilha usando can_swap
	if (!can_swap(stack_a))
	{
		// Não há elementos suficientes para trocar
		return (0);
	}
	
	// Chamar 'swap' para trocar as posições dos dois primeiros valores de [A]
	swap(stack_a);
	// Imprime a operação realizada
	ft_printf("Op:[sa]\n");
	return (1);
}

//Funçao swap para trocar dois primeiros elementos do topo da pilha [B]
int	sb(t_stack *stack_b)
{
	// Verifica se há pelo menos dois elementos na pilha usando can_swap
	if (!can_swap(stack_b))
	{
		// Não há elementos suficientes para trocar
		return (0);
	}
	// Chamar 'swap' para trocar as posições dos dois primeiros valores de [B]
	swap(stack_b);
	// Imprime a operação realizada
	ft_printf("Op:[sb]\n");
	return (1);
}

//Funçao para trocar simultaneamente 2 primeiro elementos de [A] e [B]
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	/*
		Declarar variaveis que recebera a funçao (can_swap) para verificar 
		se a pilha tem pelomenos dois elelemntos para trocar
	*/
	int	can_swap_a;
	int	can_swap_b;

	//Chamar a funçao (can_swap)
	can_swap_a = can_swap(stack_a);
	can_swap_b = can_swap(stack_b);
	/*
		Validar se na pilha A foi encontrada pelomenos dois 
		valores na pilha chama (swap) para trocar as posiçoes
	*/
	if (can_swap_a)
	{
		//chamar (swap) para trocar as posiçoes
		swap(stack_a);
	}
	/*
		Validar se na pilha B foi encontrada pelomenos dois 
		valores na pilha chama (swap) para trocar as posiçoes
	*/
    if (can_swap_b)
	{
		//chamar (swap) para trocar as posiçoes
		swap(stack_b);
	}	
	//Se as duas pilha contem pelomenos dois valor é imprimido a operaçao
    if (can_swap_a && can_swap_b)
	{
		ft_printf("Op:[ss]\n");
	}
}

/*
    Função para empilhar (push) elemento da pilha B para a pilha A
	com paramtero de tipo local ou membros
*/
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	//Declarar variavel que armazenara o nó do topo da pilha B
	int	value;

	//Validar se a pilha B esta vazia antes de mover o nó do topo
	if (is_empty(stack_b))
	{
		ft_printf("Pilha B está vazia, não é possível empilhar para A\n");
		return;
	}
	// Armazenar o valor do nó movido
	value = pop(stack_b);
	// Adicionar o nó movido no topo da pilha A
	push(stack_a, value);
	//Imprimir a operaçao
	ft_printf("Op:[pa]\n");
}

/*
    Função para empilhar (push) elemento da pilha A para a pilha B
	com paramtero de tipo local ou membros
*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	//Declarar variavel que armazenara o nó do topo da pilha A
	int	value;

	//Validar se a pilha A esta vazia antes de mover o nó do topo
	if (is_empty(stack_a))
	{
		ft_printf("Pilha A está vazia, não é possível empilhar para B\n");
		return;
	}
	// Armazenar o valor do nó movido
	value = pop(stack_a);
	// Adicionar o nó movido no topo da pilha B
	push(stack_b, value);
	//Imprimir a operaçao
	ft_printf("Op:[pb]\n");
}

/*
	Função para rotacionar a pilha A, movendo o primeiro elemento para o final
*/
void ra(t_stack *stack_a, int print)
{
	// Declarar a variável local que armazenará o novo nó a ser adicionado na base da pilha A
	t_node	*new_node;
	// Declarar a variável local para percorrer a pilha
	t_node	*current;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return;

	// O ponteiro para o nó de topo é armazenado na variável (new_node)
	new_node = stack_a->top;

	// Atualizar o topo da pilha para ser o segundo nó
	stack_a->top = stack_a->top->next;
	// Definir o próximo nó do nó armazenado em (new_node) como NULL
	new_node->next = NULL;

	// Atualizar `current` para apontar para o novo topo da pilha
	current = stack_a->top;
	// Percorrer a pilha até o último elemento
	while (current->next != NULL)
	{
		current = current->next;
	}

	// Adicionar o nó armazenado ao final da pilha
	current->next = new_node;
	// Verifico se (print) é diferente a zero, imprimir a operação realizada
	if (print != 0)
	{
		ft_printf("Op:[ra]\n");
	}
}

/*
	Função para rotacionar a pilha B, movendo o primeiro elemento para o final
*/
void rb(t_stack *stack_b, int print)
{
	// Declarar a variável local que armazenará o nó a ser movido para o final da pilha A
	t_node *new_node;
	// Declarar a variável local para percorrer a pilha
	t_node *current;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return;

    // O ponteiro para o nó de topo é armazenado na variável (new_node)
	new_node = stack_b->top;
	// Atualizar o topo da pilha para ser o segundo nó
	stack_b->top = stack_b->top->next;
	// Definir o próximo nó do nó armazenado em (new_node) como NULL
	new_node->next = NULL;

	// Atualizar `current` para apontar para o novo topo da pilha
	current = stack_b->top;

	// Percorrer a pilha até o último elemento
	while (current->next != NULL)
	{
		current = current->next;
	}
	// Adicionar o nó removido ao final da pilha
	current->next = new_node;

	// Verifico se (print) é diferente a 0, imprimir a operação realizada
	if (print)
		ft_printf("Op:[rb]\n");
}

/*
    Função para rotacionar ambas as pilhas A e B, movendo o primeiro elemento de cada pilha para o final
*/
void rr(t_stack *stack_a, t_stack *stack_b)
{
	//Declarar variaveis de verificaçao se as pilhas contem pelomenos dois valores
	int	can_rotate_a;
	int	can_rotate_b;

	// Verifica se ambas as pilhas têm pelo menos dois elementos
	can_rotate_a = (stack_a->top != NULL && stack_a->top->next != NULL);
	can_rotate_b = (stack_b->top != NULL && stack_b->top->next != NULL);

	// Validar se foi encontrado dois valores nas pilhas
	if (can_rotate_a && can_rotate_b)
	{
		ra(stack_a, 0); // Rotaciona a pilha A sem imprimir
		rb(stack_b, 0); // Rotaciona a pilha B sem imprimir
		ft_printf("Op:[rr]\n"); // Imprime a operação realizada
	}
}
/*
    Função para rotacionar a pilha [A] ao contrário, movendo o último elemento para o topo
*/
void	rra(t_stack *stack_a, int print)
{
	// Declarar variáveis locais para percorrer a pilha
	t_node	*last;
	t_node	*second_last;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_a) || stack_a->top->next == NULL)
		return;

	// Inicializar last e second_last
	last = stack_a->top;
	second_last = NULL;

	// Percorrer a pilha até o último elemento, iterando subsequente no while:
	while (last->next != NULL)//Verificar se nó anterior é diferente ao NULL
	{
		second_last = last; // second_last aponta para o nó atual
		last = last->next; // last avança para o próximo nó da pilha
	}

	last->next = stack_a->top; // Conecta o último nó ao antigo topo da pilha
	stack_a->top = last; // Atualiza o topo da pilha para o último nó percorrido no while
	second_last->next = NULL; // Penúltimo nó (second_last) agora é o último nó

	// Imprimir a operação realizada se print for diferente de zero
	if (print != 0)
		ft_printf("Op:[rra]\n");
}

/*
    Função para rotacionar a pilha [B] ao contrário, movendo o último elemento para o topo
*/
void	rrb(t_stack *stack_b, int print)
{
	// Declarar variáveis locais para percorrer a pilha
	t_node	*last;
	t_node	*second_last;

	// Verifica se a pilha está vazia ou tem apenas um elemento
	if (is_empty(stack_b) || stack_b->top->next == NULL)
		return;
	// Inicializar last e second_last
	last = stack_b->top;
	second_last = NULL;
	// Percorrer a pilha até o último elemento, iterando subsequente no while:
	while (last->next != NULL)//Verificar se nó anterior é diferente ao NULL
	{
		second_last = last; // second_last aponta para o nó atual
		last = last->next; // last avança para o próximo nó da pilha
	}
	last->next = stack_b->top; // Conecta o último nó ao antigo topo da pilha
	stack_b->top = last; // Atualiza o topo da pilha para o último nó percorrido no while
	second_last->next = NULL; // Penúltimo nó (second_last) agora é o último nó
	// Imprimir a operação realizada se print for diferente de zero
	if (print != 0)
		ft_printf("Op:[rrb]\n");
	
}

/*
	Função para rotacionar ambas as pilhas [A] e [B] ao contrário (rrr)
*/
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	//Declarar variaveis de verificaçao se as pilhas contem pelomenos dois valores
	int	can_rotate_a;
	int	can_rotate_b;

	// Verifica se ambas as pilhas têm pelo menos dois elementos
	can_rotate_a = (stack_a->top != NULL && stack_a->top->next != NULL);
	can_rotate_b = (stack_b->top != NULL && stack_b->top->next != NULL);

	// Validar se foi encontrado dois valores nas pilhas
	if (can_rotate_a && can_rotate_b)
	{
		rra(stack_a, 0); // Rotacionar a pilha [A] ao contrario
		rrb(stack_b, 0); // Rotacionar a pilha [B] ao contrario
		ft_printf("Op: [rrr]\n"); // Imprime a operação realizada para os dois
	}
}

/*
	Função para liberar a memória de uma pilha.
    Percorre cada nó da pilha e libera a memória alocada.
*/
void	free_stack(t_stack *stack)
{
	//Declarar a variavel que vai armazenar valor de top da pilha
	t_node	*current;
	// Declara a variável que armazenará o próximo nó
	t_node	*next_node;
	
	// Atribui o valor do topo da pilha à variável (current)
	current = stack->top;
	// Percorre a pilha enquanto o nó atual não for NULL
	while (current != NULL)
	{
		// Armazena o próximo nó para continuar a iteração após liberar o nó atual
		next_node = current->next;
		 // Libera a memória do nó atual
		free(current);
		// Avança para o próximo nó
		current = next_node;
	}
	// Libera a estrutura da pilha
	free(stack);
}

/*
    Função para verificar se a string representa um 
    número válido dentro do intervalo de int e retornar o valor convertido
*/
long	ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	long num; // Variável para armazenar o número convertido

	// Verifica se a string contém apenas dígitos válidos
	if (!ft_digit_valid(str))
	{
		ft_printf("Erro: Argumento '%s' contém caracteres inválidos\n", str);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); // Encerra o programa se a string não for válida
	}

	// Converte a string para número usando ft_atoi
	num = ft_atol(str);

	// Verifica se o número está dentro dos limites de int
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Erro: Argumento '%s' está fora dos limites de int\n", str);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); // Encerra o programa se o número estiver fora dos limites de int
	}

	//return (num); // Retorna o número convertido se for válido
	return (int)num; // Retorna o número convertido se for válido
}
/*
	Função para verificar se um número já está presente 
	na pilha e gerar mensagem de erro
*/ 
void	check_duplicate(t_stack *stack, int num)
{
	t_node *current; //Declarar variavel que vai receber ńo do topo da pilha
	
	 // O nó do topo da pilha é armazenado em 'current'
	current = stack->top;

	// Percorre a pilha até encontrar o final (NULL)
	while (current != NULL)
    {
		// Verifica se o valor do nó atual é igual ao número fornecido
		if (current->value == num)
		{
			ft_printf("Erro: Número duplicado '%d'\n", num);
			exit(1); // Encerra o programa se o número já estiver presente
		}
		current = current->next; //Apontar  para seguinte nó
	}
}

/*
	Função para inicializar e validar as pilhas, chamando ostras funçoes
*/ 
void	initialize_stacks(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	num;

	// Inicializar as pilhas
	*stack_a = init_stack();
	*stack_b = init_stack();

	if (argc < 2) 
	{
		printf("Número de argumentos insuficiente\n");
		free_stack(*stack_a);
		free_stack(*stack_b);
		exit(1);
	}

	i = 1;
	// Empilhar os valores convertidos na pilha A
	while (i < argc)
	{
		// Validação do número
		num = ft_is_valid_number(argv[i], *stack_a, *stack_b);

		// Verifica se o número já está presente na pilha e gera mensagem de erro se necessário
		check_duplicate(*stack_a, num);

		// Empilha o valor validado na pilha A
		push(*stack_a, num);

		i++;
	}
}