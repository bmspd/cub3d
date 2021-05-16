#include "../includes/cub3d.h"

static int	first_render(t_win *win)
{
	win->x = 0;
	win->img = mlx_new_image(win->mlx, (int)win->width, (int)win->height);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length, &win->endian);
	while (win->x < win->width)
	{
		win->ray->camera_x = 2 * win->x / (double)win->width - 1;
		win->ray->ray_dir_x = win->player->dir_x
			+ win->player->plane_x * win->ray->camera_x;
		win->ray->ray_dir_y = win->player->dir_y
			+ win->player->plane_y * win->ray->camera_x;
		win->ray->map_x = (int) win->player->posx;
		win->ray->map_y = (int) win->player->posy;
		win->ray->delta_dist_x = fabs(1 / win->ray->ray_dir_x);
		win->ray->delta_dist_y = fabs(1 / win->ray->ray_dir_y);
		win->ray->hit = 0;
		calculate_side_dist(win);
		dda_algorithm(win);
		perpendicular_wall_distance(win);
		draw_pixel_lines(win, win->x);
		draw_floor_ceiling(win, win->x);
		win->ray->zbuffer[win->x++] = win->ray->perp_wall_dist;
	}
	sprite_drawing(win);
	return (screenshot(win));
}

int	push_or_screen(t_win *win)
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
	return (1);
}
