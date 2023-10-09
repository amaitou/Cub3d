UNAME = $(shell uname)
HEADER_FILE_MANDATORY = ./mandatory/includes/cub3d.h
HEADER_FILE_BONUS = ./bonus/includes/cub3d_bonus.h
NAME_BONUS = cub3D_bonus
NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror -O3
CFILES_MANDATORY = ./mandatory/sources/parser/reader.c \
		 ./mandatory/sources/parser/parser.c \
		 ./mandatory/sources/parser/parser_utils.c \
		 ./mandatory/sources/checker/check_reader.c \
		 ./mandatory/sources/checker/check_parser.c \
		 ./mandatory/sources/checker/checker.c \
		 ./mandatory/sources/checker/check_rgb.c \
		 ./mandatory/sources/checker/check_map.c \
		 ./mandatory/sources/checker/check_walls.c \
		 ./mandatory/sources/checker/check_spaces.c \
		 ./mandatory/sources/ray_casting/rays_casting.c \
		 ./mandatory/sources/ray_casting/ray_casting_utils.c \
		 ./mandatory/sources/ray_casting/h_intersection.c \
		 ./mandatory/sources/ray_casting/v_intersection.c \
		 ./mandatory/sources/render/projection_plan.c \
		 ./mandatory/sources/render/render_game.c \
		 ./mandatory/sources/render/render_game_utils.c \
		 ./mandatory/sources/render/textures.c \
		 ./mandatory/sources/render/textures_calculations.c \
		 ./mandatory/sources/utils/init_members.c \
		 ./mandatory/sources/utils/mlx_hooks.c \
		 ./mandatory/sources/utils/player_movements.c \
		 ./mandatory/sources/utils/split2.c \
		 ./mandatory/sources/utils/leaks.c \
		 ./mandatory/sources/utils/banner.c \
		 ./mandatory/sources/utils/game_exit.c \
		 ./mandatory/sources/displayer/displayer.c \
		 ./mandatory/sources/run_game.c \
		 ./mandatory/sources/cub3d.c

CFILES_BONUS = ./bonus/sources/parser/reader_bonus.c \
		./bonus/sources/parser/parser_bonus.c \
		./bonus/sources/parser/parser_utils_bonus.c \
		./bonus/sources/checker/check_reader_bonus.c \
		./bonus/sources/checker/check_parser_bonus.c \
		./bonus/sources/checker/checker_bonus.c \
		./bonus/sources/checker/check_rgb_bonus.c \
		./bonus/sources/checker/check_map_bonus.c \
		./bonus/sources/checker/check_walls_bonus.c \
		./bonus/sources/checker/check_spaces_bonus.c \
		./bonus/sources/ray_casting/rays_casting_bonus.c \
		./bonus/sources/ray_casting/ray_casting_utils_bonus.c \
		./bonus/sources/ray_casting/h_intersection_bonus.c \
		./bonus/sources/ray_casting/v_intersection_bonus.c \
		./bonus/sources/render/mini_map_bonus.c \
		./bonus/sources/render/projection_plan_bonus.c \
		./bonus/sources/render/render_game_bonus.c \
		./bonus/sources/render/render_game_utils_bonus.c \
		./bonus/sources/render/render_helper_bonus.c \
		./bonus/sources/render/textures_bonus.c \
		./bonus/sources/render/textures_calculations_bonus.c \
		./bonus/sources/utils/init_members_bonus.c \
		./bonus/sources/utils/mlx_hooks_bonus.c \
		./bonus/sources/utils/player_movements_bonus.c \
		./bonus/sources/utils/split2_bonus.c \
		./bonus/sources/utils/leaks_bonus.c \
		./bonus/sources/utils/banner_bonus.c \
		./bonus/sources/utils/game_exit_bonus.c \
		./bonus/sources/displayer/displayer_bonus.c \
		./bonus/sources/run_game_bonus.c \
		./bonus/sources/cub3d_bonus.c



OBJECTS_MANDATORY = $(patsubst %.c,%.o,$(CFILES_MANDATORY))
OBJECTS_BONUS = $(patsubst %.c,%.o,$(CFILES_BONUS))

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
bonus: $(SUPERLIB) $(NAME_BONUS)

$(SUPERLIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB_DIR)

$(NAME): $(OBJECTS_MANDATORY) $(HEADER_FILE_MANDATORY)
	@echo "\033[95m[.] creating *.c to cub3D mandatory\033[0m"
	@$(CC) $(CFLAGS) $(CFILES_MANDATORY) $(SUPERLIB) $(MLX) -o $@

$(NAME_BONUS): $(OBJECTS_BONUS) $(HEADER_FILE_BONUS)
	@echo "\033[95m[.] creating *.c to cub3D bonus\033[0m"
	@$(CC) $(CFLAGS) $(CFILES_BONUS) $(SUPERLIB) $(MLX) -o $@

%.o: %.c
	@echo "\033[92m[*] compiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;31m[!] deleting cub3D\033[0m"
	@$(MAKE) clean -C $(SUPERLIB_DIR)
	@rm -f $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf cub3D.dSYM
	@rm -rf cub3D_bonus.dSYM

fclean: clean
	@rm -f $(OBJECTS_MANDATORY)
	@rm -f $(OBJECTS_BONUS)
	@$(MAKE) fclean -C $(SUPERLIB_DIR)

run:
	@echo "\033[0;35m[!] running the cub3D\033[0m"
	@make && ./cub3D ./maps/valid_maps/random.cub

run_bonus:
	@echo "\033[0;35m[!] running the cub3D_bonus\033[0m"
	@make bonus && ./cub3D_bonus ./maps/valid_maps/random.cub

re: fclean all

.PHONY: all clean fclean re run run_bonus
