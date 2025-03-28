/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:28:57 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 01:58:32 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void draw_tile(t_game *game, int x, int y, char tile)
{
	// Establece la imagen a dibujar en función del tipo de tile
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == VOID)
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * TILE_SIZE, y * TILE_SIZE);
}

void get_map_size(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		columns = 0;
	int		rows = 0;

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
			columns = ft_strlen(line) - 1;
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
			draw_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, game->width - 100, 10, 0x808080, "Pasos: ");
	mlx_string_put(game->mlx, game->win, game->width - 40, 10, 0x808080, ft_itoa(game->moves));
	mlx_string_put(game->mlx, game->win, 10, 30, 0x808080, "Coleccionables restantes: ");
	mlx_string_put(game->mlx, game->win, 170, 30, 0x808080, ft_itoa(game->total_collectibles - game->collected));	
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
	while (line)
	{
		ft_printf("Paso %d: Línea obtenida: %s\n",i + 3, line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	
	return (map[i] = NULL, map);
}