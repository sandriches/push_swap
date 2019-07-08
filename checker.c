/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 10:25:49 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/08 17:30:18 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_instruction(char *str, p_a *ps)
{
	if (ft_strcmp(str, "sa") == 0)
		return (swap_a(ps));
	else if (ft_strcmp(str, "sb") == 0)
		return (swap_b(ps));
	else if (ft_strcmp(str, "ss") == 0)
		return (swap_both(ps));
	else if (ft_strcmp(str, "pa") == 0)
		return (push_a(ps));
	else if (ft_strcmp(str, "pb") == 0)
		return (push_b(ps));
	else if (ft_strcmp(str, "ra") == 0)
		return (rotate_a(ps));
	else if (ft_strcmp(str, "rb") == 0)
		return (rotate_b(ps));
	else if (ft_strcmp(str, "rr") == 0)
		return (rotate_both(ps));
	else if (ft_strcmp(str, "rra") == 0)
		return (reverse_a(ps));
	else if (ft_strcmp(str, "rrb") == 0)
		return (reverse_b(ps));
	else if (ft_strcmp(str, "rrr") == 0)
		return (reverse_both(ps));
	return (0);
}

static int	mini_gnl(p_a *ps, char *line)
{
	int ret;

	ret = 1;
	while (ret > 0)
	{
		ft_bzero(line, 500);
		ret = read(1, line, 500);
		if (ret == 0)
			break ;
		line[ret - 1] = '\0';
		if (ret < 1 || check_instruction(line, ps) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (1);
}

static void	fill_arrays(p_a *ps, char **argv, int size)
{
	int x;

	ps->print_commands = 0;
	ps->a = (int *)malloc(sizeof(int) * size);
	ps->b = (int *)malloc(sizeof(int) * size);
	ps->size = size - 1;
	ps->print_stacks = 0;
	ps->ret = 0;
	x = 0;
	while (x < size - 1)
	{
		ps->a[x] = ft_atoi(argv[x + 1]);
		ps->b[x] = 0;
		x++;
	}
	ps->len_a = size - 1;
	ps->len_b = 0;
}

static int	free_everything(p_a *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps);
	return (1);
}

int			main(int argc, char **argv)
{
	char	line[500];
	p_a		*ps;
	int		*a;
	int		*b;

	if (check_errors(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ps = (p_a *)malloc(sizeof(p_a));
	fill_arrays(ps, argv, argc);
	if (mini_gnl(ps, line) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (find_unordered_ascending(ps->a, ps->len_a) == 0 && ps->len_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free_everything(ps));
}
