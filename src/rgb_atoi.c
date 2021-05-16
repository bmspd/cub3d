#include "../includes/cub3d.h"
static int	tabpass(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	rgb_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nbr;
	unsigned long	overflow;

	nbr = 0;
	sign = 1;
	i = tabpass(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (nbr * sign < 0 || nbr > 255)
		return (-1);
	return (nbr * sign);
}
