/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:07:04 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:15 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//// Massive free
/// Frees the char ** as a whole
void	free_array(char **str)
{
	int	i;

	i = -1;
	while (str[i] != NULL)
		free(str[i++]);
	free(str - 1);
}

/// Frees the stack and  each node
void	stash_free(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cur;

	if (!a)
		return ;
	cur = *a;
	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	free(cur);
}
