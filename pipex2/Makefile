#Nombre del ejecutable
NAME = pipex

#Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Recursos
SRC = src/main.c src/pipex.c src/process.c src/paths.c src/utils.c src/free.c src/functions/ft_memcpy.c src/functions/ft_split.c src/functions/ft_strjoin.c src/functions/ft_strncmp.c

#Los archivos objeto a partir de los recursos
OBJS = $(SRC:.c=.o)

INCLUDE = -I includes

# Colores para los mensajes
GREEN  = \033[32m
CYAN   = \033[36m
RED    = \033[31m
RESET  = \033[0m


all: $(NAME)

# Enlazado del ejecutable
$(NAME): $(OBJS)
	@echo "$(CYAN)🔹 Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✅ Compilation complete!$(RESET)"

%.o: %.c
	@echo "$(CYAN)🔹 Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

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
