/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:59:04 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:37:05 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int height, t_point pos)
{
	int			len;
	t_point		up;
	t_point		down;
	t_point		left;
	t_point		right;

	len = strnew(map[0]);
	if (pos.x < 0 || pos.y < 0 || map[pos.x][pos.y] == '1' ||
		pos.x >= height || map[pos.x][pos.y] == 'F' ||
		pos.y >= len)
		return ;
	map[pos.x][pos.y] = 'F';
	up.x = pos.x - 1;
	up.y = pos.y;
	down.x = pos.x + 1;
	down.y = pos.y;
	left.x = pos.x;
	left.y = pos.y - 1;
	right.x = pos.x;
	right.y = pos.y + 1;
	flood_fill(map, height, down);
	flood_fill(map, height, right);
	flood_fill(map, height, up);
	flood_fill(map, height, left);
}

char	**copy_map(char	**map, int height)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	validate_path(char **map, int height)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = strnew(map[0]);
	while (i < height)
	{
		while (j < len)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_map(map);
				ft_putstr("error\ninvalid map no way to win");
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_map(map);
}

t_point	player_pos(char **map, int height)
{
	t_point		player;
	int			len;
	int			i;
	int			j;

	i = -1;
	len = strnew(map[0]);
	while (++i < height)
	{
		j = -1;
		while (++j < len)
		{
			if (map[i][j] == 'P')
			{
				player.x = i;
				player.y = j;
				return (player);
			}
		}
	}
	player.x = -1;
	player.y = -1;
	return (player);
}

void	validate_path1(char **map, int height, t_point pos)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = strnew(map[0]);
	while (i < height)
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	flood_fill(map, height, pos);
	validate_path(map, height);
}
