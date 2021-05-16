#include "../includes/cub3d.h"

void	calculate_variables(t_win *win, int i)
{
	SPRITEi->sprite_x = SPRITEi->x - (win->player->posx - 0.5);
	SPRITEi->sprite_y = SPRITEi->y - (win->player->posy - 0.5);
	SPRITEi->inversion_det = 1.0 / (win->player->plane_x * win->player->dir_y
			- win->player->dir_x * win->player->plane_y);
	SPRITEi->transform_x = SPRITEi->inversion_det * (win->player->dir_y
			* SPRITEi->sprite_x - win->player->dir_x * SPRITEi->sprite_y);
	SPRITEi->transform_y = SPRITEi->inversion_det
		* (-win->player->plane_y * win->spr_coords[i]->sprite_x
			+ win->player->plane_x * win->spr_coords[i]->sprite_y);
	SPRITEi->sprite_screen_x = (int)((win->width / 2)
			* (1 + SPRITEi->transform_x / SPRITEi->transform_y));
	SPRITEi->sprite_height = abs((int)(win->height / SPRITEi->transform_y)) / 2;
	SPRITEi->sprite_width = abs((int)(win->height / SPRITEi->transform_y)) / 2;
}

void	calculate_draw_xy(t_win *win, int i)
{
	SPRITEi->draw_start_y = -SPRITEi->sprite_height / 2 + win->height / 2;
	if (SPRITEi->draw_start_y < 0)
		SPRITEi->draw_start_y = 0;
	SPRITEi->draw_end_y = SPRITEi->sprite_height / 2 + win->height / 2;
	if (SPRITEi->draw_end_y >= win->height)
		SPRITEi->draw_end_y = win->height - 1;
	SPRITEi->draw_start_x = -SPRITEi->sprite_width
		/ 2 + SPRITEi->sprite_screen_x;
	if (SPRITEi->draw_start_x < 0)
		SPRITEi->draw_start_x = 0;
	SPRITEi->draw_end_x = SPRITEi->sprite_width / 2 + SPRITEi->sprite_screen_x;
	if (SPRITEi->draw_end_x >= win->width)
		SPRITEi->draw_end_x = win->width - 1;
}

void	put_rgb_pixels_y(t_win *win, int i, int stripe, int tex_x)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	y;

	y = SPRITEi->draw_start_y;
	while (y < SPRITEi->draw_end_y)
	{
		SPRITEi->d = y * SPRITE->line_length - win->height * SPRITE->line_length
			/ 2 + SPRITEi->sprite_height * SPRITE->line_length / 2;
		SPRITEi->tex_y = ((SPRITEi->d * SPRITE->tex_height)
				/ SPRITEi->sprite_height) / SPRITE->line_length;
		b = (unsigned char) SPRITE->addr[SPRITEi->tex_y * SPRITE->line_length
			+ tex_x * SPRITE->bits_per_pixel / 8];
		g = (unsigned char) SPRITE->addr[SPRITEi->tex_y * SPRITE->line_length
			+ tex_x * SPRITE->bits_per_pixel / 8 + 1];
		r = (unsigned char) SPRITE->addr[SPRITEi->tex_y * SPRITE->line_length
			+ tex_x * SPRITE->bits_per_pixel / 8 + 2];
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

	stripe = SPRITEi->draw_start_x;
	while (stripe < SPRITEi->draw_end_x)
	{
		tex_x = (int)(SPRITE->line_length * (stripe
					- (-SPRITEi->sprite_width / 2 + SPRITEi->sprite_screen_x))
				* win->sprite->tex_width / SPRITEi->sprite_width)
			/ SPRITE->line_length;
		if (SPRITEi->transform_y > 0
			&& stripe > 0
			&& stripe < win->width
			&& SPRITEi->transform_y < RAY->zbuffer[stripe])
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
		SPRITEi->sprite_distance = ((PLAYER->posx - SPRITEi->x)
				* (PLAYER->posx - SPRITEi->x) + (PLAYER->posy - SPRITEi->y)
				* (PLAYER->posy - SPRITEi->y));
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
