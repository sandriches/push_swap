/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ab_case_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 20:13:54 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 20:26:29 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	get_case_79(int step, int count)
{
	if (step == 0 || (step == 4 && (count == 2 || count == 3)))
		return ('b');
	return ('a');
}

static char	get_case_5(int step, int count)
{
	if (step == 0 && count != 3)
		return ('b');
	else if (step == 2 && count != 2)
		return ('b');
	else if (step == 4 && (count == 0 || count == 3))
		return ('b');
	return ('a');
}

static char	get_case_14_15(int w_case, int step, int count)
{
	if (w_case == 14)
	{
		if (step == 7 || step == 6 || step == 5 || step == 1)
			return ('a');
		else if (step == 0 || step == 2)
			return ('b');
		else if ((step == 3 && count == 1) || (step == 4 && count == 0))
			return ('a');
		return ('b');
	}
	else
	{
		if (step == 7 || (step == 6 && count == 0) || (step == 4 && count == 0))
			return ('a');
		return ('b');
	}
}

static char	get_case_3(int step, int count)
{
	if (step == 5)
	{
		if (count == 1 || count == 2)
			return ('b');
	}
	return ('a');
}

char		second_get_ab_case(int w_case, int step, int count)
{
	if (w_case == 7 || w_case == 9)
		return (get_case_79(step, count));
	else if (w_case == 5)
		return (get_case_5(step, count));
	else if (w_case == 14 || w_case == 15)
		return (get_case_14_15(w_case, step, count));
	else
		return (get_case_3(step, count));
}