#include "../includes/cub3d.h"
static int	biggest_str_len(char **map, int size)
{
	int	lmax;
	int	i;
	int	current_len;

	i = 0;
	lmax = 0;
	while (i < size)
	{
		if (!map[i])
			current_len = 0;
		else
			current_len = (int)ft_strlen(map[i]);
		if (current_len > lmax)
			lmax = (int)ft_strlen(map[i]);
		i++;
	}
	return (lmax);
}

char	**make_map_copy(char **map, int size)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(size + 1, sizeof(char *));
	if (!new_map)
		invalid_data_error(2);
	i = 0;
	while (i < size)
	{
		if (!map[i])
			new_map[i] = ft_strdup("");
		else
			new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			invalid_data_error(2);
		i++;
	}
	return (new_map);
}
