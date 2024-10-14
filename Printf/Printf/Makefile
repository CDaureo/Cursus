NAME = ../libftprintf.a

SRC = ft_printf.c ft_put_string.c ft_putchar.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) Libft

$(NAME): $(OBJ)
	@echo "Creando Libreria estatica"
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

Libft:
	@$(MAKE) -C ../Libft

clean:
	@echo "Limpiando... (sin .a)"
	@rm -f $(OBJ)
	@echo "Entrando en Directorio libft"
	@$(MAKE) -C ../Libft clean

fclean: clean
	@echo "Limpiando..."
	@rm -f $(NAME)
	@$(MAKE) -C ../Libft fclean

re: fclean all

.PHONY: all clean fclean re Libft
