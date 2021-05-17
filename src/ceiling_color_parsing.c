#include "../includes/cub3d.h"

static void	check_repeating(t_win *win)
{
	if (win->map->ceiling_color != -1)
		invalid_data_error(3);
}

static int	number_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static int	take_part_color(char *map, int *i)
{
	int	rgb;

	while (is_space(map[*i]))
		(*i)++;
	if (!ft_isdigit(map[*i]))
		invalid_data_error(3);
	rgb = rgb_atoi(&map[*i]);
	*i = *i + number_len(rgb);
	while (is_space(map[*i]))
		(*i)++;
	return (rgb);
}

void	ceiling_rgb_color(char *map, t_win *win)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 1;
	check_repeating(win);
	r = take_part_color(map, &i);
	if (map[i] != ',')
		invalid_data_error(3);
	i++;
	g = take_part_color(map, &i);
	if (map[i] != ',')
		invalid_data_error(3);
	i++;
	b = take_part_color(map, &i);
	if (map[i] != '\0')
		invalid_data_error(3);
	if (r < 0 || g < 0 || b < 0)
		invalid_data_error(3);
	win->map->ceiling_color = create_rgb(r, g, b);
}
