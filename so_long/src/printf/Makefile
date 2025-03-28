# Variables para la librería 'libftprintf'
NAME = libftprintf.a

SRC = ft_handle_unsigned.c ft_handle_char.c ft_handle_integer.c ft_handle_pointer.c ft_handle_string.c ft_printf.c ft_handle_hex_int_lc.c ft_handle_hex_int_uc.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# Colores para la terminal
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m

# Mensajes personalizados
MSG_START = $(GREEN)[START] $(RESET)
MSG_DONE = $(BLUE)[DONE] $(RESET)
MSG_ERROR = $(RED)[ERROR] $(RESET)

# Objetivo 'all', crea la librería estática
all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

# Compilación de archivos objeto (.o)
%.o: %.c
	@echo "$(CYAN) Compilando archivo fuente $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de los archivos objeto
clean:
	@echo "$(YELLOW) Limpiando archivos objeto...$(RESET)"
	@rm -f $(OBJ)

# Limpieza total (archivos objeto y la librería)
fclean: clean
	@echo "$(YELLOW) Limpiando librería estática 'libftprintf.a'...$(RESET)"
	@rm -f $(NAME)

# Reconstrucción completa
re: fclean all

.PHONY: all clean fclean re
