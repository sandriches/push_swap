/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_errors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 12:51:05 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/21 14:55:36 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exists_in_big_array(char *check, char **bigarray, int size)
{
	int x;

	x = 0;
	while (x < size - 1)
	{
		if (ft_strcmp(check, bigarray[x]) == 0)
			return (1);
		x++;
	}
	return (0);
}

static int	free_dup_array(char **array, int size)
{
	int x;

	x = 0;
	size--;
	while (x < size)
	{
		free(array[x]);
		x++;
	}
	return (1);
}

static int	no_duplicates(int argc, char **argv)
{
	int		x;
	char	*bigarray[argc];

	bigarray[0] = ft_strdup(argv[1]);
	x = 2;
	while (x < argc)
	{
		if (exists_in_big_array(argv[x], bigarray, x) == 0)
			bigarray[x - 1] = ft_strdup(argv[x]);
		else
		{
			x--;
			while (x > 0)
			{
				free(bigarray[x - 1]);
				x--;
			}
			return (0);
		}
		x++;
	}
	return (free_dup_array(bigarray, x));
}

static int	args_are_integers(int argc, char **argv)
{
	int x;
	int y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		if (argv[x][0] == '-' && ft_strlen(argv[x]) > 1)
			y++;
		while (argv[x][y] != '\0')
		{
			if (argv[x][y] < 48 || argv[x][y] > 57)
				return (0);
			y++;
		}
		if (ft_fits_in_int(argv[x]) == 0)
			return (0);
		x++;
	}
	return (1);
}

int			check_errors(int argc, char **argv)
{
	if (argc < 2 || args_are_integers(argc, argv) == 0 || \
	no_duplicates(argc, argv) == 0)
		return (0);
	return (1);
}
