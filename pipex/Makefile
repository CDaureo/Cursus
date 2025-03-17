# Nombre del ejecutable ./pipex
NAME = pipex

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Sources
SRC = main.c

# Los archivos objeto generado a partir de sources

OBJS= $(SRC:.c=.o)

HEADERS = includes/pipex.h
# Colores para los mensajes
GREEN  = \033[32m
CYAN   = \033[36m
RED    = \033[31m
RESET  = \033[0m

# Regla principal
all: $(NAME)

# Enlazado del ejecutable
$(NAME): $(OBJS)
	@echo "$(CYAN)🔹 Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✅ Compilation complete!$(RESET)"

# Regla para compilar archivos .c en .o
%.o: %.c $(HEADERS)
	@echo "$(CYAN)🔹 Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	@echo "$(RED)🗑 Removing object files...$(RESET)"
	@rm -f $(OBJS)

# Limpieza total
fclean: clean
	@echo "$(RED)🗑 Removing executable...$(RESET)"
	@rm -f $(NAME)

# Recompilar todo
re: fclean all

# Evitar errores con nombres de reglas que coincidan con archivos
.PHONY: all clean fclean re 
