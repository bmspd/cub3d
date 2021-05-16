#include "../includes/cub3d.h"

static int	check_res_and_colors(char **map, t_win *win)
{
	if (**map == 'R')
	{
		take_resolution(*map, win);
		return (1);
	}
	else if (**map == 'F')
	{
		floor_rgb_color(*map, win);
		return (1);
	}
	else if (**map == 'C')
	{
		ceiling_rgb_color(*map, win);
		return (1);
	}
	return (0);
}

static int	check_textures(char **map, t_win *win)
{
	if (**map == 'N' && *((*map) + 1) == 'O')
	{
		check_north_texture(*map, win);
		return (1);
	}
	else if (**map == 'S' && *((*map) + 1) == 'O')
	{
		check_south_texture(*map, win);
		return (1);
	}
	else if (**map == 'W' && *((*map) + 1) == 'E')
	{
		check_west_texture(*map, win);
		return (1);
	}
	else if (**map == 'E' && *((*map) + 1) == 'A')
	{
		check_east_texture(*map, win);
		return (1);
	}
	return (0);
}

static int	check_sprites_and_map(char **map, t_win *win, int *j, int size)
{
	if (**map == 'S')
	{
		check_sprite(*map, win);
		return (1);
	}
	else if (**map == ' ' || **map == '1' || **map == '0' || **map == '2')
	{
		map = map_parsing(win, map, j, size);
		map--;
		(*j)--;
		return (1);
	}
	return (0);
}

static int	check_properties(char **map, t_win *win, int *j, int size)
{
	if (check_res_and_colors(map, win))
		return (1);
	else if (check_textures(map, win))
		return (1);
	else if (check_sprites_and_map(map, win, j, size))
		return (1);
	return (0);
}

void	parsing_file(char **map, t_win *win, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (**map == '\0')
		{
			map++;
			j++;
			if (j == size)
				break ;
			continue ;
		}
		else if (check_properties(map, win, &j, size))
			;
		else
			invalid_data_error(3);
		map++;
		j++;
	}
	if (!win->map->map)
		invalid_data_error(3);
}
