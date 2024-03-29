/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:24:09 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/28 10:44:18 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// Checks if there are only digits 
void	check_digit(char **arg, int split)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	j = 0;
	while (arg[j])
	{
		digit = 0;
		if (arg[j][0] == '\0')
			its_an_error(0, arg, split, 4);
		while (arg[j][i])
		{
			if (check_digit2(arg[j], split, i, digit) == 1)
				its_an_error(0, arg, split, 4);
			if (arg[j][i] >= '0' && arg[j][i] <= '9')
			digit = 1;
			i++;
		}
		j++;
		i = 0;
	}
}

int	double_check(t_stack **b, long nb)
{
	t_stack	*a;

	a = *b;
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack **a)
{
	t_stack	*check;

	check = *a;
	while (check->next != NULL)
	{
		if (check->nbr > check->next->nbr)
			return (1);
		check = check->next;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	check_digit2(char *arg, int split, int i, int digit)
{
	if (i >= 1 && arg[i] == ' ' && arg[i - 1] == ' ' && digit == 1)
		its_an_error(0, 0, split, 4);
	if (i >= 1 && ft_isdigit(arg[i]) == 1 && digit == 1
		&& !ft_isdigit(arg[i - 1]))
		its_an_error(0, 0, split, 4);
	if (!ft_isdigit(arg[i]))
		if ((arg[i] != '-' && arg[i] != '+' && arg[i] != ' ')
			|| ((arg[i] == '-' || arg[i] == '+')
				&& (arg[i + 1] == '-' || arg[i + 1] == '+'
					|| arg[i + 1] == '\0')))
			return (1);
	return (0);
}
