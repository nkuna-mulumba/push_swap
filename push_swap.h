/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 13:37:57 by jcongolo          #+#    #+#             */
/*   Updated: 2024-12-27 13:37:57 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

#  ifndef MAX_SIZE
#   define MAX_SIZE 1000
#  endif 

//Funçao para inicializar Stacks
void	init_stacks(int *top_a, int *top_b);

//Funçao para inicializar Stack com valore de ARGV convertidos
void	init_stack(int stack[], int *top, int argc, char **argv);

//Funçao para CHEQUEAR elementos UNICO
int	check_element(int stack[], int top);

//Funçao para verificar DIGITOS
int	ft_isdigit(int c);

// Setup de Inicialização de Stacks e sua conversão
void	setup_stacks(int stack_a[], int *top_a, int *top_b, int argc, char **argv);

//Funçao para imprimir a pilha (para depuraçao)
void	print_stack(int stack[], int top);

//Funçao para imprimir 2 pilhas
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b);

//Função para trocar os dois primeiros elementos da pilha "A"
void	sa(int stack_a[], int top_a);

//Função para trocar os dois primeiros elementos da pilha "B"
void	sb(int stack_b[], int top_b);

void	ss(int stack_a[], int top_a, int stack_b[], int top_b);

//Função para mover o primeiro elemento da pilha B para a pilha "A"
void	pa(int stack_a[], int *top_a, int stack_b[], int *top_b);

//Funçao para mover o primeiro elemento da pilha "A" para a pilha "B"
void	pb(int stack_a[], int *top_a, int stack_b[], int *top_b);

//Função para rodar todos os elementos da pilha "A" para cima
void	ra(int stack_a[], int top_a);

//Função para rodar todos os elementos da pilha "B" para cima
void	rb(int stack_b[], int top_b);

//Função para rodar os elementos da pilha "A" e "B" para cima simultaneamente
void	rr(int stack_a[], int top_a, int stack_b[], int top_b);

// Função para rodar todos os elementos da pilha A para baixo
void	rra(int stack_a[], int top_a);

// Função para rodar todos os elementos da pilha "B" para baixo
void	rrb(int stack_b[], int top_b);

//Função para rodar os elementos da pilha "A" e "B" para baixo simultaneamente
void	rrr(int stack_a[], int top_a, int stack_b[], int top_b);

#endif