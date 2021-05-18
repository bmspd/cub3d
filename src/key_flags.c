#include "../includes/cub3d.h"

int	key_press(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		printf("Exiting from Cub3D...\n");
		exit(0);
	}
	if (keycode == KEY_W)
		win->flag_w = 1;
	if (keycode == KEY_S)
		win->flag_s = 1;
	if (keycode == KEY_A)
		win->flag_a = 1;
	if (keycode == KEY_D)
		win->flag_d = 1;
	if (keycode == KEY_LEFT)
		win->flag_lrot = 1;
	if (keycode == KEY_RIGHT)
		win->flag_rrot = 1;
	return (0);
}

int	key_release(int keycode, t_win *win)
{
	if (keycode == KEY_W)
		win->flag_w = 0;
	if (keycode == KEY_S)
		win->flag_s = 0;
	if (keycode == KEY_A)
		win->flag_a = 0;
	if (keycode == KEY_D)
		win->flag_d = 0;
	if (keycode == KEY_LEFT)
		win->flag_lrot = 0;
	if (keycode == KEY_RIGHT)
		win->flag_rrot = 0;
	return (0);
}

int	x_destroy(void)
{
	printf("Exiting from Cub3D...\n");
	exit(0);
}
