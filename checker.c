/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:15:50 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/29 12:27:41 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h> 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}	t_list;

typedef struct s_check
{
	char	*str;
	struct s_check *next;	
}	t_check;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
t_list	*lastnode1(t_list *temp);
int		check_newline(t_list *stash);
void	stash_free1(t_list *stash);
void	stash_drop(t_list **stash);
void	stash_filler(t_list **stash, char *buf, int bytes);
void	read_to_stash(t_list **stash, int fd);
void	linemalloc(t_list *stash, char **line);
void	stash_to_line(t_list *stash, char **line);
t_check	*lastnode_check(t_check *temp);
void	stash_free_check(t_check **a);


void print_stack2(t_check *stack) {
    t_check *current = stack;

    printf("[ ");
    while (current != NULL) {
        printf("%s", current->str);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" ]\n");
}

void	stash_free_check(t_check **a)
{
	t_check	*temp;
	t_check	*cur;

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

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	cur;
	char	*dup;

	cur = 0;
	len = ft_strlen((char *)s);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == 0)
		return (NULL);
	while (s[cur] != '\0')
	{
		dup[cur] = s[cur];
		cur++;
	}
	dup[cur] = '\0';
	return (dup);
}

t_check	*lastnode_check(t_check *temp)
{
	if (!temp)
		return (0);
	while (temp && temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	enlarge_struct(t_check **a, char *line)
{
	t_check	*end;
	t_check	*temp;

	temp = malloc(sizeof(t_check));
	if (!temp)
		return ;
	temp->str = ft_strdup(line);
	temp->next = NULL;
	if (*a == NULL)
		*a = temp;
	else
	{
		end = lastnode_check(*a);
		end->next = temp;
	}
	printf("Le debut est a %s", (*a)->str);
	print_stack2(*a);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//  Going to the last node of our stash
t_list	*lastnode1(t_list *temp)
{
	if (!temp)
		return (0);
	while (temp && temp->next != NULL)
		temp = temp->next;
	return (temp);
}

//  Check for \n inside stash, if found returns 1, else 0
int	check_newline(t_list *stash)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (stash == NULL)
		return (0);
	temp = lastnode1(stash);
	while (temp->content[i])
	{
		if (temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//  free(all the stash)//
void	stash_free1(t_list *stash)
{
	t_list	*temp;
	t_list	*cur;

	cur = stash;
	while (cur)
	{
		free(cur->content);
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

/*  Clearing stash and getting new begining for it
	t_list	*end_stash;
	t_list	*new_start;
*/
void	stash_drop(t_list **stash)
{
	t_list	*end;
	t_list	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (stash_free1(*stash));
	new->next = 0;
	end = lastnode1(*stash);
	while (end->content[i] && end->content[i] != '\n')
		i++;
	if (end->content[i] && end->content[i] == '\n')
		i++;
	new->content = malloc(sizeof(char) *((ft_strlen(end->content) - i) + 1));
	if (!new->content)
		return (stash_free1(*stash));
	while (end->content[i] != '\0')
		new->content[j++] = end->content[i++];
	new->content[j] = '\0';
	stash_free1(*stash);
	*stash = new;
}


void	stash_filler(t_list **stash, char *buf, int bytes)
{
	int		i;
	t_list	*temp;
	t_list	*end;

	i = 0;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->next = NULL;
	temp->content = malloc(sizeof(char) * (bytes + 1));
	if (!temp->content)
		return (free(temp));
	while (buf[i] && i < bytes)
	{
		temp->content[i] = buf[i];
		i++;
	}
	temp->content[i] = '\0';
	if (*stash == NULL)
		*stash = temp;
	else
	{
		end = lastnode1(*stash);
		end->next = temp;
	}
}

//  Looping & reading until \n or EOF
void	read_to_stash(t_list **stash, int fd)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	while (!check_newline(*stash) && bytes > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		bytes = (int)read(fd, buf, BUFFER_SIZE);
		if ((bytes == 0 && *stash == NULL) || bytes == -1)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		stash_filler(stash, buf, bytes);
		if (!stash)
		{
			free(buf);
			return ;
		}
		free(buf);
	}
}

//  New malloced line 
void	linemalloc(t_list *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i] != '\0')
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

//  Trasnfer from stash to line until \n or EOF
void	stash_to_line(t_list *stash, char **line)
{
	int		j;
	int		k;
	t_list	*temp;

	j = 0;
	temp = stash;
	linemalloc(stash, line);
	if (*line == NULL)
		return ;
	while (temp)
	{
		k = 0;
		while (temp->content[k] != '\0')
		{
			if (temp->content[k] == '\n')
			{
				(*line)[j++] = temp->content[k];
				break ;
			}
			(*line)[j++] = temp->content[k++];
		}
		temp = temp->next;
	}
	(*line)[j] = '\0';
}
/*        1/trasnferer buf dans stash pour taille de bytes;
            buftostash(&stash, bytes);
        2/check si quelque chose a été stash
        3/stash to line
            stash_to_line(&stash, &line)
        4/clean stash   
            stash_drop(&stash);  */

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		stash_free1(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	read_to_stash(&stash, fd);
	if (!stash)
		return (NULL);
	stash_to_line(stash, &line);
	if (stash == NULL)
		return (0);
	stash_drop(&stash);
	if (line[0] == '\0')
	{
		stash_free1(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void print_stack(t_stack *stack) {
    t_stack *current = stack;

    printf("[ ");
    while (current != NULL) {
        printf("%d", current->nbr);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" ]\n");
}
void	pushers(t_stack **a, t_stack **b, t_check **c)
{
	if((*c)->str[1] == 'a')
		pa(a, b, 0);
	else
		pb(a, b, 0);
}
void swappers(t_stack **a, t_stack **b, t_check **c)
{
	if((*c)->str[1] == 'a')
		sa(a, 0);
	else if ((*c)->str[1] == 'b')
		sb(b, 0);
	else
		ss(a, b, 0);		
}
void	rotate_up(t_stack **a, t_stack **b, t_check **c)
{printf("JE RENTRE ICI\n");
	if((*c)->str[1] == 'a'){
		ra(a, 0);}
	else if ((*c)->str[1] == 'b')
		rb(b, 0);
	else
		rr(a, b, 0);		
}
void	rotate_down(t_stack **a, t_stack **b, t_check **c)
{
	if((*c)->str[2] == 'a')
		rra(a, 0);
	else if ((*c)->str[2] == 'b')
		rrb(b, 0);
	else
		rrr(a, b, 0);		
}
int	compare(char *str, char *cmd)
{
	int i;
	int j;

	i = 0;
	while(cmd[i])
	{
		j = 0;
		while(str[j] == cmd[i])
		{
			if(str[j] == '\n')
				return (1);
			j++;
			i++;
		}
		i++;
	}
	return (0);
}
int	check_error(t_check **c)
{
	char *cmd;

	cmd = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	while(*c)
	{
		if(compare((*c)->str, cmd) == 1)
			*c = (*c)->next;
		else 
			return (1);
	}
	return (0);
}
void	sort(t_stack **a, t_stack **b, t_check **c)
{
	if(check_error(c) == 1)
	{	
		stash_free(a);
		stash_free(b);
		stash_free_check(c);
		write(2, "Error\n", 6);
		exit(1);
	}
	while(*c)
	{
		if((*c)->str[0] == 's')
			swappers(a, b, c);
		else if((*c)->str[0] == 'p')
			pushers(a, b, c);
		else if((*c)->str[0] == 'r' && (*c)->str[3] == '\0')
			rotate_up(a, b, c);
		else if ((*c)->str[0] == 'r' && (*c)->str[4] == '\0')
			rotate_down(a, b, c);
		(*c) = (*c)->next;
	}
}
int	main(int ac, char **arg)
{
	t_stack	*a;
	t_stack	*b;
	t_check *c;
    char *line;

	a = NULL;
	b = NULL;
	c = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		arg = ft_split(arg[1], ' ');
		if (arg[1] == NULL)
			its_an_error(0, arg + 1, ac == 2, 2);
	}
	check_digit(arg + 1, ac == 2);
	init_struct(&a, arg + 1, ac == 2);
	valuefiller(&a);
    while(1)
    {
		line = get_next_line(0);
		if(line == NULL)
			break ;
		enlarge_struct(&c, line);
		free(line);		
    }
    //exec
	sort(&a, &b ,&c);
    if(!b && is_sorted(&a) == 0)
        write(1, "OK\n", 3);
    else
	{ 
        write(1, "KO\n", 3);
	}
	print_stack(a);
	return (stash_free(&a), stash_free_check(&c), 0);
}
