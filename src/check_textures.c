#include "../includes/cub3d.h"

void	check_north_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (NORTH_T->path != NULL)
		invalid_data_error(3);
	i = 0;
	j = 0;
	if (str[i] == 'N' && str[i + 1] == 'O')
		i = i + 2;
	if (str[i] != ' ')
		invalid_data_error(3);
	while (str[i] == ' ')
		i++;
	len = (int)ft_strlen(&str[i]);
	NORTH_T->path = ft_calloc(len + 1, sizeof(char));
	if (!NORTH_T->path)
		invalid_data_error(2);
	while (str[i])
		NORTH_T->path[j++] = str[i++];
}

void	check_south_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (SOUTH_T->path != NULL)
		invalid_data_error(3);
	i = 0;
	j = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		i = i + 2;
	if (str[i] != ' ')
		invalid_data_error(3);
	while (str[i] == ' ')
		i++;
	len = (int)ft_strlen(&str[i]);
	SOUTH_T->path = ft_calloc(len + 1, sizeof(char));
	if (!SOUTH_T->path)
		invalid_data_error(2);
	while (str[i])
		SOUTH_T->path[j++] = str[i++];
}

void	check_west_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (WEST_T->path != NULL)
		invalid_data_error(3);
	i = 0;
	j = 0;
	if (str[i] == 'W' && str[i + 1] == 'E')
		i = i + 2;
	if (str[i] != ' ')
		invalid_data_error(3);
	while (str[i] == ' ')
		i++;
	len = (int)ft_strlen(&str[i]);
	WEST_T->path = ft_calloc(len + 1, sizeof(char));
	if (!WEST_T->path)
		invalid_data_error(2);
	while (str[i])
		WEST_T->path[j++] = str[i++];
}

void	check_east_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (EAST_T->path != NULL)
		invalid_data_error(3);
	i = 0;
	j = 0;
	if (str[i] == 'E' && str[i + 1] == 'A')
		i = i + 2;
	if (str[i] != ' ')
		invalid_data_error(3);
	while (str[i] == ' ')
		i++;
	len = (int)ft_strlen(&str[i]);
	EAST_T->path = ft_calloc(len + 1, sizeof(char));
	if (!EAST_T->path)
		invalid_data_error(2);
	while (str[i])
		EAST_T->path[j++] = str[i++];
}

void	check_sprite(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (SPRITE->path != NULL)
		invalid_data_error(3);
	i = 0;
	j = 0;
	if (str[i] == 'S')
		i = i + 1;
	if (str[i] != ' ')
		invalid_data_error(3);
	while (str[i] == ' ')
		i++;
	len = (int)ft_strlen(&str[i]);
	SPRITE->path = ft_calloc(len + 1, sizeof(char));
	if (!SPRITE->path)
		invalid_data_error(2);
	while (str[i])
		SPRITE->path[j++] = str[i++];
}
