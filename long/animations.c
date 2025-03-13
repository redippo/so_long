/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:27:00 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:35:26 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	free_images(t_game	*game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->e_img)
		mlx_destroy_image(game->mlx, game->e_img);
	if (game->door1)
		mlx_destroy_image(game->mlx, game->door1);
	if (game->door2)
		mlx_destroy_image(game->mlx, game->door2);
	if (game->door3)
		mlx_destroy_image(game->mlx, game->door3);
	if (game->door4)
		mlx_destroy_image(game->mlx, game->door4);
	if (game->key1)
		mlx_destroy_image(game->mlx, game->key1);
	if (game->p1_img)
		mlx_destroy_image(game->mlx, game->p1_img);
}
