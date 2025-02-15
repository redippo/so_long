#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct  s_game
{
    void        *mlx;
    void        *mlx_win;
    void        *wall_img;
    void        *floor_img;
    void        *e_img;
    void        *c_img;
    void        *door1;
    void        *door2;
    void        *door3;
    void        *door4;
    void        *key1;
    void        *key2;
    void        *key3;
    void        *key4;
    void        *obstacle_img;
    void        *p1_img;
    void        *p2_img;
    void        *p3_img;
    void        *p4_img;
    char        **map;
    char        **map_copy;
    int         img_width;
    int         img_height;
    int         width;
    int         height;
    int         player;
    int         exitt;
    int         collec;
    int         moves;
    t_point     pos;
}               t_game;

int     check_format(char   *mapstring); // check .ber exetension
void    flood_fill(char **map, int  height, t_point pos); // checkss if it's possible to win
void    free_map(char   **map); 
void    check_wall(char     **map, int  height); // check if the map is surrounded by walls
char    **store_map(char    *mapstring, int     height);  // storing the map from the file 
t_point     player_pos(char     **map, int  height); // get the player position
char    **copy_map(char     **map, int  height); // copies the map for flood fill
int     count_lines(char    *mapstring); // count's the height of the map
void     check_map_content(char      **map, int      height, t_game     *game); // checks if the map has the right contents
void    validate_path(char     **map, int   height); // validate that there is a path for the player
int ft_init_game(t_game    *game); // initializes the game
int    render_map(t_game *game); // renders the map
int key_press(int   keycode, t_game *game); // handle key press
int hooks(t_game *game); // hooks for the game
int close_window(t_game *game); // close the window
int    move_player(t_game  *game, int x, int y); // move the player

#endif