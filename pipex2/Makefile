NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/pipex.c src/process.c src/paths.c src/utils.c src/free.c src/ft_split.c src/ft_strjoin.c src/ft_strncmp.c src/ft_memcpy.c
OBJ = $(SRC:.c=.o)
INCLUDE = -I includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
