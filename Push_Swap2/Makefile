NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
FUN_DIR = functions
OPS_DIR = operations
PRF_DIR = printf
SRT_DIR = sorters
UTL_DIR = utils

SRC = $(SRC_DIR)/push_swap.c \
      $(FUN_DIR)/atoi.c $(FUN_DIR)/isdigit.c $(FUN_DIR)/list_add_back.c \
      $(FUN_DIR)/list_clear.c $(FUN_DIR)/list_new.c $(FUN_DIR)/list_post.c \
      $(FUN_DIR)/list_size.c $(FUN_DIR)/split.c $(FUN_DIR)/strchr.c \
	  $(FUN_DIR)/putstr.c $(FUN_DIR)/strcmp.c \
      $(OPS_DIR)/pa.c $(OPS_DIR)/pb.c $(OPS_DIR)/ra.c $(OPS_DIR)/rb.c \
      $(OPS_DIR)/rr.c $(OPS_DIR)/rra.c $(OPS_DIR)/rrb.c $(OPS_DIR)/rrr.c \
      $(OPS_DIR)/sa.c $(OPS_DIR)/sb.c \
      $(PRF_DIR)/ft_printf.c $(PRF_DIR)/ft_putchar_fd.c \
      $(PRF_DIR)/ft_putexa_fd.c $(PRF_DIR)/ft_putnbr_fd.c \
      $(PRF_DIR)/ft_putpointer_fd.c $(PRF_DIR)/ft_putstr_fd.c \
      $(PRF_DIR)/ft_putunsigned_fd.c \
      $(SRT_DIR)/ksort.c \
      $(UTL_DIR)/index.c $(UTL_DIR)/parser.c $(UTL_DIR)/validator.c

OBJ = $(SRC:.c=.o)


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
re: fclean all

.PHONY: all clean fclean re
