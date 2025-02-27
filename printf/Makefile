# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 21:05:42 by jcongolo          #+#    #+#              #
#    Updated: 2024/10/29 14:27:48 by jcongolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SRCS = ft_handle_char.c ft_handle_int_dcml.c ft_handle_void_pointer.c\
		ft_printf.c ft_unsigned_int_to_str.c ft_handle_hex_lower.c\
		ft_handle_strings.c ft_itoa.c ft_reverse_str.c ft_handle_hex_upper.c\
		ft_handle_unsigned_int.c ft_num_to_hex.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS =  -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		cc $(FLAGS) -c $< -o $@ -I ./

$(NAME):
	cc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
