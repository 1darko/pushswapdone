/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:58 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:19 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/// Sorting for stack of size 3
void sort_three(t_stack **a)
{
    if((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
        ra(a, 1);
    else if ((*a)->nbr < (*a)->next->nbr)
        rra(a, 1);
    // printf("je bug ici \n");

    if((*a)->nbr > (*a)->next->nbr)
        sa(a, 1);
}

void real_sort(t_stack **a, t_stack **b)
{
    int size;

    size  = size_stack(*a);
    if(size-- > 3 && is_sorted(a) == 1)
        pb(a, b, 1);
    if(size-- > 3 && is_sorted(a) == 1)
        pb(a, b, 1);
    while(size-- > 3 && is_sorted(a) == 1)
    {
        node_setter_a(*a, *b);     
        push_a_to_b(a, b);
    }
    if(is_sorted(a) == 1)
        sort_three(a);
    size = size_stack(*b);
    while(*b)
    {   
        node_setter_b(*a, *b);
        push_b_to_a(a, b);
        size--;
    }
    index_setter(*a);
    sorting_a(a); 
}

void sorting_a(t_stack **a)
{
    t_stack *first_node_value;
    
    first_node_value = first_node(*a);
    while(first_node_value != *a)
    {
        if(first_node_value->above_median == 1)
            ra(a, 1);
        else
            rra(a, 1);
    }
}