#include "so_long.h"

int ft_init_game(t_game    *game)
{
    int width = game->width * 32;
    int height = game->height * 32;

    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->mlx_win = mlx_new_window(game->mlx, width, height, "mygame");
    if (!game->mlx_win)
        return (0);
    game->moves = 0;
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "./assets/finalwal.xpm", &game->img_width, &game->img_height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "./assets/background.xpm", &game->img_width, &game->img_height);
    // game->c_img = mlx_xpm_file_to_image(game->mlx, "./assets/coll.xpm", &game->img_width, &game->img_height);
    game->key1 = mlx_xpm_file_to_image(game->mlx, "./assets/cle1.xpm", &game->img_width, &game->img_height);
    game->key2 = mlx_xpm_file_to_image(game->mlx, "./assets/cle2.xpm", &game->img_width, &game->img_height);
    game->key3 = mlx_xpm_file_to_image(game->mlx, "./assets/cle3.xpm", &game->img_width, &game->img_height);
    game->key4 = mlx_xpm_file_to_image(game->mlx, "./assets/cle4.xpm", &game->img_width, &game->img_height);
    game->e_img = mlx_xpm_file_to_image(game->mlx, "./assets/gate.xpm", &game->img_width, &game->img_height);
    game->obstacle_img = mlx_xpm_file_to_image(game->mlx, "./assets/death.xpm", &game->img_width, &game->img_height);
    game->p1_img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm", &game->img_width, &game->img_height);
    game->p2_img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm", &game->img_width, &game->img_height);
    game->p3_img = mlx_xpm_file_to_image(game->mlx, "./assets/player3.xpm", &game->img_width, &game->img_height);
    game->p4_img = mlx_xpm_file_to_image(game->mlx, "./assets/player2.xpm", &game->img_width, &game->img_height);
    game->door1 = mlx_xpm_file_to_image(game->mlx, "./assets/exit1.xpm", &game->img_width, &game->img_height);
    game->door2 = mlx_xpm_file_to_image(game->mlx, "./assets/exit2.xpm", &game->img_width, &game->img_height);
    game->door3 = mlx_xpm_file_to_image(game->mlx, "./assets/exit3.xpm", &game->img_width, &game->img_height);
    game->door4 = mlx_xpm_file_to_image(game->mlx, "./assets/exit4.xpm", &game->img_width, &game->img_height);
    if (!game->wall_img)
    {
        perror("wall image not loaded");
        return (0);
    }
    return (1);
}

void    player_animation(t_game    *game, int x, int y)
{
    static int  counter;

    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x * 32, y * 32);
    if (counter <= 10) 
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->p1_img, x * 32, y * 32);
    else if (counter > 10 && counter <= 20)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->p2_img, x * 32, y * 32);
    else if (counter > 20 && counter <= 30)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->p3_img, x * 32, y * 32);
    else if (counter > 30 && counter <= 40)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->p4_img, x * 32, y * 32);   
    counter++;
    if (counter > 40)
        counter = 0;
}

void    door_animation(t_game    *game, int x, int y)
{
    static int  i;

    if (i <= 10) 
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->door1, x * 32, y * 32);
    else if (i > 20 && i <= 40)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->door2, x * 32, y * 32);
    else if (i > 40 && i <= 60)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->door3, x * 32, y * 32);
    else if (i > 60 && i <= 80)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->door4, x * 32, y * 32);   
    i++;
    if (i > 80)
        i = 0;
}

void    key_animation(t_game    *game, int x, int y)
{
    static int  b;

    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x * 32, y * 32);
    if (b <= 30) 
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->key1, x * 32, y * 32);
    else if (b > 30 && b <= 60)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->key2, x * 32, y * 32);
    else if (b > 60 && b <= 90)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->key3, x * 32, y * 32);
    else if (b > 90 && b <= 120)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->key4, x * 32, y * 32);   
    b++;
    if (b > 120)
        b = 0;
}

int    render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x * 32, y * 32);
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_img, x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                player_animation(game, x, y);
            else if (game->map[y][x] == 'C')
                key_animation(game, x, y);
                // mlx_put_image_to_window(game->mlx, game->mlx_win, game->c_img, x * 32, y * 32);
            else if (game->map[y][x] == 'E' && game->collec != 0)
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->e_img, x * 32, y * 32);
            else if (game->map[y][x] == 'O')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->obstacle_img, x * 32, y * 32);
            else if (game->map[y][x] == 'E' && game->collec == 0)
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x * 32, y * 32);
                door_animation(game, x, y);
            }
            x++;
        }
        y++;
    }
    return (0);
}
