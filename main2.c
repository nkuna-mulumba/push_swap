// incluir header do projecto
#include "push_swap.h"
#include <string.h>

//Contador para operadores
int	count_pb = 0;
int	count_pa = 0;
int	count_sa = 0;
int	count_sb = 0;
int	count_ss = 0;
int	count_ra = 0;
int	count_rb = 0;
int	count_rr = 0;
int	count_rra = 0;
int	count_rrb = 0;
int	count_rrr = 0;

// Defina um array com as operações
char	*operation[] = {"pb", "pa", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr"};
int		num_operation = sizeof(operation) / sizeof(operation[0]);
int		i = 0;

//Funçao para decidir operaçao beseada no array
char	*decide_next_operation()
{
	if (i < num_operation)
	{
		return operation[i++];
	}
	else
	{
		return NULL;
	}
}

int main(int argc,	char **argv)
{
	int	stack_a[MAX_SIZE]; //Tamanho fixo ou estatica
	int	stack_b[MAX_SIZE]; //Tamanho fixo ou estatica
	int	top_a;
	int	top_b;

	// Setup de Inicialização de Stacks e sua conversão
	setup_stacks(stack_a, &top_a, &top_b, argc, argv);



	//Loop para realizar as operaçoes e incrementar os contadores
	char	*operation; // Variável para armazenar a próxima operação a ser executada
	while ((operation = decide_next_operation()) != NULL)
	{
		if (strcmp(operation, "sa") == 0)
		{
			sa(stack_a, top_a); //Correcto
			ft_printf("sa\n");
			count_sa++;
		}
		else if (strcmp(operation, "sb") == 0)
		{
			sb(stack_b, top_b); //Correcto
			ft_printf("sb\n");
			count_sb++;
		}
		else if (strcmp(operation, "ss") == 0)
		{
			ss(stack_a, top_a, stack_b, top_b);//Correcto
			ft_printf("ss\n");
			count_ss++;
		}
		else if (strcmp(operation, "pa") == 0)
		{
			pa(stack_a, &top_a, stack_b, &top_b); //Correcto
			ft_printf("pa\n");
			count_pa++;
		}
		else if (strcmp(operation, "pb") == 0)
		{
			pb(stack_a, &top_a, stack_b, &top_b); //Correcto
			ft_printf("pb\n");
			count_pb++;
		}
		else if (strcmp(operation, "ra") == 0)
		{
			ra(stack_a, top_a);
			ft_printf("ra\n");
			count_ra++;
		}
		else if (strcmp(operation, "rb") == 0)
		{
			rb(stack_b, top_b);
			ft_printf("rb\n");
			count_rb++;
		}
		else if (strcmp(operation, "rr") == 0) //Correcto
		{
			rr(stack_a, top_a, stack_b, top_b);
			ft_printf("rr\n");
			count_rr++;
		}
		else if (strcmp(operation, "rra") == 0)
		{
			rra(stack_a, top_a); //Correcto
			ft_printf("rra\n");
			count_rra++;
		}
		else if (strcmp(operation, "rrb") == 0)
		{
			rrb(stack_b, top_b); 
			ft_printf("rrb\n");
			count_rrb++;
		}
		else if (strcmp(operation, "rrr") == 0)
		{
			rrr(stack_a, top_a, stack_b, top_b); //Correcto
			ft_printf("rrr\n");
			count_rrr++;
		}
	}
	combined_radix_sort(stack_a, top_a + 1);
//	combined_radix_sort(stack_b, top_b + 1);

	// //Bucle hasta ordenar el stack a y b, while(has_sorted())
	// combined_radix_sort(stack_a, top_a + 1);
	// combined_radix_sort(stack_b, top_b + 1);
	// //Funcion que envie los valores del stack_b al stack_a

	return (0);
}