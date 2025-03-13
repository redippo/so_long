/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:48:20 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:36:39 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_game(t_game	*game)
{
	int	width;
	int	height;

	width = game->width * 32;
	height = game->height * 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, width, height, "mygame");
	if (!game->mlx_win)
		return (0);
	game->moves = 0;
	load_images(game);
	return (1);
}

int	render_map(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_helper(game, x, y);
			x++;
		}
		y++;
		put_string(game);
	}
	return (0);
}

void	render_helper(t_game	*game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->floor_img, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->wall_img, x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		player_animation(game, x, y);
	else if (game->map[y][x] == 'C')
		key_animation(game, x, y);
	else if (game->map[y][x] == 'E' && game->collec != 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->e_img, x * 32, y * 32);
	}
	else if (game->map[y][x] == 'O')
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->obstacle_img, x * 32, y * 32);
	else if (game->map[y][x] == 'E' && game->collec == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->floor_img, x * 32, y * 32);
		door_animation(game, x, y);
	}
}
