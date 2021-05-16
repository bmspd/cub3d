#include "../includes/cub3d.h"

static void	check_all(t_win *win)
{
	if (win->height == 0 || win->width == 0 || win->map->floor_color == -1
		|| win->map->ceiling_color == -1 || !win->texture_east->path
		|| !win->texture_west->path || !win->texture_south->path
		|| !win->texture_north->path || !win->sprite->path)
	{
		invalid_data_error(3);
	}
}

static void	check_map_symbols(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map->map[i])
	{
		j = 0;
		while (win->map->map[i][j])
		{
			if (win->map->map[i][j] != '0' && win->map->map[i][j] != '1'
			&& win->map->map[i][j] != '2' && win->map->map[i][j] != 'N'
			&& win->map->map[i][j] != 'W' && win->map->map[i][j] != 'E'
			&& win->map->map[i][j] != 'S')
			{
				invalid_data_error(3);
			}
			j++;
		}
		i++;
	}
}

static void	free_unnecessary(t_list *head, char **check_map)
{
	int	z;
	int	k;

	z = ft_lstsize(head);
	k = 0;
	while (k < z)
	{
		free(check_map[k]);
		k++;
	}
	free(check_map);
	ft_lstclear(&head, free);
}

char	**map_parsing(t_win *win, char **map, int *j, int size)
{
	char	**check_map;
	int		i;
	t_list	*head;

	head = NULL;
	check_all(win);
	i = 0;
	size = size - *j;
	while (i < size)
	{
		ft_lstadd_back(&head, ft_lstnew(*map));
		map++;
		(*j)++;
		i++;
	}
	ft_lstadd_back(&head, ft_lstnew(*map));
	win->map->map = make_map(&head, ft_lstsize(head));
	check_map_symbols(win);
	check_map = make_map_copy(win->map->map, ft_lstsize(head));
	set_player_pos(win, head, check_map);
	count_sprites(win);
	placing_sprite_coordinats(win);
	zero_surround_map_check(check_map, ft_lstsize(head));
	free_unnecessary(head, check_map);
	return (map);
}
