#include "../so_long/libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>

int     check_format(char   *mapstring)
{
    int len;

    len = ft_strlen(mapstring);
    if (len < 4)
        return (0);
    if (ft_strncmp(&mapstring[len - 4], ".ber", 4))
    {
        perror("invalid map file");
        return (0);
    }
    return (1);
}

void    flood_fill(char **map, int  height, t_point pos)
{
    t_point     up;
    t_point     down;
    t_point     left;
    t_point     right;
    int         len;

    len = strnew(map[0]);
    if (pos.x < 0 || pos.y < 0 || map[pos.x][pos.y] == '1' ||
    pos.x >= height || map[pos.x][pos.y] == 'F' || pos.y >= len)
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
    flood_fill(map , height, up);
    flood_fill(map , height, down);
    flood_fill(map , height, right);
    flood_fill(map , height, left);
}

void    free_map(char   **map)
{
    int     i;

    i = 0;
    if (!map)
        return ;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void    check_wall(char     **map, int  height)
{
    int len;
    int i;

    len = strnew(map[0]);
    i = 0;
    while (i < len)
    {
        if (map[0][i] != '1' || map[height - 1][i] != '1')
        {
            perror("invalid map not surrounded by walls");
            free_map(map);
            exit(1);
        }
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (map[i][0] != '1' || map[i][len -1] != '1')
        {
            perror("invalid map not surrounded by walls");
            free_map(map);
            exit(1); 
        }
        i++;
    }
}

char    **store_map(char    *mapstring, int     height)
{
    int     fd;
    char    **map;
    int     idx;

    map = malloc ((height + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    fd = open (mapstring, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return (NULL);
    }
    idx = 0;
    while (idx < height)
    {
       map[idx] = get_next_line(fd);
       if (!map[idx])
       {
        free_map(map);
        close(fd);
        return (NULL);
       }
       idx++;
    }
    map[idx] = NULL;
    close(fd);
    return (map);
}

t_point     player_pos(char     **map, int  height)
{
    int         len;
    t_point     player;
    int         i;
    int         j;

    j = 0;
    i = 0;
    len = strnew(map[0]);
    while (i < height)
    {
        while (j < len)
        {
            if (map[i][j] == 'P')
            {
                player.x = i;
                player.y = j;
                return (player);
            }
            j++;
        }
        j = 0;
        i++;
    }
    player.x = -1;
    player.y = -1;
    return (player);
}

char    **copy_map(char     **map, int  height)
{
    int     i;
    char    **map_copy;

    i = 0;
    map_copy = malloc((height + 1) * sizeof(char    *));
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
int     count_lines(char    *mapstring)
{
    int height;
    int len;
    int fd;
    char    *line;

    height = 0;
    fd = open(mapstring , O_RDONLY);
    if (fd < 0)
    {
        perror ("file not openned");
        return (0);
    }
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
            perror("invalid mapp");
            free(line);
            exit(1);
        }
    }
    free(line);
    if (len == height)
    {
        perror("map not rectangular");
        return (0);
    }
    return (height);
}

void     check_map_content(char      **map, int      height, t_game *game)
{
    int     i;
    int     j;
    int     len;

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
            if (map[i][j] == 'P')
                game->player++;
            else if (map[i][j] == 'E')
                game->exitt++;
            else if (map[i][j] == 'C')
                game->collec++;
            else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'O')
            {
                perror("invalid charachter in map");
                free_map(map);
                exit(1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    if (game->player != 1 || game->exitt != 1 || game->collec <= 0)
    {
        perror("invalid map pieces");
        free_map(map);
        exit(1);
    }
}

void    validate_path(char     **map, int   height)
{
    int     i;
    int     len;
    int     j;

    i = 0;
    j = 0;
    len = strnew(map[0]);
    while (i < height)
    {
        while (j < len)

        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
            {
                perror("invalid map no way to win");
                free_map(map);
                exit(1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    free_map(map);
}

// int main ()
// {
//     int d = 0;
//     int  i = count_lines("amap.ber");
//     // printf("%d",i);
//     char **map = store_map("amap.ber", i);
//     check_wall(map , i);
//     check_map_content(map, i);
//     t_point player = player_pos(map, i);

//     char    **map_copy;
//     map_copy = copy_map(map, i);
//     while (d < i)
//     {
//         printf("%s\n",map_copy[d]);
//         d++;
//     }
//     flood_fill(map_copy, i, player);
//     d = 0;
//     printf("--------------\n");
//     while (d < i)
//     {
//         printf("%s\n",map_copy[d]);
//         d++;
//     }
//     validate_path(map_copy, i);
//     // int i = check_format("amap.ber");
//     // printf("%d", i);
// }