#include "../includes/cub3d.h"

void	key_move_forward_back(t_win *win)
{
	if (win->flag_w)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			+ win->player->dir_x * win->player->speed)] == '0')
			win->player->posx += win->player->dir_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy + win->player->dir_y
				* win->player->speed)][(int)(win->player->posx)] == '0')
			win->player->posy += win->player->dir_y * win->player->speed;
	}
	if (win->flag_s)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			- win->player->dir_x * win->player->speed)] == '0')
			win->player->posx -= win->player->dir_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy - win->player->dir_y
				* win->player->speed)][(int)(win->player->posx)] == '0')
			win->player->posy -= win->player->dir_y * win->player->speed;
	}
}

void	key_move_sides(t_win *win)
{
	if (win->flag_d)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			+ win->player->plane_x * win->player->speed)] == '0')
			win->player->posx += win->player->plane_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy + win->player->plane_y
				* win->player->speed)][(int)win->player->posx] == '0')
			win->player->posy += win->player->plane_y * win->player->speed;
	}
	if (win->flag_a)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			- win->player->plane_x * win->player->speed)] == '0')
			win->player->posx -= win->player->plane_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy - win->player->plane_y
				* win->player->speed)][(int)win->player->posx] == '0')
			win->player->posy -= win->player->plane_y * win->player->speed;
	}
}

void	key_left_rotating(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	if (win->flag_lrot)
	{
		old_dir_x = win->player->dir_x;
		win->player->dir_x = win->player->dir_x * cos(-win->player->rot_speed)
			- win->player->dir_y * sin(-win->player->rot_speed);
		win->player->dir_y = old_dir_x * sin(-win->player->rot_speed)
			+ win->player->dir_y * cos(-win->player->rot_speed);
		old_plane_x = win->player->plane_x;
		win->player->plane_x = win->player->plane_x
			* cos(-win->player->rot_speed)
			- win->player->plane_y * sin(-win->player->rot_speed);
		win->player->plane_y = old_plane_x
			* sin(-win->player->rot_speed)
			+ win->player->plane_y * cos(-win->player->rot_speed);
	}
}

void	key_right_rotating(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	if (win->flag_rrot)
	{
		old_dir_x = win->player->dir_x;
		win->player->dir_x = win->player->dir_x * cos(win->player->rot_speed)
			- win->player->dir_y * sin(win->player->rot_speed);
		win->player->dir_y = old_dir_x * sin(win->player->rot_speed)
			+ win->player->dir_y * cos(win->player->rot_speed);
		old_plane_x = win->player->plane_x;
		win->player->plane_x = win->player->plane_x
			* cos(win->player->rot_speed)
			- win->player->plane_y * sin(win->player->rot_speed);
		win->player->plane_y = old_plane_x * sin(win->player->rot_speed)
			+ win->player->plane_y * cos(win->player->rot_speed);
	}
}
