/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ab_case_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 19:35:23 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 20:13:51 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		case_124(int step, int count)
{
	if (step == 0 && (count == 0 || count == 1))
		return ('b');
	return ('a');
}

static char		case_68(int step, int count)
{
	if (step == 0 && count == 3)
		return ('a');
	else if (step == 1 && count == 2)
		return ('a');
	else if ((step == 2 || step == 6) && (count == 0 || count == 2))
		return ('a');
	else if (step == 3 || step == 7)
		return ('a');
	else if (step == 4 && (count == 0 || count == 3))
		return ('a');
	else if (step == 5 && count == 2)
		return ('a');
	return ('b');
}

static char case_10_11(int w_case, int step, int count)
{
	if ((w_case == 11 && step == 0 && count == 3) || step == 7)
		return ('a');
	else if ((w_case == 10 && step == 1) || (w_case == 11 && (step == 1 || \
	step == 2 || step == 5)))
	{
		if (count == 0)
			return ('b');
		return ('a');
	}
	else if ((w_case == 11 && step == 7) || (w_case == 10 && (step == 3 || \
	step == 7 || step == 6)))
		return ('a');
	else if ((w_case == 11 && step == 6) || (w_case == 10 && step == 5))
	{
		if (count == 1)
			return ('b');
		return ('a');
	}
	else if ((w_case == 11 && step == 0 && count == 3) || (w_case == 11 && \
	step == 3 && count == 1) || (w_case == 11 && step == 4 && (count == 0 \
	|| count == 3)))
		return ('a');
	return ('b');
}

static char		case_12_13(int step, int count)
{
	if (step == 3 || (step == 2 && count == 0))
		return ('b');
	else if (step == 4 && (count == 2 || count == 3))
		return ('b');
	else if (step == 5 && count == 1)
		return ('b');
	else if (step == 6 && (count == 1 || count == 2))
		return ('b');
	return ('a');
}

char	get_ab_case(int w_case, int step, int count)
{
	if (w_case == 1 || w_case == 2 || w_case == 4)
		return (case_124(step, count));
	else if (w_case == 6 || w_case == 8)
		return (case_68(step, count));
	else if (w_case == 12 || w_case == 13)
		return (case_12_13(step, count));
	else if (w_case == 10 || w_case == 11)
		return (case_10_11(w_case, step, count));
	else
		return (second_get_ab_case(w_case, step, count));	
}