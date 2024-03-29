/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:19:13 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:17 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = its_on_sale(*a);
	if (cheap->above_median == 1 && cheap->target->above_median == 1)
		rotate_up_a(a, b, cheap);
	if (cheap->above_median == 0 && cheap->target->above_median == 0)
		rotate_down_a(a, b, cheap);
	set_a_on_top(a, cheap);
	set_b_on_top(b, cheap->target);
	pb(a, b, 1);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	set_a_on_top2(a, (*b)->target);
	pa(a, b, 1);
}

void	node_setter_a(t_stack *a, t_stack *b)
{
	index_setter(a);
	index_setter(b);
	target_filler1(a, b);
	cost_setter(a, b);
	cheapest_setter(a);
}

void	node_setter_b(t_stack *a, t_stack *b)
{
	index_setter(a);
	index_setter(b);
	target_filler2(a, b);
}
