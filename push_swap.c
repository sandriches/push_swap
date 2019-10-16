/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:25:28 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/23 19:17:33 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps		*create_struct(int argc, char **argv)
{
	t_ps	*ps;
	int		x;

	ps = (t_ps *)malloc(sizeof(t_ps));
	ps->a = (int *)malloc(sizeof(int) * argc);
	ps->b = (int *)malloc(sizeof(int) * argc);
	ps->check = 0;
	ps->clist = NULL;
	ps->len_a = argc - 1;
	ps->len_b = 0;
	x = 0;
	ps->ret = 0;
	ps->size = argc - 1;
	while (x < argc - 1)
	{
		ps->a[x] = ft_atoi(argv[x + 1]);
		ps->b[x] = 0;
		x++;
	}
	ps->print_commands = 1;
	x = 0;
	return (ps);
}

static void		which_algo_small(t_ps *ps)
{
	if (ps->size == 1)
		return ;
	else if (ps->size == 2)
		return (check_swap(ps, 'a'));
	else if (ps->size == 3)
		return (sort_3_a(ps));
	else if (ps->size == 4)
		return (sort_4(ps));
	else
		return (small_algo(ps));
}

static int		free_everything(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps);
	return (1);
}

int				main(int argc, char **argv)
{
	t_ps *ps;

	if (argc < 2)
		return (1);
	ps = create_struct(argc, argv);
	if (!find_unordered_ascending(ps->a, ps->len_a))
		return (free_everything(ps));
	if (argc < 7)
		which_algo_small(ps);
	else
		big_algorithm_three(ps);
	check_for_dumb_commands(ps, 0);
	print_clist(ps);
	return (free_everything(ps));
}
