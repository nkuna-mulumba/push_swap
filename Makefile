# Nome do executável final
NAME = push_swap

# Arquivos fonte do projeto
SRC = ft_stack.c\
	ft_utils.c\
	ft_swap.c\
	ft_push.c\
	ft_rotate_up.c\
	ft_rotate_down.c\
	ft_ord_sort.c\
	ft_ord_sort_util.c\
    main.c

# Arquivos objeto gerados a partir dos arquivos fonte.
OBJ = $(SRC:.c=.o)

# Compilador a ser usado
CC = cc

# Flags do compilador
FLAGS = -Wall -Wextra -Werror

# Diretórios das bibliotecas LIBFT e PRINTF
LIBFT_DIR = ../libft
PRINTF_DIR = ../printf

# Nomes dos arquivos das bibliotecas
LIBFT_NAME = libft.a
PRINTF_NAME = printf.a

# Caminhos para as bibliotecas compiladas
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
PRINTF = $(PRINTF_DIR)/$(PRINTF_NAME)

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

# Declarar alvos que não são arquivos para evitar conflitos
.PHONY: all clean fclean re