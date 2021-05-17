#include "../includes/cub3d.h"

int	rgb_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (nbr * sign < 0 || nbr > 255)
		return (-1);
	return ((int)(nbr * sign));
}
