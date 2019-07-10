/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ab_case_value.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/10 15:55:04 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/10 16:07:52 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_ab_case_value(p_a *ps, int step, int count)
{
	if (get_ab_case(ps->w_case, step, count) == 'a')
	{
		if (step == 1 || step == 2 || step == 5 || step == 6)
			return (ps->half_array_a[count + 1]);
		else if (step == 3 || step == 7)
		{
			return (ps->half_array_a[count + 2]);
		}
		else
			return (ps->half_array_a[count]);
	}
	else
	{
		if (step == 1 || step == 2 || step == 5 || step == 6)
			return (ps->half_array_b[count + 1]);
		else if (step == 3 || step == 7)
		{
			return (ps->half_array_b[count + 2]);
		}
		else
			return (ps->half_array_b[count]);
	}
}
