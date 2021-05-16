#include "../includes/cub3d.h"
static void	make_img_tex(t_win *win, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(win->mlx,
			tex->path, &tex->tex_width, &tex->tex_height);
	if (tex->img == NULL)
		invalid_data_error(3);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

void	make_img_textures(t_win *win)
{
	make_img_tex(win, EAST_T);
	make_img_tex(win, WEST_T);
	make_img_tex(win, SOUTH_T);
	make_img_tex(win, NORTH_T);
	make_img_tex(win, SPRITE);
}
