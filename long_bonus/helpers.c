/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:30 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:37:02 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_string(t_game *game)
{
	if (game->move)
		free(game->move);
	game->move = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFF00, "MOVES ");
	mlx_string_put(game->mlx, game->mlx_win, 70, 10, 0xFFFF00, game->move);
}

int	check_lines(char	*line,	int len, int fd, int height)
{
	line = get_next_line(fd);
	if (line)
		len = strnew(line);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
		if (line && strnew(line) != len)
		{
			free(line);
			ft_putstr("error\ninvalid map form");
		}
	}
	if (len == height)
	{
		close(fd);
		ft_putstr("error\nmap not rectangular");
	}
	free(line);
	return (height);
}

void	check_pieces(t_game	*game, char	**map)
{
	if (game->player != 1 || game->exitt != 1 || game->collec <= 0)
	{
		free_map(map);
		ft_putstr("error\ninvalid map pieces");
	}
}

void	count_pieces(char c, t_game	*game, char	**map)
{
	if (c == 'P')
		game->player++;
	else if (c == 'E')
		game->exitt++;
	else if (c == 'C')
		game->collec++;
	else if (c != '1' && c != '0' && c != 'O')
	{
		free_map(map);
		ft_putstr("error\ninvalid charachter in map");
	}
}

char	**read_map(char **map, int fd, int height)
{
	int	idx;

	idx = -1;
	while (++idx < height)
	{
		map[idx] = get_next_line(fd);
		if (!map[idx])
		{
			free_map(map);
			close(fd);
			ft_putstr("error\n");
		}
	}
	map[idx] = NULL;
	close(fd);
	return (map);
}
