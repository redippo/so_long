/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:27:00 by rroundi           #+#    #+#             */
/*   Updated: 2025/02/23 18:58:52 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_animation(t_game	*game, int x, int y)
{
	static int	i;

	if (i <= 10) 
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->door1, x * 32, y * 32);
	else if (i > 20 && i <= 40)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->door2, x * 32, y * 32);
	else if (i > 40 && i <= 60)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->door3, x * 32, y * 32);
	else if (i > 60 && i <= 80)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->door4, x * 32, y * 32);
	i++;
	if (i > 80)
		i = 0;
}

void	key_animation(t_game	*game, int x, int y)
{
	static int	b;

	mlx_put_image_to_window(game->mlx, game->mlx_win, 
		game->floor_img, x * 32, y * 32);
	if (b <= 30) 
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->key1, x * 32, y * 32);
	else if (b > 30 && b <= 60)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->key2, x * 32, y * 32);
	else if (b > 60 && b <= 90)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->key3, x * 32, y * 32);
	else if (b > 90 && b <= 120)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->key4, x * 32, y * 32);
	b++;
	if (b > 120)
		b = 0;
}

void	player_animation(t_game	*game, int x, int y)
{
	static int	counter;

	mlx_put_image_to_window(game->mlx, game->mlx_win, 
		game->floor_img, x * 32, y * 32);
	if (counter <= 10) 
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->p1_img, x * 32, y * 32);
	else if (counter > 10 && counter <= 20)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->p2_img, x * 32, y * 32);
	else if (counter > 20 && counter <= 30)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->p3_img, x * 32, y * 32);
	else if (counter > 30 && counter <= 40)
		mlx_put_image_to_window(game->mlx, game->mlx_win, 
			game->p4_img, x * 32, y * 32);
	counter++;
	if (counter > 40)
		counter = 0;
}
