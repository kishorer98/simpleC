PATH_GAME = ./main/
PATH_GNL = ./GNL/
PATH_UTILS = ./UTS/
PATH_MAP = ./wmap/
PATH_MLX = ./mlx_linux/
PATH_OBJ = ./OBJ/
SRC = ./%.c

FILES = errors.c $(PATH_GAME)game_flow.c $(render.c) \
		$(PATH_GAME)init.c $(PATH_GAME)render.c $(PATH_GAME)rst.c $(PATH_GNL)get_next_line_utils.c $(PATH_GNL)get_next_line.c \
		$(PATH_MAP)config_map.c $(PATH_MAP)set_map.c $(PATH_UTILS)ft_bzero.c $(PATH_UTILS)ft_calloc.c \
		$(PATH_UTILS)ft_itoa.c $(PATH_UTILS)ft_strnstr.c

OBJS = $(patsubst $(SRC), $(PATH_OBJ)/%.o, $(FILES))

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Ilmlx -lXext -lX11 -lbsd -I $(PATH_MLX) -L $(PATH_MLX)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(OBJS) so_long.c $(MLXFLAGS) $(PATH_MLX)libmlx.a -o $(NAME)

$(PATH_OBJ)/%.o:	$(SRC)
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)main
	@mkdir -p $(PATH_OBJ)GNL
	@mkdir -p $(PATH_OBJ)wmap
	@mkdir -p $(PATH_OBJ)UTS
	$(CC) $(CFLAGS)  -I. -c $< -o $@

norm: 
	norminette wmap main GNL UTS errors.c so_long.c utils.h

clean:  
	rm -rf $(PATH_OBJ)

fclean: clean
	make clean -C $(PATH_MLX)
	rm -rf $(NAME)

re: fclean all

teste:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long
