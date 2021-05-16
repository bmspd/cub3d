#include "../includes/cub3d.h"

int	take_color_part(t_win *win, char c, int tex_x, int i)
{
	int	color_part;

	if (c == 'b')
	{
		color_part = (unsigned char) win->sprite->addr
		[win->spr_coords[i]->tex_y
			* win->sprite->line_length
			+ tex_x * win->sprite->bits_per_pixel / 8];
	}
	else if (c == 'g')
		color_part = (unsigned char) win->sprite->addr
		[win->spr_coords[i]->tex_y
			* win->sprite->line_length
			+ tex_x * win->sprite->bits_per_pixel / 8 + 1];
	else
		color_part = (unsigned char) win->sprite->addr
		[win->spr_coords[i]->tex_y
			* win->sprite->line_length
			+ tex_x * win->sprite->bits_per_pixel / 8 + 2];
	return (color_part);
}
