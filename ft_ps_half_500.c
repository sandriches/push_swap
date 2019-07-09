/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ps_half_500.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 11:59:24 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 16:59:26 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_back_ints(p_a *ps, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		push_b(ps);
		x++;
	}
}

static void do_insert_4_sort(p_a *ps)
{
	while (ps->len_b > 4)
	{
		grab_4_high_low_from_b(ps, ps->len_b);
		sort_4_high_low_b(ps);
	}
	while (ps->len_b > 0)
		push_a(ps);
	sort_4_not_alone_a(ps);
}

static void	half_a(p_a *ps, int size)
{
	static int i;
	i++;
	sort_by_med_a(ps, size, 0);
	if (ps->len_a > 4)
	{
		half_a(ps, ps->len_a);
		sort_4_not_alone_a(ps);
		// do_insert_4_sort(ps);
	}
}

static void	merge_sort_4_high(p_a *ps)
{
	ft_printf("in merge sort, biggest: %d\n", return_biggest_int_4(ps->a[0], ps->a[1], ps->b[0], ps->b[1]));
	if (return_biggest_int_4(ps->a[0], ps->a[1], ps->b[0], ps->b[1]) == ps->a[0])
		rotate_a(ps);
	else if (return_biggest_int_4(ps->a[0], ps->a[1], ps->b[0], ps->b[1]) == ps->a[1])
	{
		swap_a(ps);
		rotate_a(ps);
	}
	else if (return_biggest_int_4(ps->a[0], ps->a[1], ps->b[0], ps->b[1]) == ps->b[0])
	{
		push_a(ps);
		rotate_a(ps);
	}
	else if (return_biggest_int_4(ps->a[0], ps->a[1], ps->b[0], ps->b[1]) == ps->b[1])
	{
		swap_b(ps);
		push_a(ps);
		rotate_a(ps);
	}
}

void		ft_ps_half_500(p_a *ps, int size)
{
	int x;

	x = 0;
	sort_by_med_a(ps, ps->len_a, 0);
	sort_by_med_a(ps, ps->len_a, 0);
	// while (ps->len_b > 4)
	// {
	// 	grab_4_from_b(ps, ps->len_b);
	// 	sort_4_not_alone_a(ps);
	// }
	// while (ps->len_b > 0)
	// {
	// 	push_a(ps);
	// 	sort_4_not_alone_a(ps);
	// }
	// x = 0;
	// while (x < ps->size / 4)
	// {
	// 	rotate_a(ps);
	// 	x++;
	// }
	// while (x < ps->size / 2)
	// {
	// 	push_b(ps);
	// 	x++;
	// }
	// while (ps->len_b > 4)
	// {
	// 	grab_4_from_b(ps, ps->len_b);
	// 	sort_4_not_alone_a(ps);
	// }
	// while (ps->len_b > 0)
	// {
	// 	push_a(ps);
	// 	sort_4_not_alone_a(ps);
	// }
}









// static void	bring_back_ints2(p_a *ps, int size)
// {
// 	int x;

// 	x = 0;
// 	while (x < size)
// 	{
// 		push_b(ps);
// 		x++;
// 	}
// }

// static void do_insert_4_sort2(p_a *ps, int size)
// {
// 	while (ps->len_a > 2)
// 	{
// 		grab_2_high_low(ps, ps->len_a);
// 		if (ps->b[0] > ps->b[1])
// 			rotate_b(ps);
// 		else
// 		{
// 			swap_b(ps);
// 			rotate_b(ps);
// 		}		
// 	}
// 	while (ps->len_a > 0)
// 		push_b(ps);
// 	// sort_4_not_alone_a(ps);
// }

// static void	half_a_inoffensive(p_a *ps, int size)
// {
// 	static int i;
// 	i++;
// 	sort_by_med_a(ps, size, 0);
// 	if (ps->len_a > 2)
// 	{
// 		half_a_inoffensive(ps, size);
// 		sort_4_not_alone_a(ps);
// 		do_insert_4_sort2(ps, size);
// 	}
// }



// void		ft_ps_half_500(p_a *ps, int size)
// {
// 	do_insert_4_sort2(ps, size);
// }