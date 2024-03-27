/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:29 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:12 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//// Check and errors
/// @brief Error display
/// @param a Stack that needs to be freed
/// @param arg Arguments of the program
/// @param split Check if arguments were split or not
/// @param check Case check for display message : 
///         0 : element(s) outside int range  -- 1 : duplicates  -- 2 non valid arg (2) 
void its_an_error(t_stack **a, char **arg, int split, int check)
{

    if(check == 0)
        write(2, "Error : element(s) outside int range\n", 38);
    if(check == 1)
        write(2, "Error : duplicates\n", 20);
    if(check == 2 || check == 4)
    { 
        write(2, "Error : non-valid arg\n", 23);
        if(split)
            free_array(arg);
        exit(1);
    }
    if(split)
        free_array(arg);
    stash_free(a);
    exit(1);
}