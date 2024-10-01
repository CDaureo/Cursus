# Nombre del archivo de la librería
NAME = libft.a

# Archivos fuente
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c

OBJ = $(SRC:.c=.o)

# Compilador y flags todo junto
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regla por defecto: compilar todo y crear la librería
all: $(NAME)

# Regla para crear la librería estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Regla para compilar los archivos .o a partir de los .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJ)

# Regla para limpiar todo, incluyendo la librería
fclean: clean
	rm -f $(NAME)

# Regla para recompilar todo desde cero
re: fclean all

# Indicar que las reglas no son archivos
.PHONY: all clean fclean re