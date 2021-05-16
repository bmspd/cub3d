#include "../includes/cub3d.h"

void	count_sprites(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (MAP->map[i])
	{
		j = 0;
		while (MAP->map[i][j])
		{
			if (MAP->map[i][j] == '2')
				MAP->sprite_number++;
			j++;
		}
		i++;
	}
}

void	placing_sprite_coordinats(t_win *win)
{
	int	i;
	int	x;
	int	y;

	win->spr_coords = malloc (sizeof(t_sprite *) * MAP->sprite_number);
	i = 0;
	x = 0;
	while (MAP->map[x])
	{
		y = 0;
		while (MAP->map[x][y])
		{
			if (MAP->map[x][y] == '2')
			{
				SPRITEi = malloc (sizeof(t_sprite));
				SPRITEi->x = y;
				SPRITEi->y = x;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	sprite_sorting(t_win *win)
{
	int			i;
	int			j;
	t_sprite	*temp;

	i = 0;
	while (i < MAP->sprite_number)
	{
		j = 0;
		while (j < MAP->sprite_number - i - 1)
		{
			if (win->spr_coords[j]->sprite_distance
				< win->spr_coords[j + 1]->sprite_distance)
			{
				temp = win->spr_coords[j + 1];
				win->spr_coords[j + 1] = win->spr_coords[j];
				win->spr_coords[j] = temp;
			}
			j++;
		}
		i++;
	}
}
