/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_biggest_or_smallest.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:58:14 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/25 15:07:44 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_3_int(int a, int b, int c, char sign)
{
	if (sign == '>')
	{
		if (a > b && a > c)
			return (a);
		else if (b > a && b > c)
			return (b);
		return (c);
	}
	else if (sign == '<')
	{
		if (a < b && a < c)
			return (a);
		else if (b < a && b < c)
			return (b);
		return (c);
	}
	else
	{
		if (a < b && a < c && b < c)
			return (b);
		if (b < c && b < a && a < c)
			return (a);
		return (c);
	}
}

int	return_smallest_int_4(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < a && b < c && b < d)
		return (b);
	else if (c < a && c < b && c < d)
		return (c);
	return (d);
}

int	return_biggest_int_4(int a, int b, int c, int d)
{
	if (a > b && a > c && a > d)
		return (a);
	else if (b > a && b > c && b > d)
		return (b);
	else if (c > a && c > b && c > d)
		return (c);
	return (d);
}

int	return_second_biggest_int_4(int a, int b, int c, int d)
{
	if (return_biggest_int_4(a, b, c, d) == a)
		return (return_3_int(b, c, d, '>'));
	else if (return_biggest_int_4(a, b, c, d) == b)
		return (return_3_int(a, c, d, '>'));
	else if (return_biggest_int_4(a, b, c, d) == c)
		return (return_3_int(a, b, d, '>'));
	else
		return (return_3_int(a, b, c, '>'));
}

int	return_second_smallest_int(int a, int b, int c, int d)
{
	if (return_smallest_int_4(a, b, c, d) == a)
		return (return_3_int(b, c, d, '<'));
	else if (return_smallest_int_4(a, b, c, d) == b)
		return (return_3_int(a, c, d, '<'));
	else if (return_smallest_int_4(a, b, c, d) == c)
		return (return_3_int(a, b, d, '<'));
	else
		return (return_3_int(a, b, c, '<'));
}
