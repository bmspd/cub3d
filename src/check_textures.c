#include "../includes/cub3d.h"

void	check_north_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (win->texture_north->path != NULL)
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
	win->texture_north->path = ft_calloc(len + 1, sizeof(char));
	if (!win->texture_north->path)
		invalid_data_error(2);
	while (str[i])
		win->texture_north->path[j++] = str[i++];
}

void	check_south_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (win->texture_south->path != NULL)
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
	win->texture_south->path = ft_calloc(len + 1, sizeof(char));
	if (!win->texture_south->path)
		invalid_data_error(2);
	while (str[i])
		win->texture_south->path[j++] = str[i++];
}

void	check_west_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (win->texture_west->path != NULL)
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
	win->texture_west->path = ft_calloc(len + 1, sizeof(char));
	if (!win->texture_west->path)
		invalid_data_error(2);
	while (str[i])
		win->texture_west->path[j++] = str[i++];
}

void	check_east_texture(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (win->texture_east->path != NULL)
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
	win->texture_east->path = ft_calloc(len + 1, sizeof(char));
	if (!win->texture_east->path)
		invalid_data_error(2);
	while (str[i])
		win->texture_east->path[j++] = str[i++];
}

void	check_sprite(char *str, t_win *win)
{
	int	i;
	int	j;
	int	len;

	if (win->sprite->path != NULL)
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
	win->sprite->path = ft_calloc(len + 1, sizeof(char));
	if (!win->sprite->path)
		invalid_data_error(2);
	while (str[i])
		win->sprite->path[j++] = str[i++];
}
