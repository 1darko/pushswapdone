/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:05:52 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/27 18:40:14 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief
/// @param str The intial string
/// @param c Char that splits words
/// @param tab Intialization of tab[2] = {0 , 0} if check 1
/// @param check Check for tab
/// @return Word count 
static int	wdcount(const char *str, char c, int *tab, int check)
{
	int	cur;
	int	words;

	if (check == 1)
	{
		tab[0] = 0;
		tab[1] = 0;
	}
	cur = 0;
	words = 0;
	while (str[cur])
	{
		if (str[cur] != c && (str[cur + 1] == c || str[cur + 1] == '\0'))
			words++;
		cur++;
	}
	return (words);
}

static char	*newstr(int start, char c, const char *str, int count)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * count + 1);
	if (!copy)
		return (0);
	while (str[start] != '\0' && str[start] != c)
	{
		copy[i] = str[start];
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	checker(const char *str, int *i, char c)
{
	if ((str[*i] == c && str[*i - 1] != c) && *i != 0)
		return (1);
	if ((str[*i] == 0 && str[*i - 1] != c) && *i != 0)
		return (1);
	return (0);
}

static int	real_split(char **copy, const char *str, int *i, char c)
{
	int	count[2];

	wdcount(str, c, count, 1);
	while (str[++(*i)])
	{
		if (checker(str, i, c))
		{
			copy[count[0]] = newstr(*i - count[1], c, str, count[1]);
			if (!copy[count[0]])
				return (1);
			(count[0])++;
			count[1] = 0;
		}
		if (str[*i] != c && str[*i] != 0)
			count[1]++;
	}
	if (checker(str, i, c))
	{
		copy[count[0]] = newstr(*i - count[1], c, str, count[1]);
		if (!copy[count[0]])
			return (1);
		(count[0])++;
	}
	copy[count[0]] = NULL;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**copy;
	int		j;

	j = 0;
	i = -1;
	if (!str)
		return (NULL);
	copy = malloc(sizeof(char *) * (wdcount(str, c, (int *)0, 0) + 2));
	if (!copy)
		return (NULL);
    copy[0] = malloc(1);
    if(!copy[0])
        return NULL;
    copy[0][0] = '\0';
	if (real_split(&(*copy) + 1, str, &i, c))
	{
		while (copy[j])
			free(copy[j++]);
		free(copy);
		return (0);
	}
	return (copy);
}