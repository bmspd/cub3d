#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define KEY_W 		13
# define KEY_A 		0
# define KEY_D		2
# define KEY_S		1
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define ESC		53

typedef struct s_player
{
	double	posx;
	double	posy;
	double	speed;
	double	rot_speed;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	*zbuffer;
}				t_ray;
typedef struct s_map
{
	char	**map;
	int		floor_color;
	int		ceiling_color;
	int		sprite_number;
}				t_map;
typedef struct s_tex{
	void	*img;
	char	*path;
	int		tex_width;
	int		tex_height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}				t_tex;

typedef struct s_sprite{
	int		x;
	int		y;
	double	sprite_distance;
	double	sprite_x;
	double	sprite_y;
	double	inversion_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_y;
	int		d;
}				t_sprite;
typedef struct s_win {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	int			p_height;
	int			p_width;
	int			x;
	int			flag;
	int 		flag_lrot;
	int 		flag_rrot;
	int			flag_w;
	int 		flag_s;
	int			flag_d;
	int 		flag_a;
	t_player	*player;
	t_ray		*ray;
	t_map		*map;
	t_tex		*texture_east;
	t_tex		*texture_west;
	t_tex		*texture_north;
	t_tex		*texture_south;
	t_tex		*sprite;
	t_sprite	**spr_coords;
}				t_win;

void	init_window(t_win **win);
void	init_player(t_win *win);
void	init_map(t_win *win);
void	init_ray(t_win *win);
void	init_texture(t_win *win);
void	init_sprite(t_win *win);

void	check_arguments(int argc, char **argv);

int		key_press(int keycode, t_win *win);

int		main_cycle(t_win *win);

void	my_mlx_pixel_put(t_win *win, int x, int y, int color);

void	parsing_file(char **map, t_win *win, int size);
void	floor_rgb_color(char *map, t_win *win);
void	ceiling_rgb_color(char *map, t_win *win);

void	take_resolution(char *map, t_win *win);

int		rgb_atoi(const char *str);

void	invalid_data_error(int type);

char	**make_map(t_list **head, int size);
char	**make_map_copy(char **map, int size);
void	zero_surround_map_check(char **check_map, int size);

char	**map_parsing(t_win *win, char **map, int *j, int size);
void	map_validation(char **map, int size, int x, int y);
void	set_player_pos(t_win *win, t_list *head, char **check_map);

int		take_color_part(t_win *win, char c, int tex_x, int i);
void	draw_floor_ceiling(t_win *win, int x);

void	check_north_texture(char *str, t_win *win);
void	check_south_texture(char *str, t_win *win);
void	check_west_texture(char *str, t_win *win);
void	check_east_texture(char *str, t_win *win);
void	check_sprite(char *str, t_win *win);

void	count_sprites(t_win *win);
void	placing_sprite_coordinats(t_win *win);
void	sprite_sorting(t_win *win);
void	sprite_drawing(t_win *win);

int		create_rgb(int r, int g, int b);

int		push_or_screen(t_win *win);

int		screenshot(t_win *win);

void	make_img_textures(t_win *win);

void	draw_texture(t_win *win, int x, t_tex *tex);

void	calculate_side_dist(t_win *win);
void	dda_algorithm(t_win *win);
void	perpendicular_wall_distance(t_win *win);
void	draw_pixel_lines(t_win *win, int x);

int		check_empty_string(char *string, t_win *win);

int 	is_space(char c);

void 	pass_tabs(char **string, t_win *win);

int 	key_release(int keycode, t_win *win);
void	key_move_forward_back(t_win *win);
void	key_move_sides(t_win *win);
void	key_left_rotating(t_win *win);
void	key_right_rotating(t_win *win);
void	ray_calculations(t_win *win);
int	x_destroy(void);
#endif