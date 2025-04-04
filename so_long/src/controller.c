/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:51:59 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 01:57:31 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		return;
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->collected++;
		ft_printf("Collected: %d/%d\n", game->collected, game->total_collectibles);
		game->map[y][x] = VOID;
	}
	if (game->map[y][x] == EXIT)
	{
		if (game->collected == game->total_collectibles)
		{
			game->moves++;
			ft_printf("Juego terminado en %d movimientos.\n", game->moves);
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else
			return;
	}
	if (game->map[game->player_y][game->player_x] != EXIT && game->map[game->player_y][game->player_x] != COLLECTIBLE)
		game->map[game->player_y][game->player_x] = VOID;
	game->map[y][x] = PLAYER;
	game-> player_x = x;
	game-> player_y = y;
	game->moves++;
	draw_map(game);
}

void find_player(t_game *game)
{
	int x, y;

	y = 0;
	while (game->map[y])
	{
	x = 0;
	while (game->map[y][x])
	{
		if (game->map[y][x] ==  PLAYER)
		{
			game->player_x = x;
			game->player_y = y;
		return;
		}
		x++;
	}
	y++;
	}
}

int	handle_keypress(int key, t_game *game)
{
	int width;
	int height;
	if (ESC_KEY == key)
	{
		mlx_destroy_window(game->mlx,game->win);
		ft_printf("Closing game\n");
		exit(0);
	}
	else if (key == KEY_W)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "src/textures/player_90.xpm",&width, &height);
		move_player(game, game->player_x, game->player_y - 1);
	}
	else if (key == KEY_A)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "src/textures/player_180.xpm",&width, &height);
		move_player(game, game->player_x - 1, game->player_y);
	}
	else if (key == KEY_S)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "src/textures/player_270.xpm",&width, &height);
		move_player(game, game->player_x, game->player_y + 1);
	}
	else if (key == KEY_D)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "src/textures/player_0.xpm",&width, &height);
		move_player(game, game->player_x + 1, game->player_y);
	}
	return(0);
}

void count_collectibles(t_game *game)
{
	int x;
	int y;

	game->total_collectibles = 0;
	game->collected = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COLLECTIBLE) 
				game->total_collectibles++;
			x++;
		}
		y++;
	}
}
