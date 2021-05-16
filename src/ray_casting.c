#include "../includes/cub3d.h"

void	calculate_side_dist(t_win *win)
{
	if (RAY->ray_dir_x < 0)
	{
		RAY->step_x = -1;
		RAY->side_dist_x = (PLAYER->posx - RAY->map_x)
			* RAY->delta_dist_x;
	}
	else
	{
		RAY->step_x = 1;
		RAY->side_dist_x = (RAY->map_x + 1.0 - PLAYER->posx)
			* RAY->delta_dist_x;
	}
	if (RAY->ray_dir_y < 0)
	{
		RAY->step_y = -1;
		RAY->side_dist_y = (PLAYER->posy - RAY->map_y)
			* RAY->delta_dist_y;
	}
	else
	{
		RAY->step_y = 1;
		RAY->side_dist_y = (RAY->map_y + 1.0 - PLAYER->posy)
			* RAY->delta_dist_y;
	}
}

void	dda_algorithm(t_win *win)
{
	while (RAY->hit == 0)
	{
		if (RAY->side_dist_x < RAY->side_dist_y)
		{
			RAY->side_dist_x += RAY->delta_dist_x;
			RAY->map_x += RAY->step_x;
			RAY->side = 0;
		}
		else
		{
			RAY->side_dist_y += RAY->delta_dist_y;
			RAY->map_y += RAY->step_y;
			RAY->side = 1;
		}
		if (MAP->map[RAY->map_y][RAY->map_x] != '0'
			&& MAP->map[RAY->map_y][RAY->map_x] != '2')
			RAY->hit = 1;
	}
}

void	perpendicular_wall_distance(t_win *win)
{
	if (RAY->side == 0)
		RAY->perp_wall_dist = (RAY->map_x - PLAYER->posx
				+ (1 - RAY->step_x) / 2) / RAY->ray_dir_x;
	else
		RAY->perp_wall_dist = (RAY->map_y - PLAYER->posy
				+ (1 - RAY->step_y) / 2) / RAY->ray_dir_y;
}

void	draw_pixel_lines(t_win *win, int x)
{
	RAY->line_height = (int)(win->height / RAY->perp_wall_dist);
	RAY->draw_start = -RAY->line_height / 2 + win->height / 2;
	if (RAY->draw_start < 0)
		RAY->draw_start = 0;
	RAY->draw_end = RAY->line_height / 2 + win->height / 2;
	if (RAY->draw_end >= win->height)
		RAY->draw_end = win->height - 1;
	if (RAY->side == 0)
		RAY->wall_x = PLAYER->posy + RAY->perp_wall_dist * RAY->ray_dir_y;
	else
		RAY->wall_x = PLAYER->posx + RAY->perp_wall_dist * RAY->ray_dir_x;
	RAY->wall_x -= floor((RAY->wall_x));
	if (RAY->side == 0 && RAY->ray_dir_x > 0)
		draw_texture_east(win, x);
	else if (RAY->side == 0 && RAY->ray_dir_x < 0)
		draw_texture_west(win, x);
	else if (RAY->side == 1 && RAY->ray_dir_y > 0)
		draw_texture_south(win, x);
	else
		draw_texture_north(win, x);
}

int	main_cycle(t_win *win)
{
	win->x = 0;
	win->img = mlx_new_image(win->mlx, (int)win->width, (int)win->height);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length, &win->endian);
	while (win->x < win->width)
	{
		RAY->camera_x = 2 * win->x / (double)win->width - 1;
		RAY->ray_dir_x = PLAYER->dir_x
			+ PLAYER->plane_x * RAY->camera_x;
		RAY->ray_dir_y = PLAYER->dir_y
			+ PLAYER->plane_y * RAY->camera_x;
		RAY->map_x = (int) PLAYER->posx;
		RAY->map_y = (int) PLAYER->posy;
		RAY->delta_dist_x = fabs(1 / RAY->ray_dir_x);
		RAY->delta_dist_y = fabs(1 / RAY->ray_dir_y);
		RAY->hit = 0;
		calculate_side_dist(win);
		dda_algorithm(win);
		perpendicular_wall_distance(win);
		draw_pixel_lines(win, win->x);
		draw_floor_ceiling(win, win->x);
		RAY->zbuffer[win->x++] = RAY->perp_wall_dist;
	}
	sprite_drawing(win);
	push_or_screen(win);
}
