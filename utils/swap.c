/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:01:11 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/29 11:09:10 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a, int to_print)
{
	t_stack	*swap;
	t_stack	*temp;

	if ((*a)->next == NULL || a == NULL)
		return ;
	swap = *a;
	temp = swap->next;
	swap->next = swap->next->next;
	temp->next = swap;
	*a = temp;
	if (to_print)
		write(1, "sa\n", 3);
	return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b, int to_print)
{
	t_stack	*swap;
	t_stack	*temp;

	if ((*b)->next == NULL || b == NULL)
		return ;
	swap = *b;
	temp = swap->next;
	swap->next = swap->next->next;
	temp->next = swap;
	*b = temp;
	if (to_print)
		write(1, "sb\n", 3);
	return ;
}

// ss : sa and sb at the same time.
void	ss(t_stack **a, t_stack **b, int to_print)
{
	sa(a, 0);
	sb(b, 0);
	if(to_print)
		write(1, "ss\n", 3);
	return ;
}
