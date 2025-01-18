# Nome do executável final
NAME = push_swap
 
# Arquivos fonte do projeto
SRC = push_swap.c\
	push_swap_validate.c\
	push_swap_operations/push_swap_op1.c\
	push_swap_operations/push_swap_op2.c\
	push_swap_operations/push_swap_op3.c\
	radix_sort/radix_sort_utils.c\
	radix_sort/radix_sort.c main.c

# Arquivos objeto gerados a partir dos arquivos fonte.
OBJ = $(SRC:.c=.o)

# Compilador a ser usado
CC = cc

# Flags do compilador para mostrar todos os avisos, tratar avisos como erros e mostrar avisos extras
FLAGS = -Wall -Wextra -Werror

# Diretórios das bibliotecas LIBFT e PRINTF
LIBFT_DIR = ../libft
PRINTF_DIR = ../printf

#Caminhos para as bibliotecas compiladas
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Regra padrão para compilar o executável
all: $(LIBFT) $(PRINTF) $(NAME)

# Regras para criar o executável a partir dos objetos
$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

# Regras para compilar as bibliotecas LIBFT e PRINTF
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(FLAGS) -I$(PRINTF_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Regra para limpar os arquivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Regra para limpar todos os arquivos gerados, incluindo o executável
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Regra para reconstruir tudo do zero
re: fclean all

.PHONY: all clean fclean re
