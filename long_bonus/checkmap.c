/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:33:00 by rroundi           #+#    #+#             */
/*   Updated: 2025/03/07 23:37:08 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall(char	**map, int height)
{
	int	len;
	int	i;

	len = strnew(map[0]);
	i = -1;
	while (++i < len)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
		{
			free_map(map);
			ft_putstr("error\nmap not surrounded by walls");
		}
	}
	i = -1;
	while (++i < height)
	{
		if (map[i][0] != '1' || map[i][len -1] != '1')
		{
			free_map(map);
			ft_putstr("error\nmap not surrounded by walls");
		}
	}
}

char	**store_map(char *mapstring, int height)
{
	int		fd;
	char	**map;

	map = malloc ((height + 1) * sizeof(char *));
	if (!map)
		exit (1);
	fd = open (mapstring, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		close (fd);
		ft_putstr("error\nfile not oppenned");
	}
	map = read_map(map, fd, height);
	close(fd);
	return (map);
}

int	count_lines(char *mapstring)
{
	char	*line;
	int		height;
	int		len;
	int		fd;

	height = 0;
	line = NULL;
	len = 0;
	fd = open(mapstring, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		ft_putstr("error\nbad file descriptor");
	}
	height = check_lines(line, len, fd, height);
	close(fd);
	if (height > 43)
		ft_putstr("error\nmap to big");
	return (height);
}

void	check_map_content(char	**map, int height, t_game *game)
{
	int	i;
	int	j;
	int	len;

	len = strnew(map[0]);
	game->player = 0;
	game->exitt = 0;
	game->collec = 0;
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < len)
		{
			count_pieces(map[i][j], game, map);
			j++;
		}
		j = 0;
		i++;
	}
	check_pieces(game, map);
}
