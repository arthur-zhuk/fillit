#include "../include/fillit.h"
#include "../include/libft.h"


int		nl_check(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		if ((i - (i / 21)) % 5 == 4 && z[i] != '\n')
		{
			// printf("i1: %d\n", i);
			return (0);
		}
		if ((i % 21) == 0 && z[i - 1] != '\n' && i != 0)
		{
			/*
			** >  i % 21 :index after line break. This is necessary because the
			** minos are 21 long, if we were to modulo by another number, then
			** it would be ++1 off each time we itterated.  So we do 21, then
			** compensate w z[i - 1].  An alternative would be to do
			**  i % 21 == 20 then we could use z[i].  Don't think one way is
			** better than the other.
			** >  z[i - 1] : line break index
			** >  i != 0 : this ensures that we don't throw "bad result"
			** when looking at the first character in the string, which
			** satisfies the other 2 conditions.
			*/
			// printf("i2: %d\n", i);

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
	while (	z[i] != '\0' )
	{
		if ((i - (i / 21)) % 5 != 4 && z[i] != '.' && z[i] != '#'
			&& (i + 1) % 21 != 0)
		{
			// printf("fail index: %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

// re malloc because the original malloc is going to be too big.
char	*rm_nl(char *z)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(z) + 1));
	while (z[i] != '\0')
	{
		if (z[i] != '\n')
		{
			ret[j] = z[i];
			j++;
		}
		i++;
	}
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
			inpt = ft_strdup_n(&z[i], 15);
			printf("inpt: %s, index: %d\n", inpt, find_hash(inpt));
			ans = shape_check(inpt, find_hash(inpt), 100, 0);
			// printf("ans: %d\n", ans);
			// if (ans != 4)
			// 	return (0);
			// // ft_bzero(inpt, 16);
			// printf("-------------------------------------------\n");
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
		if ((i + 1) % 21 == 0 && i != 0)
		{
			c++;
		}
		if (z[i] == '#')
			z[i] = c;
		i++;
	}
	return (z);
}

