/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:39:58 by rroundi           #+#    #+#             */
/*   Updated: 2025/02/23 18:39:50 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include "../solong/libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_img;
	void	*floor_img;
	void	*e_img;
	void	*c_img;
	void	*door1;
	void	*door2;
	void	*door3;
	void	*door4;
	void	*key1;
	void	*key2;
	void	*key3;
	void	*key4;
	void	*obstacle_img;
	void	*p1_img;
	void	*p2_img;
	void	*p3_img;
	void	*p4_img;
	char	**map;
	char	**map_copy;
	int		img_width;
	int		img_height;
	int		width;
	int		height;
	int		player;
	int		exitt;
	int		collec;
	int		moves;
	char	*move;
	t_point	pos;
}	t_game;

int		check_format(char *mapstring);
void	flood_fill(char **map, int height, t_point pos);
void	free_map(char **map); 
void	check_wall(char **map, int height);
char	**store_map(char *mapstring, int height);
t_point	player_pos(char **map, int height);
char	**copy_map(char **map, int height);
int		count_lines(char *mapstring);
void	check_map_content(char	**map, int height, t_game	*game);
void	validate_path(char **map, int height);
int		ft_init_game(t_game *game); // initializes the game
int		render_map(t_game *game); // renders the map
int		key_press(int keycode, t_game *game); // handle key press
int		hooks(t_game *game); // hooks for the game
int		close_window(t_game *game); // close the window
int		move_player(t_game *game, int x, int y); // move the player
void	put_string(t_game *game);
int		check_lines(char	*line,	int len, int fd, int height);
void	check_pieces(t_game	*game, char	**map);
void	count_pieces(char c, t_game *game, char **map);
char	**read_map(char **map, int fd, int height);
void	load_images(t_game	*game);
void	load_player(t_game	*game);
void	load_keys(t_game	*game);
void	player_animation(t_game	*game, int x, int y);
void	key_animation(t_game	*game, int x, int y);
void	door_animation(t_game	*game, int x, int y);
void	render_helper(t_game	*game, int x, int y);

#endif