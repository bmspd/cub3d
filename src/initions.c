#include "../includes/cub3d.h"

void	init_player(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (!win->player)
		invalid_data_error(2);
	win->player->dir_x = 1;
	win->player->dir_y = 0;
	win->player->plane_x = 0;
	win->player->plane_y = 0.66;
	win->player->speed = 0.1;
	win->player->rot_speed = 0.035;
}

void	init_map(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		invalid_data_error(2);
	win->map->floor_color = -1;
	win->map->ceiling_color = -1;
	win->map->map = NULL;
	win->map->sprite_number = 0;
}

void	init_ray(t_win *win)
{
	win->ray = malloc(sizeof(t_ray));
	if (!win->ray)
		invalid_data_error(2);
	win->ray->hit = 0;
}

void	init_texture(t_win *win)
{
	win->texture_west = malloc(sizeof(t_tex));
	if (!win->texture_west)
		invalid_data_error(2);
	win->texture_west->path = NULL;
	win->texture_east = malloc(sizeof(t_tex));
	if (!win->texture_east)
		invalid_data_error(2);
	win->texture_east->path = NULL;
	win->texture_north = malloc(sizeof(t_tex));
	if (!win->texture_north)
		invalid_data_error(2);
	win->texture_north->path = NULL;
	win->texture_south = malloc(sizeof(t_tex));
	if (!win->texture_south)
		invalid_data_error(2);
	win->texture_south->path = NULL;
}

void	init_sprite(t_win *win)
{
	win->sprite = malloc(sizeof(t_tex));
	if (!win->sprite)
		invalid_data_error(2);
	win->sprite->path = NULL;
}
