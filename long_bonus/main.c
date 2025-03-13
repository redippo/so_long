/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:33:33 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:36:46 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.height = count_lines(argv[1]);
		game.map = store_map(argv[1], game.height);
		game.width = strnew(game.map[0]);
		check_wall(game.map, game.height);
		check_map_content(game.map, game.height, &game);
		game.pos = player_pos(game.map, game.height);
		game.map_copy = copy_map(game.map, game.height);
		game.map_copy2 = copy_map(game.map, game.height);
		flood_fill(game.map_copy, game.height, game.pos);
		validate_path(game.map_copy, game.height);
		validate_path1(game.map_copy2, game.height, game.pos);
		if (ft_init_game(&game) == 0)
			return (1);
		render_map(&game);
		hooks(&game);
		mlx_loop(game.mlx);
		free(game.mlx);
		free(game.map_copy);
		free(game.map_copy2);
		free_images(&game);
	}
}
