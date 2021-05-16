#include "../includes/cub3d.h"

static void	key_move_forward_back(int keycode, t_win *win)
{
	if (keycode == KEY_W)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			+ win->player->dir_x * win->player->speed)] == '0')
			win->player->posx += win->player->dir_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy + win->player->dir_y
				* win->player->speed)][(int)(win->player->posx)] == '0')
			win->player->posy += win->player->dir_y * win->player->speed;
	}
	if (keycode == KEY_S)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			- win->player->dir_x * win->player->speed)] == '0')
			win->player->posx -= win->player->dir_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy - win->player->dir_y
				* win->player->speed)][(int)(win->player->posx)] == '0')
			win->player->posy -= win->player->dir_y * win->player->speed;
	}
}

static void	key_move_sides(int keycode, t_win *win)
{
	if (keycode == KEY_D)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			+ win->player->plane_x * win->player->speed)] == '0')
			win->player->posx += win->player->plane_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy + win->player->plane_y
				* win->player->speed)][(int)win->player->posx] == '0')
			win->player->posy += win->player->plane_y * win->player->speed;
	}
	if (keycode == KEY_A)
	{
		if (win->map->map[(int)win->player->posy][(int)(win->player->posx
			- win->player->plane_x * win->player->speed)] == '0')
			win->player->posx -= win->player->plane_x * win->player->speed;
		if (win->map->map[(int)(win->player->posy - win->player->plane_y
				* win->player->speed)][(int)win->player->posx] == '0')
			win->player->posy -= win->player->plane_y * win->player->speed;
	}
}

static void	key_left_rotating(int keycode, t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == KEY_LEFT)
	{
		old_dir_x = win->player->dir_x;
		win->player->dir_x = win->player->dir_x * cos(-win->player->speed)
			- win->player->dir_y * sin(-win->player->speed);
		win->player->dir_y = old_dir_x * sin(-win->player->speed)
			+ win->player->dir_y * cos(-win->player->speed);
		old_plane_x = win->player->plane_x;
		win->player->plane_x = win->player->plane_x * cos(-win->player->speed)
			- win->player->plane_y * sin(-win->player->speed);
		win->player->plane_y = old_plane_x * sin(-win->player->speed)
			+ win->player->plane_y * cos(-win->player->speed);
	}
}

static void	key_right_rotating(int keycode, t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == KEY_RIGHT)
	{
		old_dir_x = win->player->dir_x;
		win->player->dir_x = win->player->dir_x * cos(win->player->speed)
			- win->player->dir_y * sin(win->player->speed);
		win->player->dir_y = old_dir_x * sin(win->player->speed)
			+ win->player->dir_y * cos(win->player->speed);
		old_plane_x = win->player->plane_x;
		win->player->plane_x = win->player->plane_x * cos(win->player->speed)
			- win->player->plane_y * sin(win->player->speed);
		win->player->plane_y = old_plane_x * sin(win->player->speed)
			+ win->player->plane_y * cos(win->player->speed);
	}
}

int	key_press(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		printf("Exiting from Cub3D...\n");
		exit(0);
	}
	key_move_forward_back(keycode, win);
	key_move_sides(keycode, win);
	key_left_rotating(keycode, win);
	key_right_rotating(keycode, win);
	return (0);
}
