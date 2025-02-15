#include "so_long.h"
#include "libft/libft.h"


int main ()
{
    t_game  game;

    game.height = count_lines("amap.ber");
    game.map = store_map("amap.ber", game.height);
    game.width = strnew(game.map[0]);
    check_wall(game.map , game.height);
    check_map_content(game.map, game.height, &game);
    game.pos = player_pos(game.map, game.height);
    game.map_copy = copy_map(game.map, game.height);
    flood_fill(game.map_copy, game.height, game.pos);
    validate_path(game.map_copy, game.height);
    if (ft_init_game(&game) == 0)
        return (1);
    render_map(&game);
    hooks(&game);

    mlx_loop(game.mlx);
}