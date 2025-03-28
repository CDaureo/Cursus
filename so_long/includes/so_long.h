/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:21:56 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 01:36:00 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "../src/gnl/get_next_line.h"
# include "../src/printf/printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# define TILE_SIZE 32
# define ESC_KEY 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define WALL 49
# define VOID 48
# define PLAYER	80
# define COLLECTIBLE 67
# define EXIT 69


typedef struct s_game
{
    void    *mlx;
    void    *win;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
	void	*player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	char	**map;
	int		collected;
	int		total_collectibles;
	int 	moves;
} t_game;

char	*get_next_line(int fd);
void	draw_map(t_game *game);
char	**load_map(char *file, int rows);
void	init_textures(t_game *game);
int		handle_keypress(int key, t_game *game);
void 	find_player(t_game *game);
void	count_collectibles(t_game *game);
int		ft_printf(char const *c, ...);
char	*ft_itoa(int n);
void	get_map_size(char *file, t_game *game);
#endif