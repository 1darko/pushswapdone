/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:18:16 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:16 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_up_a(t_stack **a, t_stack **b, t_stack *cheap)
{
    while((*a)->nbr != cheap->nbr && (*b)->nbr != cheap->target->nbr)
        rr(a, b);
    index_setter(*a);
    index_setter(*b);
}

void    rotate_down_a(t_stack **a, t_stack **b, t_stack *cheap)
{
    while((*a)->nbr != cheap->nbr && (*b)->nbr != cheap->target->nbr)
        rrr(a, b);
    index_setter(*a);
    index_setter(*b);

}
void    rotate_up_b(t_stack **a, t_stack **b, t_stack *cheap)
{
    while((*b)->nbr != cheap->nbr && (*a)->nbr != cheap->target->nbr)
        rr(a, b);
    index_setter(*a);
    index_setter(*b);
}

void    rotate_down_b(t_stack **a, t_stack **b, t_stack *cheap)
{
    while((*b)->nbr != cheap->nbr && (*a)->nbr != cheap->target->nbr)
        rrr(a, b);
    index_setter(*a);
    index_setter(*b);
}