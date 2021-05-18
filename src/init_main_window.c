#include "../includes/cub3d.h"

void	init_window(t_win **win)
{
	*win = malloc(sizeof(t_win));
	if (!(*win))
		invalid_data_error(2);
	(*win)->height = 0;
	(*win)->width = 0;
	(*win)->flag = 0;
	init_map(*win);
	init_player(*win);
	init_ray(*win);
	init_texture(*win);
	init_sprite(*win);
}
