/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:33:00 by rroundi           #+#    #+#             */
/*   Updated: 2025/02/23 13:27:41 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char	*mapstring)
{
	int	len;

	len = ft_strlen(mapstring);
	if (len < 4)
		return (0);
	if (ft_strncmp(&mapstring[len - 4], ".ber", 4))
		return (0);
	return (1);
}

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
			perror("Error\ninvalid map not surrounded by walls");
			free_map(map);
			exit(1);
		}
	}
	i = -1;
	while (++i < height)
	{
		if (map[i][0] != '1' || map[i][len -1] != '1')
		{
			perror("invalid map not surrounded by walls");
			free_map(map);
			exit(1); 
		}
	}
}

char	**store_map(char *mapstring, int height)
{
	int		fd;
	char	**map;

	map = malloc ((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open (mapstring, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	map = read_map(map, fd, height);
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
		perror ("file not openned");
		close (fd);
		return (0);
	}
	height = check_lines(line, len, fd, height);
	free(line);
	if (len == height)
	{
		perror("map not rectangular");
		return (0);
	}
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
