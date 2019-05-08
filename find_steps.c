/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_steps.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 14:04:48 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/08 16:27:27 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_movement(m_struct *node, p_a *ps)
{
	int median;
	int x;
	int stack_size_modifier;

	x = 0;
	stack_size_modifier = 1;
	median = ps->b[ps->size / 2];
	while (x < (ps->size * stack_size_modifier))
	{
		if (ps->b[x] >= median)
			push_b(ps);
		else
			rotate_a(ps);
	}
}