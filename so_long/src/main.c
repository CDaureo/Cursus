/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:49:48 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 00:54:23 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void get_map_size(char *file, t_game *game)
{
	int  fd;
	char *line;
	int  columns = 0;
	int  rows = 0;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el mapa");
		exit(1);
	}
	line = get_next_line(fd);
	while ((line))
	{
		if (columns == 0)
			columns = strlen(line) - 1;
		rows++;
		line = get_next_line(fd);
	}
	close(fd);

	game->width = columns * TILE_SIZE;
	game->height = rows * TILE_SIZE;
	game->map = load_map(file, rows);
}

void draw_map(t_game *game)
{
	int x;
	int y;

	y= 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == VOID)
				mlx_put_image_to_window(game->mlx, game->win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	
}

char **load_map(char *file, int rows)
{
	int  fd;
	char *line;
	char **map;
	int  i;

	i = 0;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el mapa");
		exit(1);
	}

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	ft_printf("Paso 1: Abriendo archivo...\n");
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			perror("Error al abrir el mapa");
			exit(1);
		}
		ft_printf("Paso 2: Leyendo primera línea...\n");
		line = get_next_line(fd);
		
		ft_printf("Paso 3: Línea obtenida: %s\n", line);
	while (line)
	{
		ft_printf("Paso %d: Línea obtenida: %s\n",i + 4, line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}


int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Uso: ./so_long <mapa.ber>\n");
		return (1);
	}
		
	ft_printf("Leyendo mapa: %s\n", argv[1]);
	get_map_size(argv[1], &game);
	ft_printf("Dimensiones -> Ancho: %d px, Alto: %d px\n", game.width, game.height);

	ft_printf("Inicializando MiniLibX...\n");
	game.mlx = mlx_init();

	if (!game.mlx)
	{
		ft_printf("Error: No se pudo inicializar MiniLibX\n");
		return (1);
	}

	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");

	if (!game.win)
	{
		ft_printf("Error: No se pudo crear la ventana\n");
		return (1);
	}
	init_textures(&game);
	draw_map(&game);
	find_player(&game);
	count_collectibles(&game);
	mlx_hook(game.win, 17, 0, (void *)close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);



	return (0);
}