/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_case.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 20:28:49 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/10 15:50:58 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_case_b(int *a, int *b)
{
	if (a[0] % 8 == 5 && b[0] % 8 == 6)
		return (14);
	else if (a[0] % 8 == 6 && b[0] % 8 == 6)
		return (10);
	else if (a[0] % 8 == 6 && b[0] % 8 == 7)
		return (13);
	else if (a[0] % 8 == 7 && b[0] % 8 == 7)
		return (12);
	else if (a[0] % 8 == 7 && b[0] % 8 == 0)
		return (15);
	return (16);
}

int		get_case(int *a, int *b)
{
	if (a[0] % 8 == 0 && b[0] % 8 == 1)
		return (1);
	else if (a[0] % 8 == 1 && b[0] % 8 == 1)
		return (2);
	else if (a[0] % 8 == 1 && b[0] % 8 == 2)
		return (5);
	else if (a[0] % 8 == 2 && b[0] % 8 == 2)
		return (3);
	else if (a[0] % 8 == 2 && b[0] % 8 == 3)
		return (6);
	else if (a[0] % 8 == 3 && b[0] % 8 == 3)
		return (8);
	else if (a[0] % 8 == 3 && b[0] % 8 == 4)
		return (11);
	else if (a[0] % 8 == 4 && b[0] % 8 == 4)
		return (4);
	else if (a[0] % 8 == 4 && b[0] % 8 == 5)
		return (7);
	else if (a[0] % 8 == 5 && b[0] % 8 == 5)
		return (9);
	return (get_case_b(a, b));
}

// int main(void)
// {
// 	int array[14];
// 	int *a;
// 	int *b;
// 	int x = 0;

// 	for (int i = 497; i < 525; i++)
// 	{
// 		a = make_halving_array(i, 'a');
// 		b = make_halving_array(i, 'b');
// 		// ft_printf("size: %d\na[0]: %d\ta[1]: %d\ta[2]: %d\ta[3]: %d\nb[0]: %d\tb[1]: %d\tb[2]: %d\tb[3]: %d\n\n", i, a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
// 		ft_printf("size: %d\tcase: %d\n", i, get_case(a, b));
// 	}
// 	// for (int i = 248; i < 257; i++)
// 	// {
// 	// 	ft_printf("%d %% 8: %d\n", i, i % 8);
// 	// }
// 	return (0);
// }
