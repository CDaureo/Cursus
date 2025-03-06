# Nombre del ejecutable
NAME = push_swap

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Archivos fuente
SRC = 	src/push_swap.c \
		src/operations/swapers/swap_a.c \
		src/operations/swapers/swap_b.c \
		src/operations/swapers/swap_ab.c \
		src/operations/pushers/push_to_a.c \
		src/operations/pushers/push_to_b.c \
		src/operations/rotators/first_to_last_a.c \
		src/operations/rotators/first_to_last_b.c \
		src/operations/rotators/first_to_last_ab.c \
		src/operations/reverseRotators/last_to_first_a.c \
		src/operations/reverseRotators/last_to_first_b.c \
		src/operations/reverseRotators/last_to_first_ab.c \
		src/utils/utlis.c \
		src/sorters/radix_sort.c \
		src/utils/validation.c
# Archivos objeto generados a partir de los fuentes
OBJ = $(SRC:.c=.o)

# Archivos de cabecera
HEADERS = includes/stack_utils.h includes/push_swap.h

# Colores para los mensajes
GREEN  = \033[32m
CYAN   = \033[36m
RED    = \033[31m
RESET  = \033[0m

# Regla principal
all: $(NAME)

# Enlazado del ejecutable
$(NAME): $(OBJ)
	@echo "$(CYAN)🔹 Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Compilation complete!$(RESET)"

# Regla para compilar archivos .c en .o
%.o: %.c $(HEADERS)
	@echo "$(CYAN)🔹 Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	@echo "$(RED)🗑 Removing object files...$(RESET)"
	@rm -f $(OBJ)

# Limpieza total
fclean: clean
	@echo "$(RED)🗑 Removing executable...$(RESET)"
	@rm -f $(NAME)

# Recompilar todo
re: fclean all

# Evitar errores con nombres de reglas que coincidan con archivos
.PHONY: all clean fclean re 
