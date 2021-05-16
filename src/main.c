#include "../includes/cub3d.h"

void	read_by_lines(int fd, t_list **head)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, 32, &line))
	{
		ft_lstadd_back(head, ft_lstnew(line));
	}
	ft_lstadd_back(head, ft_lstnew(line));
}

int	x_destroy(void)
{
	printf("Exiting from Cub3D...\n");
	exit(0);
}

void	resize_window(t_win *win)
{
	if (win->p_height < win->height)
		win->height = win->p_height;
	if (win->p_width < win->width)
		win->width = win->p_width;
}

void	open_file(int *fd, char **argv, t_list **head)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		invalid_data_error(1);
	read_by_lines(*fd, head);
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_list	*head;
	char	**map;
	int		fd;

	check_arguments(argc, argv);
	open_file(&fd, argv, &head);
	map = make_map(&head, ft_lstsize(head));
	init_window(&win);
	mlx_get_screen_size(win->win, &win->p_width, &win->p_height);
	parsing_file(map, win, ft_lstsize(head));
	win->ray->zbuffer = malloc(sizeof(double) * win->width);
	if (!(win->ray->zbuffer))
		invalid_data_error(2);
	win->mlx = mlx_init();
	make_img_textures(win);
	if (argc == 3)
		main_cycle(win);
	resize_window(win);
	win->win = mlx_new_window(win->mlx, win->width, win->height, "cub3D");
	mlx_hook(win->win, 2, 1L << 0, key_press, win);
	mlx_hook(win->win, 17, 1L < 17, x_destroy, win);
	mlx_loop_hook(win->mlx, main_cycle, win);
	mlx_loop(win->mlx);
	close(fd);
}
