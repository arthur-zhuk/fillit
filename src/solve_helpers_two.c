#include "../include/libft.h"
#include "../include/fillit.h"

int		h_iterate_grid_coord(t_coord *coords)
{
	if (coords->x < coords->size - 1)
	{
		coords->x++;
		return (1);
	}
	else if (coords->x == coords->size - 1
		&& coords->y != coords->size - 1)
	{
		coords->x = 0;
		coords->y++;
		return (1);
	}
	else
		return (0);
}

char	*ft_strdup_n(const char *src, int n)
{
	int		i;
	char	*str;

	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i != nb)
	{
		i++;
		if (i * i == nb)
		{
			return (i);
		}
		if (i * i > nb)
		{
			return (i);
		}
	}
	return (0);
}
