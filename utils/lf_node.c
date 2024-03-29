/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:07:35 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:14 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Looks for the biggets nbr inside struct a
t_stack	*itsabigboy(t_stack *a)
{
	long	min;
	t_stack	*temp;

	if (!a)
		return (NULL);
	min = -2147483648;
	temp = a;
	while (a)
	{
		if (a->nbr > min)
		{
			min = a->nbr;
			temp = a;
		}
	a = a->next;
	}
	return (temp);
}

t_stack	*itstinyboi(t_stack *a)
{
	t_stack	*temp;
	long	max;

	max = 2147483647;
	temp = a;
	while (a)
	{
		if (a->nbr < max)
		{
			temp = a;
			max = temp->nbr;
		}
		a = a->next;
	}
	return (temp);
}
