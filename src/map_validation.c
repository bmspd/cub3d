#include "../includes/cub3d.h"

void	map_validation(char **check_map, int size, int x, int y)
{
	if (check_map[x][y] == '1' || check_map[x][y] == 'F')
	{
		return ;
	}
	if (x == 0 || y == 0 || x == size - 1 || (check_map[x][y] != '1'
		&& check_map[x][y] != '0' &&check_map[x][y] != '2'))
		invalid_data_error(0);
	if (check_map[x][y] == '0' || check_map[x][y] == '2')
		check_map[x][y] = 'F';
	map_validation(check_map, size, x + 1, y);
	map_validation(check_map, size, x, y + 1);
	map_validation(check_map, size, x - 1, y);
	map_validation(check_map, size, x, y - 1);
	map_validation(check_map, size, x - 1, y - 1);
	map_validation(check_map, size, x - 1, y + 1);
	map_validation(check_map, size, x + 1, y - 1);
	map_validation(check_map, size, x + 1, y + 1);
}

void	zero_surround_map_check(char **check_map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (check_map[i][j] != '\0')
		{
			if (check_map[i][j] == '0' || check_map[i][j] == '2')
				map_validation(check_map, size, i, j);
			j++;
		}
		i++;
	}
}
