#include "../includes/cub3d.h"

int	check_empty_string(char *string, t_win *win)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!is_space(string[i]))
			return (0);
		i++;
	}
	if (win->height != 0 && win->width != 0
		&& win->map->floor_color != -1 && win->map->ceiling_color != -1
		&& win->texture_east->path && win->texture_north->path
		&& win->texture_south->path && win->texture_west->path
		&& win->sprite->path)
		return (1);
	return (0);
}

void	pass_tabs(char **string, t_win *win)
{
	while (is_space(**string) && (win->height == 0
			|| win->width == 0 || win->map->floor_color == -1
			|| win->map->ceiling_color == -1 || !win->texture_east->path
			|| !win->texture_west->path || !win->texture_south->path
			|| !win->texture_north->path || !win->sprite->path))
	{
		(*string)++;
	}
}
