#include "../includes/cub3d.h"

static void	check_repeating(t_win *win)
{
	if (win->map->floor_color != -1)
		invalid_data_error(3);
}

static void	move_to_next_nbr(char *map, int *i, int flag)
{
	if (map[*i] == '+')
		(*i)++;
	while (ft_isdigit(map[*i]))
		(*i)++;
	if (flag == 1)
		return ;
	while (map[*i] == ' ')
		(*i)++;
	if (map[*i] == ',')
		(*i)++;
	while (map[*i] == ' ')
		(*i)++;
}

static int	init_color_number(char *map, int *i, int flag)
{
	int	color_letter;

	color_letter = 0;
	if (ft_isdigit(map[*i]) || map[*i] == '-' || map[*i] == '+')
		color_letter = rgb_atoi(&map[*i]);
	else
		invalid_data_error(3);
	move_to_next_nbr(map, i, flag);
	return (color_letter);
}

void	floor_rgb_color(char *map, t_win *win)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 1;
	check_repeating(win);
	while (map[i] == ' ')
		i++;
	r = init_color_number(map, &i, 0);
	g = init_color_number(map, &i, 0);
	b = init_color_number(map, &i, 1);
	while (map[i] != '\0')
	{
		if (map[i] != ' ')
			invalid_data_error(3);
		i++;
	}
	if (r < 0 || g < 0 || b < 0)
		invalid_data_error(3);
	win->map->floor_color = create_rgb(r, g, b);
}
