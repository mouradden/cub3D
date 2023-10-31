libft=libft/libft.a

NAME	= cub3D
NAME_B	= cub3D_bonus

CC		:= cc
FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -O3 -Ofast -flto #-fsanitize=address -g
LIBMLX	:= /Users/$(USER)/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw  -pthread -lm #-L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib" 

INCLUDES = -I $(LIBMLX)/include


SRC= mandatory/cub3d.c\
get_next_line/get_next_line.c\
mandatory/parsing/check_map/characters.c mandatory/parsing/check_map/empty_zero_one.c mandatory/parsing/check_map/newlines.c mandatory/parsing/check_map/surronded.c\
mandatory/parsing/final_parse/store_colors.c mandatory/parsing/final_parse/store_map.c mandatory/parsing/final_parse/store_pictures.c mandatory/parsing/final_parse/store_player.c mandatory/parsing/final_parse/to_raycasting.c\
mandatory/parsing/six_characters/colors.c mandatory/parsing/six_characters/colors_.c mandatory/parsing/six_characters/existance.c mandatory/parsing/six_characters/path.c\
mandatory/parsing/others/free.c mandatory/parsing/others/read_map.c mandatory/parsing/others/split.c mandatory/parsing/others/string.c\
mandatory/game/build.c mandatory/game/draw.c mandatory/game/move.c mandatory/game/init_data.c\
mandatory/game/ray_casting/ray_cast.c mandatory/game/ray_casting/get_inters_horizontals.c mandatory/game/ray_casting/get_inters_verticals.c\
mandatory/game/build_3d.c mandatory/game/render_texture.c \
mandatory/game/clearing.c mandatory/game/utils.c \
mandatory/parsing/others/freee.c\

SRC_BONUS = bonus/cub3d_bonus.c \
get_next_line/get_next_line.c\
bonus/parsing/check_map/characters.c bonus/parsing/check_map/empty_zero_one.c bonus/parsing/check_map/newlines.c bonus/parsing/check_map/surronded.c\
bonus/parsing/final_parse/store_colors.c bonus/parsing/final_parse/store_map.c bonus/parsing/final_parse/store_pictures.c bonus/parsing/final_parse/store_player.c bonus/parsing/final_parse/to_raycasting.c\
bonus/parsing/six_characters/colors.c bonus/parsing/six_characters/existance.c bonus/parsing/six_characters/path.c\
bonus/parsing/others/free.c bonus/parsing/others/read_map.c bonus/parsing/others/split.c bonus/parsing/others/string.c\
bonus/game/build_bonus.c bonus/game/draw_bonus.c bonus/game/move_bonus.c bonus/game/init_data_bonus.c\
bonus/game/ray_casting_bonus/ray_cast.c bonus/game/ray_casting_bonus/get_inters_horizontals.c bonus/game/ray_casting_bonus/get_inters_verticals.c\
bonus/game/build_3d_bonus.c bonus/game/render_texture_bonus.c\
bonus/game/clearing_bonus.c bonus/game/utils_bonus.c  bonus/game/mouse_hook.c\
bonus/parsing/six_characters/colors_.c\
bonus/parsing/others/freee.c\
bonus/game/animation_bonus.c\

OBJ=$(SRC:.c=.o)

OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)

bonus : $(NAME_B)

$(NAME_B): ${OBJ_BONUS} $(libft)
	${CC} ${FLAGS} ${OBJ_BONUS} $(INCLUDES) $(libft) $(LIBS) -o $(NAME_B)

$(libft):
	make -C libft

$(NAME): $(OBJ) $(libft)
	$(CC) $(FLAGS) $(INCLUDES) $(libft) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ) ${OBJ_BONUS}


fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean  all

.PHONY: all clean fclean re bonus
