#include "../includes/cub3d.h"

void	draw_floor_ceiling(t_win *win, int x)
{
	int	y;

	if (win->ray->draw_end < 0)
		win->ray->draw_end = win->height;
	y = win->ray->draw_end + 1;
	while (y < win->height)
	{
		my_mlx_pixel_put(win, x, y, win->map->floor_color);
		my_mlx_pixel_put(win, x, win->height - y - 1, win->map->ceiling_color);
		y++;
	}
}
