/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:17:40 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/29 11:08:05 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// Big sort
void	set_a_on_top(t_stack **a, t_stack *cheap)
{
	if (cheap->above_median == 1)
		while ((*a)->nbr != cheap->nbr)
			ra(a, 1);
	else
		while ((*a)->nbr != cheap->nbr)
			rra(a, 1);
}

void	set_b_on_top(t_stack **b, t_stack *target)
{
	if (target->above_median == 1)
		while ((*b)->nbr != target->nbr)
			rb(b, 1);
	else
		while ((*b)->nbr != target->nbr)
			rrb(b, 1);
}

void	set_b_on_top2(t_stack **b, t_stack *cheap)
{
	if (cheap->above_median == 1)
		while ((*b)->nbr != cheap->nbr)
			rb(b, 1);
	else
		while ((*b)->nbr != cheap->nbr)
			rrb(b, 1);
}

void	set_a_on_top2(t_stack **a, t_stack *target)
{
	if (target->above_median == 1)
		while ((*a)->nbr != target->nbr)
			ra(a, 1);
	else
		while ((*a)->nbr != target->nbr)
			rra(a, 1);
}

void	rrr(t_stack **a, t_stack **b, int to_print)
{
	rra(a, 0);
	rrb(b, 0);
	if(to_print)
		write(1, "rrr\n", 4);
	return ;
}
