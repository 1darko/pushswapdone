/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:09:39 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/28 13:01:07 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Looks for the best node inside stack b, 
// setting the target inside a->target when found
void	target_filler1(t_stack *a, t_stack *b)
{
	t_stack	*node;
	t_stack	*temp_b;
	long	value;

	while (a)
	{
		value = LONG_MIN;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->nbr < a->nbr && temp_b->nbr > value)
			{
				value = temp_b->nbr;
				node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (value == LONG_MIN)
			a->target = itsabigboy(b);
		else
			a->target = node;
		a = a->next;
	}
}

void	target_filler2(t_stack *true_a, t_stack *b)
{
	t_stack	*a;
	t_stack	*node;
	long	value;

	while (b)
	{
		value = LONG_MAX;
		a = true_a;
		while (a)
		{
			if (a->nbr > b->nbr && a->nbr < value)
			{
				value = a->nbr;
				node = a;
			}
			a = a->next;
		}
		if (value == LONG_MAX)
		{
			node = itstinyboi(true_a);
			b->target = node;
		}
		else
			b->target = node;
		b = b->next;
	}

}

/// Sets the cost for each node required to push from a to b
void	cost_setter(t_stack *a, t_stack *b)
{
	long	size_a;
	long	size_b;

	size_a = size_stack(a);
	size_b = size_stack(b);
	if (!a)
		return ;
	while (a)
	{
		a->cost = a->index;
		if (a->above_median == 0)
			a->cost = size_a - (a->index);
		if (a->target->above_median == 1)
			a->cost += a->target->index;
		else
			a->cost += size_b - (a->target->index);
		a = a->next;
	}
}

// Returns the node with the first found and lowest a->cost from the stack
t_stack	*its_on_sale(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (!a)
		return (0);
	if (a->next == NULL)
		return (a);
	while (a->next != NULL)
	{
		if (temp->cost > a->cost)
			temp = a;
		a = a->next;
	}
	if (temp->cost > a->cost)
		temp = a;
	return (temp);
}

void	cheapest_setter(t_stack *a)
{
	int		cheap;
	t_stack	*temp;

	cheap = 2147483647;
	if (!a)
		return ;
	while (a)
	{
		if (cheap > a->cost)
		{
			cheap = a->cost;
			temp = a;
		}
		a = a->next;
	}
	temp->cheapest = 1;
}
