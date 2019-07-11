/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_final_numbers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 19:34:34 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/11 20:14:44 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_num(p_a *ps, int step)
{
	int rtn;

	if (step == 0)
		rtn = (ps->h_b[1] + ps->h_b[1] == ps->h_a[0]) ? ps->h_b[1] : ps->h_a[1];
	else if (step == 1)
		rtn = (ps->h_b[2] + ps->h_b[2] == ps->h_a[1]) ? ps->h_b[2] : ps->h_a[2];
	else if (step == 2)
		rtn = (ps->h_b[3] + ps->h_b[3] == ps->h_a[2]) ? ps->h_b[3] : ps->h_a[3];
	else if (step == 3)
		rtn = (ps->h_b[3] + ps->h_b[3] == ps->h_b[2]) ? ps->h_b[3] : ps->h_a[3];
	else if (step == 4)
		rtn = (ps->h_a[1] + ps->h_a[1] == ps->h_b[0]) ? ps->h_a[1] : ps->h_b[1];
	else if (step == 5)
		rtn = (ps->h_a[2] + ps->h_a[2] == ps->h_b[1]) ? ps->h_a[2] : ps->h_b[2];
	else if (step == 6)
		rtn = (ps->h_a[3] + ps->h_a[3] == ps->h_b[2]) ? ps->h_a[3] : ps->h_b[3];
	else
		rtn = (ps->h_a[3] + ps->h_a[3] == ps->h_a[2]) ? ps->h_a[3] : ps->h_b[3];
	return (rtn);
}
