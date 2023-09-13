NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror
CFILES = sources/cub3d.c \
		 sources/reader.c \
		 sources/check_reader.c \
		 sources/displayer.c \
		 sources/parser_utils.c \
		 sources/parser.c \
		 sources/leaks.c \
		 sources/errors.c \
		 sources/checker.c \
		 sources/errors_utils.c \
		 sources/map_closed.c \
		 sources/rgb_checker.c \
		 sources/cub3d_utils.c \
		 sources/mini_map.c \
		 sources/init_members.c \
		 sources/mlx_hooks.c \
		 sources/player_movements.c \
		 sources/rays.c

SUPERLIB_DIR = ./superlib
SUPERLIB = ./superlib/superlib.a
LIBS = ./mlx/build/libmlx42.a
GLFW = $(shell brew --prefix glfw)
MLX = $(LIBS) -lmlx -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib"

all: $(SUPERLIB) $(NAME)

# compile the super lib
$(SUPERLIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB_DIR)

# generate the executable file "cub3D" (Mandatory part)
$(NAME): $(CFILES)
	@echo "\033[95m[.] output *.c to cub3D\033[0m"
	@$(CC) $(CFLAGS) $(CFILES) $(SUPERLIB) $(MLX) -o $@

bonus: all $(NAME_2)

clean:
	@echo "\033[1;31m[!] deleting cub3D\033[0m"
	@$(MAKE) clean -C $(SUPERLIB_DIR)
	@rm -f $(NAME) $(NAME_2)

fclean: clean
	@rm -f $(NAME) $(NAME_2)
	@$(MAKE) fclean -C $(SUPERLIB_DIR)

run:
	make && ./cub3D ./maps/map3.cub

re: fclean all

.PHONY: all clean fclean re
