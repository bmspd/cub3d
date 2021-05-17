#include "../includes/cub3d.h"

void	pass_spaces_number(char *map, int *index)
{
	while (map[*index] == ' ')
		(*index)++;
	while (ft_isdigit(map[*index]))
		(*index)++;
}

void	take_resolution(char *map, t_win *win)
{
	int	i;

	i = 1;
	if (win->width > 0 && win->height > 0)
		invalid_data_error(0);
	win->width = ft_atoi(&map[i]);
	pass_spaces_number(map, &i);
	win->height = ft_atoi(&map[i]);
	pass_spaces_number(map, &i);
	while (is_space(map[i]))
		i++;
	if (map[i] != '\0')
		invalid_data_error(0);
	if (win->height <= 0 || win->width <= 0)
		invalid_data_error(0);
}
