/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:49:48 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 01:38:52 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



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
	game.moves = 0;
	count_collectibles(&game);
	init_textures(&game);
	draw_map(&game);
	find_player(&game);
	mlx_hook(game.win, 17, 0, (void *)close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}