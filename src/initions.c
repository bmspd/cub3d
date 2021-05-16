#include "../includes/cub3d.h"

void	init_player(t_win *win)
{
	PLAYER = malloc(sizeof(t_player));
	if (!PLAYER)
		invalid_data_error(2);
	PLAYER->dir_x = 1;
	PLAYER->dir_y = 0;
	PLAYER->plane_x = 0;
	PLAYER->plane_y = 0.66;
	PLAYER->speed = 0.5;
}

void	init_map(t_win *win)
{
	MAP = malloc(sizeof(t_map));
	if (!MAP)
		invalid_data_error(2);
	MAP->floor_color = -1;
	MAP->ceiling_color = -1;
	MAP->map = NULL;
	MAP->sprite_number = 0;
}

void	init_ray(t_win *win)
{
	RAY = malloc(sizeof(t_ray));
	if (!RAY)
		invalid_data_error(2);
	RAY->hit = 0;
}

void	init_texture(t_win *win)
{
	WEST_T = malloc(sizeof(t_tex));
	if (!WEST_T)
		invalid_data_error(2);
	WEST_T->path = NULL;
	EAST_T = malloc(sizeof(t_tex));
	if (!EAST_T)
		invalid_data_error(2);
	EAST_T->path = NULL;
	NORTH_T = malloc(sizeof(t_tex));
	if (!NORTH_T)
		invalid_data_error(2);
	NORTH_T->path = NULL;
	SOUTH_T = malloc(sizeof(t_tex));
	if (!SOUTH_T)
		invalid_data_error(2);
	SOUTH_T->path = NULL;
}

void	init_sprite(t_win *win)
{
	SPRITE = malloc(sizeof(t_tex));
	if (!SPRITE)
		invalid_data_error(2);
	SPRITE->path = NULL;
}
