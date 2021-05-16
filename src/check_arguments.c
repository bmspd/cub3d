#include "../includes/cub3d.h"

void	check_arguments(int argc, char **argv)
{
	size_t	i;

	if (argc == 1 || argc > 3)
	{
		invalid_data_error(1);
	}
	else if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		while (i > 0)
		{
			if (argv[1][i] == '.')
				break ;
			i--;
		}
		if (i == 0)
			invalid_data_error(1);
		if (ft_strncmp(&argv[1][i], ".cub", 4))
			invalid_data_error(1);
	}
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		invalid_data_error(1);
	else
		return ;
}
