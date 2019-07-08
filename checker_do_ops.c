/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_do_ops.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 14:53:35 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/08 15:07:03 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker_swap_a(c_a *ps)
{
	if (ps->len_a < 2)
		return (-1);
	ps->temp = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = ps->temp;
	return (1);
}

int		checker_swap_a(c_a *ps)
{
	if (ps->len_a < 2)
		return (-1);
	ps->temp = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = ps->temp;
	return (1);
}
