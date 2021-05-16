#include "../includes/cub3d.h"

void	draw_texture_east(t_win *win, int x)
{
	int	r;
	int	g;
	int	b;

	EAST_T->tex_x = (int)(RAY->wall_x * (double)(EAST_T->tex_width));
	if (RAY->side == 0 && RAY->ray_dir_x > 0)
		EAST_T->tex_x = EAST_T->tex_width - EAST_T->tex_x - 1;
	if (RAY->side == 1 && RAY->ray_dir_x < 0)
		EAST_T->tex_x = EAST_T->tex_width - EAST_T->tex_x - 1;
	EAST_T->step = 1.0 * EAST_T->tex_height /RAY->line_height;
	EAST_T->tex_pos = (RAY->draw_start - win->height / 2
			+ RAY->line_height / 2) * EAST_T->step;
	while (RAY->draw_start < RAY->draw_end)
	{
		EAST_T->tex_y = (int)EAST_T->tex_pos & (EAST_T->tex_height - 1);
		EAST_T->tex_pos += EAST_T->step;
		b = (unsigned char)EAST_T->addr[EAST_T->tex_y * EAST_T->line_length
			+ EAST_T->tex_x * EAST_T->bits_per_pixel / 8];
		g = (unsigned char)EAST_T->addr[EAST_T->tex_y * EAST_T->line_length
			+ EAST_T->tex_x * EAST_T->bits_per_pixel / 8 + 1];
		r = (unsigned char)EAST_T->addr[EAST_T->tex_y * EAST_T->line_length
			+ EAST_T->tex_x * EAST_T->bits_per_pixel / 8 + 2];
		my_mlx_pixel_put(win, x, win->ray->draw_start, create_rgb(r, g, b));
		RAY->draw_start++;
	}
}

void	draw_texture_west(t_win *win, int x)
{
	int	r;
	int	g;
	int	b;

	WEST_T->tex_x = (int)(RAY->wall_x * (double)(WEST_T->tex_width));
	if (RAY->side == 0 && RAY->ray_dir_x > 0)
		WEST_T->tex_x = WEST_T->tex_width - WEST_T->tex_x - 1;
	if (RAY->side == 1 && RAY->ray_dir_x < 0)
		WEST_T->tex_x = WEST_T->tex_width - WEST_T->tex_x - 1;
	WEST_T->step = 1.0 * WEST_T->tex_height /RAY->line_height;
	WEST_T->tex_pos = (RAY->draw_start - win->height / 2
			+ RAY->line_height / 2) * WEST_T->step;
	while (RAY->draw_start < RAY->draw_end)
	{
		WEST_T->tex_y = (int)WEST_T->tex_pos & (WEST_T->tex_height - 1);
		WEST_T->tex_pos += WEST_T->step;
		b = (unsigned char)WEST_T->addr[WEST_T->tex_y * WEST_T->line_length
			+ WEST_T->tex_x * WEST_T->bits_per_pixel / 8];
		g = (unsigned char)WEST_T->addr[WEST_T->tex_y * WEST_T->line_length
			+ WEST_T->tex_x * WEST_T->bits_per_pixel / 8 + 1];
		r = (unsigned char)WEST_T->addr[WEST_T->tex_y * WEST_T->line_length
			+ WEST_T->tex_x * WEST_T->bits_per_pixel / 8 + 2];
		my_mlx_pixel_put(win, x, win->ray->draw_start, create_rgb(r, g, b));
		RAY->draw_start++;
	}
}

void	draw_texture_north(t_win *win, int x)
{
	int	r;
	int	g;
	int	b;

	NORTH_T->tex_x = (int)(RAY->wall_x * (double)(NORTH_T->tex_width));
	if (RAY->side == 0 && RAY->ray_dir_x > 0)
		NORTH_T->tex_x = NORTH_T->tex_width - NORTH_T->tex_x - 1;
	if (RAY->side == 1 && RAY->ray_dir_x < 0)
		NORTH_T->tex_x = NORTH_T->tex_width - NORTH_T->tex_x - 1;
	NORTH_T->step = 1.0 * NORTH_T->tex_height /RAY->line_height;
	NORTH_T->tex_pos = (RAY->draw_start - win->height / 2
			+ RAY->line_height / 2) * NORTH_T->step;
	while (RAY->draw_start < RAY->draw_end)
	{
		NORTH_T->tex_y = (int)NORTH_T->tex_pos & (NORTH_T->tex_height - 1);
		NORTH_T->tex_pos += NORTH_T->step;
		b = (unsigned char)NORTH_T->addr[NORTH_T->tex_y * NORTH_T->line_length
			+ NORTH_T->tex_x * NORTH_T->bits_per_pixel / 8];
		g = (unsigned char)NORTH_T->addr[NORTH_T->tex_y * NORTH_T->line_length
			+ NORTH_T->tex_x * NORTH_T->bits_per_pixel / 8 + 1];
		r = (unsigned char)NORTH_T->addr[NORTH_T->tex_y * NORTH_T->line_length
			+ NORTH_T->tex_x * NORTH_T->bits_per_pixel / 8 + 2];
		my_mlx_pixel_put(win, x, win->ray->draw_start, create_rgb(r, g, b));
		RAY->draw_start++;
	}
}

void	draw_texture_south(t_win *win, int x)
{
	int	r;
	int	g;
	int	b;

	SOUTH_T->tex_x = (int)(RAY->wall_x * (double)(SOUTH_T->tex_width));
	if (RAY->side == 0 && RAY->ray_dir_x > 0)
		SOUTH_T->tex_x = SOUTH_T->tex_width - SOUTH_T->tex_x - 1;
	if (RAY->side == 1 && RAY->ray_dir_x < 0)
		SOUTH_T->tex_x = SOUTH_T->tex_width - SOUTH_T->tex_x - 1;
	SOUTH_T->step = 1.0 * SOUTH_T->tex_height /RAY->line_height;
	SOUTH_T->tex_pos = (RAY->draw_start - win->height / 2
			+ RAY->line_height / 2) * SOUTH_T->step;
	while (RAY->draw_start < RAY->draw_end)
	{
		SOUTH_T->tex_y = (int)SOUTH_T->tex_pos & (SOUTH_T->tex_height - 1);
		SOUTH_T->tex_pos += SOUTH_T->step;
		b = (unsigned char)SOUTH_T->addr[SOUTH_T->tex_y * SOUTH_T->line_length
			+ SOUTH_T->tex_x * SOUTH_T->bits_per_pixel / 8];
		g = (unsigned char)SOUTH_T->addr[SOUTH_T->tex_y * SOUTH_T->line_length
			+ SOUTH_T->tex_x * SOUTH_T->bits_per_pixel / 8 + 1];
		r = (unsigned char)SOUTH_T->addr[SOUTH_T->tex_y * SOUTH_T->line_length
			+ SOUTH_T->tex_x * SOUTH_T->bits_per_pixel / 8 + 2];
		my_mlx_pixel_put(win, x, win->ray->draw_start, create_rgb(r, g, b));
		RAY->draw_start++;
	}
}
