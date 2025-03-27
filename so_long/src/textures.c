/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:27:13 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:05 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_game *game)
{
	game->moves = 1;
	game->collected = 0;
	int width;
	int height;
	game->wall = mlx_xpm_file_to_image(game->mlx,"src/textures/wall.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx,"src/textures/floor.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx,"src/textures/player_90.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx,"src/textures/exit.xpm", &width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,"src/textures/collectable.xpm", &width, &height);
	if (!game->wall || !game->floor)
    {
        printf("Error: Unloaded environment Texture\n");
        exit(1);
    }
	if (!game->player)
	{
   		 printf("Error: Unloaded Player texture\n");
		exit(1);
	}
}

void count_collectibles(t_game *game)
{
    int x, y;

    game->total_collectibles = 0;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'C') 
				game->total_collectibles++;
            x++;
        }
        y++;
    }
}
