/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:28:50 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:20 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// Struct creater and checker if all ints are correcte
void init_struct(t_stack **a, char **arg, int split)
{   

    long nb;
    int i;
    
    i = 0;
    while(arg[i])
    {
        nb = ft_atol(arg[i]);
        if(nb > 2147483647 || nb < -2147483648)
            its_an_error(a, arg, split, 0);
        if(double_check(a, nb) == 1)
            its_an_error(a, arg, split, 1);
        struct_filler(a, nb);
        ++i;
    }
    if(split == 1)
        free_array(arg);
    

}
/// Filler for structure->nbr 
void struct_filler(t_stack **a, long nb) {
    t_stack *end;
    t_stack *temp;

    if(!a)
        return ;
    temp = malloc(sizeof(t_stack));
    if (!temp)
        return ;
    temp->nbr = nb;
    temp->next = NULL;
    if (*a == NULL) 
    {       
        temp->prev = NULL;
        *a = temp;

    }
    else 
    {        
        end = lastnode(a);
        end->next = temp;
        temp->prev = end;
    }
}

// Fills the true placement for each node
void valuefiller(t_stack **t) 
{
    t_stack *current = *t;
    t_stack *compare;
    int smaller_nbr_count;

    while (current != NULL) {
        compare = *t;
        smaller_nbr_count = 0;

        while (compare != NULL) {
            if (compare->nbr < current->nbr)
                smaller_nbr_count++;
            compare = compare->next;
        }

        current->value = smaller_nbr_count + 1;
        current = current->next;
    }
}

// Sets the acctual index for each node
void    index_setter(t_stack *a)
{
    int i;
    int median;

    i = 0;
    if(a == NULL)
        return ;
    median = (size_stack(a) / 2);
    while(a)
    {
        a->index = i;
        if(a->index <= median)
            a->above_median = 1;
        else
            a->above_median = 0;
        a = a->next;
        i++;
    }
}