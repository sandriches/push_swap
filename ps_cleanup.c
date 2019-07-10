/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_cleanup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sandRICH <sandRICH@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/10 22:32:42 by sandRICH       #+#    #+#                */
/*   Updated: 2019/07/10 22:41:30 by sandRICH      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void get_unordered_indexes(p_a *ps, int *rtn_array)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (x < ps->size)
	{
		if (ps->a[x] < ps->a[x - 1])
		{
			rtn_array[y] = ps->a[x];
			y++;
		}
		x++;
	}
}

void	cleanup(p_a *ps)
{
	int x;
	int *unordered_index_array;

	unordered_index_array = (int *)malloc(sizeof(int) * find_unordered_ascending(ps->a, ps->len_a));
	get_unordered_indexes(ps, unordered_index_array);
	x = 0;
}