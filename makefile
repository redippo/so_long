NAME        = so_long
CC          = gcc
FLAGS       = -Wall -Wextra -Werror

# Paths
LIBFT_PATH  = ./libft/
LIBFT_FILE  = libft.a
LIBFT_LIB   = $(LIBFT_PATH)$(LIBFT_FILE)

# MLX Settings
MLX_PATH = mlx
MLX_FLAGS   = -Lmlx -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS        = checkmap.c main.c so_long.c input_handling.c flood.c helpers.c loader.c animations.c
OBJS        = $(SRCS:.c=.o)

# Rules
.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

# Build libft
libft:
	@echo "\nCompiling libft..."
	@make -C $(LIBFT_PATH)
	@echo "Libft compiled successfully\n"

# Main program
$(NAME): libft $(OBJS)
	@echo "\nCompiling $(NAME)..."
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully\n"

clean:
	@echo "\nCleaning object files..."
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)
	@echo "Clean completed\n"

fclean: clean
	@echo "\nRemoving executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "Full clean completed\n"

re: fclean all

.PHONY: all clean fclean re libft