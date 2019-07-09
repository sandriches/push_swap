/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_case.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 20:28:49 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 20:38:47 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_case(int *a, int *b, int size)
{
	if (a[3] + b[3] + a[2] + a[1] + a[0] == size)
		return (1);
	else if (a[3] + b[3] + a[2] + a[1] + a[0] == size)
		return (2);
	else if (a[3] + b[3] + a[2] + a[1] + b[0] == size)
		return (5);
	else if (a[3] + b[3] + a[2] + b[1] + b[0] == size)
		return (3);
	else if (a[3] + b[3] + b[2] + b[1] + b[0] == size)
		return (4);
	else if ()
}