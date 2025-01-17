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
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "push_swap_operations/push_swap_perations.h"
# include "radix_sort/radix_sort.h"


//################ INICIO DE PREPARAÇAO DAS PILHAS ################
//String valido para DIGITOS
int		ft_digit_valid(const char *str);

//Validar limites de inteiros
int		ft_valid_integer(const char *str);

//Funçao para CHEQUEAR elementos UNICO
int		ft_check_element(int stack[], int top);

//Funçao para validar e converter strings para long
long	ft_validate_and_convert(const char *arg);

//Funçao para inicializar Stacks
void	init_stacks(int *top_a, int *top_b);

//Funçao para inicializar Stack com valore de ARGV convertidos
void	init_stack(int stack[], int *top, int argc, char **argv);

// Setup de Inicialização de Stacks e sua conversão
void	setup_stacks(int stack_a[], int *top_a, int *top_b, int argc, char **argv);

//Funçao para imprimir a pilha (para depuraçao)
void	print_stack(int stack[], int top);

//Funçao para imprimir 2 pilhas
void	print_stacks(int stack_a[], int top_a, int stack_b[], int top_b);
//################ FIM DE PREPARAÇAO DAS PILHAS ################

#endif