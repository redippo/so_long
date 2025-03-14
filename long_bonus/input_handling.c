/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:13:55 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:36:55 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game	*game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	else if (keycode == 13 || keycode == 126)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 125)
		move_player(game, 1, 0);
	else if (keycode == 123 || keycode == 0)
		move_player(game, 0, -1);
	else if (keycode == 124 || keycode == 2)
		move_player(game, 0, 1);
	return (0);
}

int	hooks(t_game	*game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, close_window, game);
	mlx_loop_hook(game->mlx, render_map, game);
	return (0);
}

int	close_window(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

int	move_player(t_game *game, int x, int y)
{
	int	n_x;
	int	n_y;

	n_x = game->pos.x + x;
	n_y = game->pos.y + y;
	if ((game->map[n_x][n_y] == 'E' && game->collec == 0) || 
	game->map[n_x][n_y] == 'O')
		close_window(game);
	else if (game->map[n_x][n_y] == '1')
		return (0);
	else if (game->map[n_x][n_y] == 'E' && game->collec != 0)
		return (0);
	else if (game->map[n_x][n_y] == 'C')
	{
		game->collec--;
		game->map[n_x][n_y] = '0';
	}
	game->map[game->pos.x][game->pos.y] = '0';
	game->pos.x = n_x;
	game->pos.y = n_y;
	game->map[game->pos.x][game->pos.y] = 'P';
	game->moves++;
	return (0);
}
