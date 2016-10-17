#include "../include/fillit.h"
#include "../include/libft.h"

int		nl_check(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		if ((i - (i / 21)) % 5 == 4 && z[i] != '\n')
			return (0);
		if (i != 0)
		{
			if ((i % 21) == 0 && z[i - 1] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

int		dot_hash_check(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		if ((i - (i / 21)) % 5 != 4 && z[i] != '.' && z[i] != '#'
			&& (i + 1) % 21 != 0)
			return (0);
		i++;
	}
	return (1);
}

char	*rm_nl(char *z, int num_mino)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (num_mino * 16 + 1));
	while (z[i] != '\0')
	{
		if (z[i] != '\n')
		{
			ret[j] = z[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	free(z);
	return (ret);
}

int		pre_shape_check(char *z)
{
	char	*inpt;
	int		i;
	int		ans;

	i = 0;
	while (z[i] != '\0')
	{
		if (i % 16 == 0)
		{
			inpt = ft_strdup_n(&z[i], 16);
			ans = shape_check(inpt, find_hash(inpt), 100, 0);
			if (ans != 4)
				return (0);
			ft_bzero(inpt, 16);
		}
		i++;
	}
	free(inpt);
	return (1);
}

char	*hash_to_letter(char *z)
{
	int		i;
	char	c;

	i = 0;
	c = 65;
	while (z[i] != '\0')
	{
		if (i % 16 == 0 && i != 0)
		{
			c++;
		}
		if (z[i] == '#')
			z[i] = c;
		i++;
	}
	return (z);
}
