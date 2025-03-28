# Variables para el proyecto 'so_long'
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L minilibx-linux -lmlx -lXext -lX11 -lm

# Ruta a la librería estática 'libftprintf.a'
FT_PRINTF_DIR = src/printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_OBJS = $(FT_PRINTF_DIR)/ft_handle_unsigned.o \
                 $(FT_PRINTF_DIR)/ft_handle_char.o \
                 $(FT_PRINTF_DIR)/ft_handle_integer.o \
                 $(FT_PRINTF_DIR)/ft_handle_pointer.o \
                 $(FT_PRINTF_DIR)/ft_handle_string.o \
                 $(FT_PRINTF_DIR)/ft_printf.o \
                 $(FT_PRINTF_DIR)/ft_handle_hex_int_lc.o \
                 $(FT_PRINTF_DIR)/ft_handle_hex_int_uc.o

# Archivos fuente y objetos del proyecto 'so_long'
SRCS = src/main.c src/textures.c src/controller.c src/ft_itoa.c src/maps.c \
       src/gnl/get_next_line.c src/gnl/get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)

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

# Objetivo 'all', incluye la creación de la librería
all: $(NAME)

# El objetivo 'so_long' depende de los objetos y la librería 'libftprintf.a'
$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	@echo "$(MSG_START) Compilando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FT_PRINTF_LIB) -o $(NAME)
	@echo "$(MSG_DONE) $(NAME) compilado correctamente!"

# Regla para crear la librería 'libftprintf.a' (llama al Makefile de 'libftprintf')
$(FT_PRINTF_LIB):
	@echo "$(MSG_START) $(GREEN) Creando librería estática 'libftprintf.a'..."
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(MSG_DONE) Librería 'libftprintf.a' creada!"

# Compilación de archivos objeto (.o)
%.o: %.c
	@echo "$(CYAN) Compilando archivo fuente $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de los archivos objeto de 'so_long'
clean:
	@echo "$(YELLOW) Limpiando archivos objeto de $(NAME)...$(RESET)"
	@rm -f $(OBJS)

	@echo "$(YELLOW) Limpiando archivos objeto de libftprintf.a...$(RESET)"
	@rm -f $(FT_PRINTF_OBJS)

# Limpieza total (archivos objeto y librerías)
fclean: clean
	@echo "$(YELLOW) Limpiando archivo ejecutable $(NAME) y librerías...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(FT_PRINTF_LIB)

# Reconstrucción completa
re: fclean all

.PHONY: all clean fclean re
