SRCS			= 	main.c keys.c ray_casting.c properties_parsing.c error_msg.c \
				 	rgb_atoi.c floor_color_parsing.c ceiling_color_parsing.c \
				 	map_validation.c making_copy.c draw_textures.c check_textures.c \
				 	map_parsing.c resolution_parsing.c draw_floor_ceiling.c \
				 	set_player_pos.c sprite.c draw_sprites.c screenshot.c \
				 	check_arguments.c initions.c create_rgb.c push_img_or_screenshot.c \
				 	make_img_textures.c make_map.c init_main_window.c put_pixel_to_img.c \
				 	take_color_part.c is_space.c properties_parsing2.c
DIR_S			= src
SOURCE			=$(addprefix $(DIR_S)/,$(SRCS))
OBJS			= $(SOURCE:.c=.o)
HEADER			= ./includes/cub3d.h
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I $(HEADER)

NAME			= cub3D

all:			$(NAME)

%.o:		%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				make -C ./mlx/
				make -C ./libft/
				$(CC) -o $(NAME )$@ $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft
				-mv ./mlx/libmlx.dylib ./

clean:
				$(RM) $(OBJS)
				make -C ./libft/ clean
				-mv libmlx.dylib ./mlx/
				make -C ./mlx/ clean

fclean:			clean
				$(RM) $(NAME)
				make -C ./libft/ fclean
				make -C ./mlx/ clean

re:				fclean all

.PHONY:			all clean fclean re