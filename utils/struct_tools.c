/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sturct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:31:34 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:20 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// LF first node by value 
t_stack	*first_node(t_stack *t)
{
	t_stack	*a;

	a = t;
	while (a->value != 1)
		a = a->next;
	return (a);
}

t_stack	*lastnode(t_stack **temp)
{
	t_stack	*cur;

	if (!temp)
		return (NULL);
	cur = *temp;
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}

/// strlen for struct (starts at 1 returns 0 if *a == NULL)
int	size_stack(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
