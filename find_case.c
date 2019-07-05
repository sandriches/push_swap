/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_case.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 13:07:49 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/05 15:34:24 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

static int	find_case_2(int *a, int *b)
{
	if (!s(a[0], b[0]) && !s(a[1], b[1]) && !s(a[2], b[2]) && s(a[3], b[3]))
		return (11);
	else if (s(a[0], b[0]) && !s(a[1], b[1]) && !s(a[2], b[2]) && !s(a[3], \
	b[3]))
		return (12);
	else if (!s(a[0], b[0]) && s(a[1], b[1]) && !s(a[2], b[2]) && !s(a[3], \
	b[3]))
		return (13);
	else if (!s(a[0], b[0]) && !s(a[1], b[1]) && s(a[2], b[2]) && !s(a[3], \
	b[3]))
		return (14);
	else if (!s(a[0], b[0]) && !s(a[1], b[1]) && !s(a[2], b[2]) && !s(a[3], \
	b[3]))
		return (15);
	return (16);
}

int			find_case(int *a, int *b)
{
	if (!s(a[0], b[0]) && s(a[1], b[1]) && s(a[2], b[2]) && s(a[3], b[3]))
		return (1);
	else if (s(a[0], b[0]) && !s(a[1], b[1]) && s(a[2], b[2]) && s(a[3], b[3]))
		return (2);
	else if (s(a[0], b[0]) && s(a[1], b[1]) && !s(a[2], b[2]) && s(a[3], b[3]))
		return (3);
	else if (s(a[0], b[0]) && s(a[1], b[1]) && s(a[2], b[2]) && !s(a[3], b[3]))
		return (4);
	else if (!s(a[0], b[0]) && !s(a[1], b[1]) && s(a[2], b[2]) && s(a[3], b[3]))
		return (5);
	else if (!s(a[0], b[0]) && s(a[1], b[1]) && !s(a[2], b[2]) && s(a[3], b[3]))
		return (6);
	else if (!s(a[0], b[0]) && s(a[1], b[1]) && s(a[2], b[2]) && !s(a[3], b[3]))
		return (7);
	else if (s(a[0], b[0]) && !s(a[1], b[1]) && !s(a[2], b[2]) && s(a[3], b[3]))
		return (8);
	else if (s(a[0], b[0]) && !s(a[1], b[1]) && s(a[2], b[2]) && !s(a[3], b[3]))
		return (9);
	else if (s(a[0], b[0]) && s(a[1], b[1]) && !s(a[2], b[2]) && !s(a[3], b[3]))
		return (10);
	else
		return (find_case_2(a, b));
}