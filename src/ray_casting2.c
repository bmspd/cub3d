#include "../includes/cub3d.h"

void	ray_calculations(t_win *win)
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
}
