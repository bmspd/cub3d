#include "../includes/cub3d.h"

static void	texture_direction(t_win *win, t_tex *tex)
{
	if (win->ray->side == 0 && win->ray->ray_dir_x < 0)
		tex->tex_x = tex->tex_width - tex->tex_x - 1;
	if (win->ray->side == 1 && win->ray->ray_dir_y > 0)
		tex->tex_x = tex->tex_width - tex->tex_x - 1;
}

void	draw_texture(t_win *win, int x, t_tex *tex)
{
	int	r;
	int	g;
	int	b;

	tex->tex_x = (int)(win->ray->wall_x * (double)(tex->tex_width));
	texture_direction(win, tex);
	tex->step = 1.0 * tex->tex_height /win->ray->line_height;
	tex->tex_pos = (win->ray->draw_start - win->height / 2
			+ win->ray->line_height / 2) * tex->step;
	while (win->ray->draw_start < win->ray->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (tex->tex_height - 1);
		tex->tex_pos += tex->step;
		b = (unsigned char)tex->addr[tex->tex_y * tex->line_length
			+ tex->tex_x * tex->bits_per_pixel / 8];
		g = (unsigned char)tex->addr[tex->tex_y * tex->line_length
			+ tex->tex_x * tex->bits_per_pixel / 8 + 1];
		r = (unsigned char)tex->addr[tex->tex_y * tex->line_length
			+ tex->tex_x * tex->bits_per_pixel / 8 + 2];
		my_mlx_pixel_put(win, x, win->ray->draw_start, create_rgb(r, g, b));
		win->ray->draw_start++;
	}
}
