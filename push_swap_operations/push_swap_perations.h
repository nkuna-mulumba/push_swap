/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_perations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 11:55:42 by jcongolo          #+#    #+#             */
/*   Updated: 2025-01-17 11:55:42 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H

//######### INICIO DE MOVIMENTAÇAO DE ELEMENTOS NAS PILHAS #########
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
//#########FIM DE MOVIMENTAÇAO DE ELEMENTOS NAS PILHAS #########

#endif