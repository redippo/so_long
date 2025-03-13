NAME        = so_long
NAME_BONUS   = bonus
CC          = cc
FLAGS       = -Wall -Wextra -Werror

# Paths
# LIBFT_PATH  = libft/
# LIBFT_FILE  = libft.a
# LIBFT_LIB   = $(LIBFT_PATH)$(LIBFT_FILE)

# MLX Settings
MLX_PATH = mlx
MLX_FLAGS   = -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS   = 	long/checkmap.c long/main.c long/so_long.c long/input_handling.c long/flood.c long/helpers.c long/loader.c long/animations.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			libft/ft_itoa.c libft/ft_strncmp.c libft/ft_strlen.c libft/ft_strdup.c

SRCS_BONUS =	long_bonus/checkmap.c long_bonus/main.c long_bonus/so_long.c long_bonus/input_handling.c long_bonus/flood.c long_bonus/helpers.c long_bonus/loader.c long_bonus/animations.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
				libft/ft_itoa.c libft/ft_strncmp.c libft/ft_strlen.c libft/ft_strdup.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#.SILENT:
 all: $(NAME)


# Build libft

# Main program
$(NAME): so_long.h $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS)  $(MLX_FLAGS) -o $(NAME_BONUS)
# libft:
# 	@make -C $(LIBFT_PATH)
.c.o:
	$(CC) $(FLAGS) -c $< -o $@
#bonus 

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re