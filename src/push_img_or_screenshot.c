#include "../includes/cub3d.h"

static int	first_render(t_win *win)
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
	screenshot(win);
}

void	push_or_screen(t_win *win)
{
	int	differ;

	if (win->win)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	}
	else
	{
		differ = win->width % 64;
		if (win->width < 64)
			win->width = 64;
		else
			win->width = win->width + differ;
		first_render(win);
		exit(1);
	}
}
