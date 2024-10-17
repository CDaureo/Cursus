NAME = ../libftprintf.a

SRC = ft_handle_unsigned.c ft_handle_char.c ft_handle_integer.c ft_handle_pointer.c ft_handle_string.c ft_printf.c ft_handle_hex_int_lc.c ft_handle_hex_int_uc.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creando Libreria estatica"
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
