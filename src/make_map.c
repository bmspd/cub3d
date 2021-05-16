#include "../includes/cub3d.h"

char	**make_map(t_list **head, int size)
{
	t_list	*tmp;
	char	**map;
	int		i;

	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		invalid_data_error(2);
	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (!tmp->content)
			map[i] = ft_strdup("");
		else
			map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (map);
}
