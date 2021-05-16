#include "../includes/cub3d.h"

void	calculate_variables(t_win *win, int i)
{
	win->spr_coords[i]->sprite_x
		= win->spr_coords[i]->x - (win->player->posx - 0.5);
	win->spr_coords[i]->sprite_y
		= win->spr_coords[i]->y - (win->player->posy - 0.5);
	win->spr_coords[i]->inversion_det
		= 1.0 / (win->player->plane_x * win->player->dir_y
			- win->player->dir_x * win->player->plane_y);
	win->spr_coords[i]->transform_x
		= win->spr_coords[i]->inversion_det * (win->player->dir_y
			* win->spr_coords[i]->sprite_x - win->player->dir_x
			* win->spr_coords[i]->sprite_y);
	win->spr_coords[i]->transform_y = win->spr_coords[i]->inversion_det
		* (-win->player->plane_y * win->spr_coords[i]->sprite_x
			+ win->player->plane_x * win->spr_coords[i]->sprite_y);
	win->spr_coords[i]->sprite_screen_x = (int)((win->width / 2)
			* (1 + win->spr_coords[i]->transform_x
				/ win->spr_coords[i]->transform_y));
	win->spr_coords[i]->sprite_height
		= abs((int)(win->height / win->spr_coords[i]->transform_y)) / 2;
	win->spr_coords[i]->sprite_width
		= abs((int)(win->height / win->spr_coords[i]->transform_y)) / 2;
}

void	calculate_draw_xy(t_win *win, int i)
{
	win->spr_coords[i]->draw_start_y
		= -win->spr_coords[i]->sprite_height / 2 + win->height / 2;
	if (win->spr_coords[i]->draw_start_y < 0)
		win->spr_coords[i]->draw_start_y = 0;
	win->spr_coords[i]->draw_end_y
		= win->spr_coords[i]->sprite_height / 2 + win->height / 2;
	if (win->spr_coords[i]->draw_end_y >= win->height)
		win->spr_coords[i]->draw_end_y = win->height - 1;
	win->spr_coords[i]->draw_start_x = -win->spr_coords[i]->sprite_width
		/ 2 + win->spr_coords[i]->sprite_screen_x;
	if (win->spr_coords[i]->draw_start_x < 0)
		win->spr_coords[i]->draw_start_x = 0;
	win->spr_coords[i]->draw_end_x
		= win->spr_coords[i]->sprite_width / 2
		+ win->spr_coords[i]->sprite_screen_x;
	if (win->spr_coords[i]->draw_end_x >= win->width)
		win->spr_coords[i]->draw_end_x = win->width - 1;
}

void	put_rgb_pixels_y(t_win *win, int i, int stripe, int tex_x)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	y;

	y = win->spr_coords[i]->draw_start_y;
	while (y < win->spr_coords[i]->draw_end_y)
	{
		win->spr_coords[i]->d
			= y * win->sprite->line_length - win->height
			* win->sprite->line_length / 2
			+ win->spr_coords[i]->sprite_height * win->sprite->line_length / 2;
		win->spr_coords[i]->tex_y
			= ((win->spr_coords[i]->d * win->sprite->tex_height)
				/ win->spr_coords[i]->sprite_height) / win->sprite->line_length;
		b = take_color_part(win, 'b', tex_x, i);
		g = take_color_part(win, 'g', tex_x, i);
		r = take_color_part(win, 'r', tex_x, i);
		color = create_rgb(r, g, b);
		if (color)
			my_mlx_pixel_put(win, stripe, y, color);
		y++;
	}
}

void	put_stripe_pixel(t_win *win, int i)
{
	int	stripe;
	int	tex_x;

	stripe = win->spr_coords[i]->draw_start_x;
	while (stripe < win->spr_coords[i]->draw_end_x)
	{
		tex_x = (int)(win->sprite->line_length
				* (stripe - (-win->spr_coords[i]->sprite_width / 2
						+ win->spr_coords[i]->sprite_screen_x))
				* win->sprite->tex_width / win->spr_coords[i]->sprite_width)
			/ win->sprite->line_length;
		if (win->spr_coords[i]->transform_y > 0
			&& stripe > 0
			&& stripe < win->width
			&& win->spr_coords[i]->transform_y < win->ray->zbuffer[stripe])
			put_rgb_pixels_y(win, i, stripe, tex_x);
		stripe++;
	}
}

void	sprite_drawing(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->map->sprite_number)
	{
		win->spr_coords[i]->sprite_distance
			= ((win->player->posx - win->spr_coords[i]->x)
				* (win->player->posx - win->spr_coords[i]->x)
				+ (win->player->posy - win->spr_coords[i]->y)
				* (win->player->posy - win->spr_coords[i]->y));
		i++;
	}
	sprite_sorting(win);
	i = 0;
	while (i < win->map->sprite_number)
	{
		calculate_variables(win, i);
		calculate_draw_xy(win, i);
		put_stripe_pixel(win, i);
		i++;
	}
}
