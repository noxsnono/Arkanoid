# change with $(GCC) or $(CLANG) depend system
CC = $(CLANG)

# change your includes
HEADER = includes/HEADER

# change binary name
NAME = BINARY_NAME

# add sources files
SRCS =	src/main.c \
	src/basic_functions.c \
	src/init_start.c \
	src/render_mlx/mlx_pointer_hook.c \
	src/render_mlx/mlx_pixel_image.c \
	src/render_mlx/render_scene.c \
	src/render_mlx/render_set_color.c \
	src/render_mlx/render_key_bind.c

# minilibx <> can be REMOVE
MLX = minilibx/libmlx.a
MLX_L = minilibx/libmlx_Linux.a

# Don'y modify following
GCC = gcc
CLANG = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -o3
LIB = libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft

$(MLX):
	make -C minilibx

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(MLX) $(MLX_L) -L x11 -lXext -lX11

glfw:
	cmake glfw
	make -C glfw


clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
