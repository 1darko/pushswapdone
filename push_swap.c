/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:49:33 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 19:41:47 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **arg)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		arg = ft_split(arg[1], ' ');
		if (arg[1] == NULL)
			its_an_error(0, arg + 1, ac == 2, 2);
	}
	check_digit(arg + 1, ac == 2);
	init_struct(&a, arg + 1, ac == 2);
	valuefiller(&a);
	if (is_sorted(&a))
	{
		if (size_stack(a) == 2)
			ra(&a, 1);
		if (size_stack(a) == 3)
			sort_three(&a);
		else
			real_sort(&a, &b);
	}
	return (stash_free(&a), 0);
}
