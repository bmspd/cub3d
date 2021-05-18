#include "../includes/cub3d.h"

void	set_north_or_south_view(t_win *win, char position, int x, int y)
{
	if (position == 'N')
	{
		win->player->dir_x = 0;
		win->player->dir_y = -1;
		win->player->plane_x = 0.66;
		win->player->plane_y = 0;
		win->player->posx = x + 0.5;
		win->player->posy = y + 0.5;
		win->map->map[y][x] = '0';
	}
	if (position == 'S')
	{
		win->player->dir_x = 0;
		win->player->dir_y = 1;
		win->player->plane_x = -0.66;
		win->player->plane_y = 0;
		win->player->posx = x + 0.5;
		win->player->posy = y + 0.5;
		win->map->map[y][x] = '0';
	}
}

void	set_west_or_east_view(t_win *win, char position, int x, int y)
{
	if (position == 'W')
	{
		win->player->dir_x = -1;
		win->player->dir_y = 0;
		win->player->plane_x = 0;
		win->player->plane_y = -0.66;
		win->player->posx = x + 0.5;
		win->player->posy = y + 0.5;
		win->map->map[y][x] = '0';
	}
	if (position == 'E')
	{
		win->player->dir_x = 1;
		win->player->dir_y = 0;
		win->player->plane_x = 0;
		win->player->plane_y = 0.66;
		win->player->posx = x + 0.5;
		win->player->posy = y + 0.5;
		win->map->map[y][x] = '0';
	}
}

void	set_player_pos(t_win *win, t_list *head, char **check_map)
{
	int	i;
	int	counter;
	int	z;

	i = 0;
	counter = 0;
	while (i < ft_lstsize(head))
	{
		z = 0;
		while (check_map[i][z])
		{
			if (check_map[i][z] == 'N' || check_map[i][z] == 'W'
				|| check_map[i][z] == 'E' || check_map[i][z] == 'S')
			{
				set_north_or_south_view(win, check_map[i][z], z, i);
				set_west_or_east_view(win, check_map[i][z], z, i);
				counter++;
				check_map[i][z] = '0';
			}
			z++;
		}
		i++;
	}
	if (counter != 1)
		invalid_data_error(3);
}
