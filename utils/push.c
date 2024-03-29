/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:26:10 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:18 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pa (push a): Take the first element at the top of b 
// and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b, int to_print)
{
	t_stack	*swap;

	if (*b == NULL)
		return ;
	swap = *b;
	*b = (*b)->next;
	swap->next = *a;
	*a = swap;
	if (to_print)
		write(1, "pa\n", 3);
	return ;
}

// pb (push b): Take the first element at the top of a
// and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b, int to_print)
{
	t_stack	*swap;

	if (*a == NULL)
		return ;
	swap = *a;
	*a = (*a)->next;
	swap->next = *b;
	*b = swap;
	if (to_print)
		write(1, "pb\n", 3);
	return ;
}
