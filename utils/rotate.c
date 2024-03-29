/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:27:24 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/29 11:08:47 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a, int to_print)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_node = *a;
	second_node = first_node->next;
	last_node = second_node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
	*a = second_node;
	first_node->next = NULL;
	if (to_print)
		write(1, "ra\n", 3);
	return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b, int to_print)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	second_node = first_node->next;
	last_node = second_node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
	*b = second_node;
	first_node->next = NULL;
	if (to_print)
		write(1, "rb\n", 3);
	return ;
}

// rr : ra and rb at the same time.
void	rr(t_stack **a, t_stack **b, int to_print)
{
	ra(a, 0);
	rb(b, 0);
	if(to_print)
		write(1, "rr\n", 3);
	return ;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **b, int to_print)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	temp = first_node;
	while (temp->next->next != NULL)
	temp = temp->next;
	last_node = temp->next;
	last_node->next = first_node;
	*b = last_node;
	temp->next = NULL;
	if (to_print)
		write(1, "rra\n", 4);
	return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b, int to_print)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	temp = first_node;
	while (temp->next->next != NULL)
	temp = temp->next;
	last_node = temp->next;
	last_node->next = first_node;
	*b = last_node;
	temp->next = NULL;
	if (to_print)
		write(1, "rrb\n", 4);
	return ;
}
