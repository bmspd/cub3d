#include "../includes/cub3d.h"

void	calculate_side_dist(t_win *win)
{
	if (win->ray->ray_dir_x < 0)
	{
		win->ray->step_x = -1;
		win->ray->side_dist_x = (win->player->posx - win->ray->map_x)
			* win->ray->delta_dist_x;
	}
	else
	{
		win->ray->step_x = 1;
		win->ray->side_dist_x = (win->ray->map_x + 1.0 - win->player->posx)
			* win->ray->delta_dist_x;
	}
	if (win->ray->ray_dir_y < 0)
	{
		win->ray->step_y = -1;
		win->ray->side_dist_y = (win->player->posy - win->ray->map_y)
			* win->ray->delta_dist_y;
	}
	else
	{
		win->ray->step_y = 1;
		win->ray->side_dist_y = (win->ray->map_y + 1.0 - win->player->posy)
			* win->ray->delta_dist_y;
	}
}

void	dda_algorithm(t_win *win)
{
	while (win->ray->hit == 0)
	{
		if (win->ray->side_dist_x < win->ray->side_dist_y)
		{
			win->ray->side_dist_x += win->ray->delta_dist_x;
			win->ray->map_x += win->ray->step_x;
			win->ray->side = 0;
		}
		else
		{
			win->ray->side_dist_y += win->ray->delta_dist_y;
			win->ray->map_y += win->ray->step_y;
			win->ray->side = 1;
		}
		if (win->map->map[win->ray->map_y][win->ray->map_x] != '0'
			&& win->map->map[win->ray->map_y][win->ray->map_x] != '2')
			win->ray->hit = 1;
	}
}

void	perpendicular_wall_distance(t_win *win)
{
	if (win->ray->side == 0)
		win->ray->perp_wall_dist = (win->ray->map_x - win->player->posx
				+ (1 - win->ray->step_x) / 2) / win->ray->ray_dir_x;
	else
		win->ray->perp_wall_dist = (win->ray->map_y - win->player->posy
				+ (1 - win->ray->step_y) / 2) / win->ray->ray_dir_y;
}

void	draw_pixel_lines(t_win *win, int x)
{
	win->ray->line_height = (int)(win->height / win->ray->perp_wall_dist);
	win->ray->draw_start = -win->ray->line_height / 2 + win->height / 2;
	if (win->ray->draw_start < 0)
		win->ray->draw_start = 0;
	win->ray->draw_end = win->ray->line_height / 2 + win->height / 2;
	if (win->ray->draw_end >= win->height)
		win->ray->draw_end = win->height - 1;
	if (win->ray->side == 0)
		win->ray->wall_x = win->player->posy
			+ win->ray->perp_wall_dist * win->ray->ray_dir_y;
	else
		win->ray->wall_x = win->player->posx
			+ win->ray->perp_wall_dist * win->ray->ray_dir_x;
	win->ray->wall_x -= floor((win->ray->wall_x));
	if (win->ray->side == 0 && win->ray->ray_dir_x > 0)
		draw_texture(win, x, win->texture_east);
	else if (win->ray->side == 0 && win->ray->ray_dir_x < 0)
		draw_texture(win, x, win->texture_west);
	else if (win->ray->side == 1 && win->ray->ray_dir_y > 0)
		draw_texture(win, x, win->texture_south);
	else
		draw_texture(win, x, win->texture_north);
}

int	main_cycle(t_win *win)
{
	win->x = 0;
	win->img = mlx_new_image(win->mlx, (int)win->width, (int)win->height);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length, &win->endian);
	key_move_forward_back(win);
	key_move_sides(win);
	key_left_rotating(win);
	key_right_rotating(win);
	while (win->x < win->width)
	{
		ray_calculations(win);
		calculate_side_dist(win);
		dda_algorithm(win);
		perpendicular_wall_distance(win);
		draw_pixel_lines(win, win->x);
		draw_floor_ceiling(win, win->x);
		win->ray->zbuffer[win->x++] = win->ray->perp_wall_dist;
	}
	sprite_drawing(win);
	return (push_or_screen(win));
}
