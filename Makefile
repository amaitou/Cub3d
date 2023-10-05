UNAME = $(shell uname)
HEADER_FILE = ./includes/cub3d.h
NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror -O3
CFILES = sources/parser/reader.c \
		 sources/parser/parser.c \
		 sources/parser/parser_utils.c \
		 sources/checker/check_reader.c \
		 sources/checker/check_parser.c \
		 sources/checker/checker.c \
		 sources/checker/check_rgb.c \
		 sources/checker/check_map.c \
		 sources/checker/check_walls.c \
		 sources/checker/check_spaces.c \
		 sources/ray_casting/rays_casting.c \
		 sources/ray_casting/ray_casting_utils.c \
		 sources/ray_casting/h_intersection.c \
		 sources/ray_casting/v_intersection.c \
		 sources/render/mini_map.c \
		 sources/render/projection_plan.c \
		 sources/render/render_game.c \
		 sources/render/render_game_utils.c \
		 sources/render/render_helper.c \
		 sources/render/textures.c \
		 sources/render/textures_calculations.c \
		 sources/utils/init_members.c \
		 sources/utils/mlx_hooks.c \
		 sources/utils/player_movements.c \
		 sources/utils/split2.c \
		 sources/utils/leaks.c \
		 sources/utils/banner.c \
		 sources/displayer/displayer.c \
		 sources/run_game.c \
		 sources/cub3d.c

OBJECTS = $(patsubst %.c,%.o,$(CFILES))

SUPERLIB_DIR = ./superlib
SUPERLIB = ./superlib/superlib.a
LIBS = ./mlx/build/libmlx42.a

ifeq ($(UNAME), Darwin)
	GLFW = $(shell brew --prefix glfw)
	MLX = $(LIBS) -lmlx -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib"
endif

ifeq ($(UNAME), Linux)
	MLX = $(LIBS) -Iinclude -ldl -lglfw -pthread -lm 
endif

all: $(SUPERLIB) $(NAME)

# compile the super lib
$(SUPERLIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB_DIR)

# generate the executable file "cub3D" (Mandatory part)
$(NAME): $(OBJECTS) $(HEADER_FILE)
	@echo "\033[95m[.] creating *.c to cub3D\033[0m"
	@$(CC) $(CFLAGS) $(CFILES) $(SUPERLIB) $(MLX) -o $@

%.o: %.c
	@echo "\033[92m[*] compiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;31m[!] deleting cub3D\033[0m"
	@$(MAKE) clean -C $(SUPERLIB_DIR)
	@rm -f $(NAME)
	@rm -rf cub3D.dSYM

fclean: clean
	@rm -f $(NAME) $(OBJECTS)
	@$(MAKE) fclean -C $(SUPERLIB_DIR)

run:
	@echo "\033[0;35m[!] running the cub3D\033[0m"
	@make && ./cub3D ./maps/valid_maps/random.cub

re: fclean all

.PHONY: all clean fclean re run
