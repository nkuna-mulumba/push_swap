/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:38:26 by jcongolo          #+#    #+#             */
/*   Updated: 2025-02-17 22:38:26 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Inclua apenas as bibliotecas necessárias
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

/*
	Estrutura que representa um unico elemento (nó) na pilha
	formando uma lista encadeada.
*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/*
    Estrutura que representa a pilha completa.
*/
typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//###### INICIALIZAÇÃO E MANIPULAÇÃO DA PILHA #####
// Função para inicializar uma pilha vazia
t_stack	*init_stack(void);
// Função para inicializar chamando outras funções
int		initialize_stacks(char **argv, t_stack **stack_a, t_stack **stack_b);
//Empilar (Push) : Adiciona um novo elemento ao topo da pilha.
void	push(t_stack *stack, int value);
//Funçao para verificar se a pilha esta vazia
int		is_empty(t_stack *stack);
//Funçao para exibir todos elementos da pilha
void	display(t_stack *stack);
//Desempilhar (Pop)Remove o elemento do topo da pilha e retorna este elemento.
int		pop(t_stack *stack);
// Função para contar o número de elementos na stack_a
int		stack_size(t_stack *stack);

//## OPERAÇOES NA PILHA
//Funçao swap para trocar dois primeiros elementos
void	swap(t_stack *stack);
//Função que verifica se a pilha tem pelo menos dois elementos
int		can_swap(t_stack *stack);
//Funçao swap para trocar dois primeiros elementos do topo da pilha [A]
int		sa(t_stack *stack);
//Funçao swap para trocar dois primeiros elementos do topo da pilha [B]
int		sb(t_stack *stack);
//Funçao para trocar simultaneamente 2 primeiro elementos de [A] e [B]
void	ss(t_stack *stack_a, t_stack *stack_b);
//Função para empilhar (push) elemento da pilha [B] para a pilha [A]
void	pa(t_stack *stack_a, t_stack *stack_b);
//Função para empilhar (push) elemento da pilha [A] para a pilha [B]
void	pb(t_stack *stack_b, t_stack *stack_a);
//Funçao para rotar para cima os elelmentos de [A]
void	ra(t_stack *stack_a, int print);
// Funçao para rotar para cima os elelmentos de [B]
void	rb(t_stack *stack_b, int print);
// Funçao para rotar silmultaneamente para cima [A] e [B]
void	rr(t_stack *stack_a, t_stack *stack_b);
//Funçao para rotear baixo os elementos de [A] 
void	rra(t_stack *stack_a, int print);
//Funçao para rotear baixo os elementos de [A] 
void	rrb(t_stack *stack_b, int print);
// Função para rotacionar ambas as pilhas ao contrário (rrr)
void	rrr(t_stack *stack_a, t_stack *stack_b);

//## LIBERAR A MEMORIA ALOCADO
// Função para liberar a memória de uma pilha
void	free_stack(t_stack *stack);

//## VALIDAR ARGUMENTOS E INICIALIZAR STACKS
//Função verificando se str representa número válido dentro do intervalo de int
long	ft_is_valid_number(const char *str, t_stack *stack_a, t_stack *stack_b);
//Função para verificar se um número já está presente na pilha
int		check_duplicate(t_stack *stack, int num);
//Função para validar os valores e empilhá-los
void	validate_and_push(char **args, t_stack *tmp, t_stack *a, t_stack *b);
//Função para dividir a string em substrings e validar os valores
void	process_arguments(char *arg, t_stack *tmp, t_stack *a, t_stack *b);
//FUnçao para validar argumentos ou parceros de strings
int		validate_args(char **argv, t_stack *tmp, t_stack *a, t_stack *b);

/*
	ALGORITMO DE ORDENAÇÃO
*/
// Funçao auxiliar para verificar se a pilha está ordenada
int		is_sorted(t_stack *stack);
//Funçao para ordenar dois elementos na pilha
void	sort_two(t_stack *stack);
// Função para ordenar três elementos na pilha
void	sort_three(t_stack *stack);
//Funçao auxiliar para encontrar indice de menor valor no STACK_A
int		find_min_position(t_stack *stack);
//Funçao para ordenar quatro elelementos na pilha
void	sort_four(t_stack *stack_a, t_stack *stack_b);
//FUnçao para ordenar cinco elementos na pilha
void	sort_five(t_stack *stack_a, t_stack *stack_b, int count);
//Funçao para mover elementos menores
//void	move_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *size);
// Funçao para ordenar e mesclagem de valores removidos
//void	finalize_sort(t_stack *stack_a, t_stack *stack_b, int total_elements);
//Função para ordenar um grande número
//void	sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements);

void separate_numbers(t_stack *stack_a, t_stack *stack_pos, t_stack *stack_neg);

int get_max(t_stack *stack);

void count_sort(t_stack *stack_a, t_stack *stack_b, int exp);

void count_sort_negatives(t_stack *stack_a, t_stack *stack_b, int exp);

void radix_sort(t_stack *stack_a, t_stack *stack_b);

void sort_large(t_stack *stack_a, t_stack *stack_b, int total_elements);

#endif


