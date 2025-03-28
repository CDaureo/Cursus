/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:50:34 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 00:53:56 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_game *game)
{
	game->moves = 1;
	game->collected = 0;
	int width;
	int height;
	game->wall = mlx_xpm_file_to_image(game->mlx,
		"src/textures/wall.xpm",&width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx,
		"src/textures/floor.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx,
		"src/textures/player_90.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
		"src/textures/exit.xpm", &width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
		"src/textures/collectable.xpm", &width, &height);
	if (!game->wall || !game->floor)
	{
		ft_printf("Error: Unloaded environment Texture\n");
		exit(1);
	}
	if (!game->player)
	{
		ft_printf("Error: Unloaded Player texture\n");
		exit(1);
	}
}


