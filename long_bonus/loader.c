/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:10:10 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:36:49 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game	*game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./x/finalwal.xpm", 
			&game->img_width, &game->img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./x/background.xpm",
			&game->img_width, &game->img_height);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./x/gate.xpm", 
			&game->img_width, &game->img_height);
	game->obstacle_img = mlx_xpm_file_to_image(game->mlx, "./x/death.xpm", 
			&game->img_width, &game->img_height);
	game->door1 = mlx_xpm_file_to_image(game->mlx, "./x/exit1.xpm", 
			&game->img_width, &game->img_height);
	game->door2 = mlx_xpm_file_to_image(game->mlx, "./x/exit2.xpm", 
			&game->img_width, &game->img_height);
	game->door3 = mlx_xpm_file_to_image(game->mlx, "./x/exit3.xpm", 
			&game->img_width, &game->img_height);
	game->door4 = mlx_xpm_file_to_image(game->mlx, "./x/exit4.xpm", 
			&game->img_width, &game->img_height);
	load_player(game);
	load_keys(game);
}

void	load_keys(t_game *game)
{
	game->key1 = mlx_xpm_file_to_image(game->mlx, "./x/cle1.xpm",
			&game->img_width, &game->img_height);
	game->key2 = mlx_xpm_file_to_image(game->mlx, "./x/cle2.xpm", 
			&game->img_width, &game->img_height);
	game->key3 = mlx_xpm_file_to_image(game->mlx, "./x/cle3.xpm",
			&game->img_width, &game->img_height);
	game->key4 = mlx_xpm_file_to_image(game->mlx, "./x/cle4.xpm", 
			&game->img_width, &game->img_height);
}

void	load_player(t_game	*game)
{
	game->p1_img = mlx_xpm_file_to_image(game->mlx, "./x/player.xpm", 
			&game->img_width, &game->img_height);
	game->p2_img = mlx_xpm_file_to_image(game->mlx, "./x/player.xpm", 
			&game->img_width, &game->img_height);
	game->p3_img = mlx_xpm_file_to_image(game->mlx, "./x/player3.xpm", 
			&game->img_width, &game->img_height);
	game->p4_img = mlx_xpm_file_to_image(game->mlx, "./x/player2.xpm", 
			&game->img_width, &game->img_height);
}

void	free_map(char	**map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_putstr(char *s)
{
	int	walker;

	walker = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[walker] != '\0')
	{
		write (1, &s[walker], 1);
		walker++;
	}
	exit(1);
}
