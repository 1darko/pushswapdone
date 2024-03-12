#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

////////////////// STRUCT /////////////////////
typedef struct s_stack
{
    int nbr;
    int value;
    struct s_stack      *next;
}   t_stack;


// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void sa (t_stack **a, int to_print)
{
    t_stack *swap;
    t_stack *temp;

    if((*a)->next == NULL || a == NULL)
        return ;
    swap = *a;
    temp = swap->next;
    swap->next = swap->next->next;
    temp->next = swap;
    *a = temp;
    if(to_print)
        write(1, "sa\n", 3);
    return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sb (t_stack **b, int to_print)
{
    t_stack *swap;
    t_stack *temp;

    if((*b)->next == NULL || b == NULL)
        return ;
    swap = *b;
    temp = swap->next;

    swap->next = swap->next->next;
    temp->next = swap;
    *b = temp;
    if(to_print)
        write(1, "sb\n", 3);
    return ;
}
// ss : sa and sb at the same time.
void ss(t_stack **a, t_stack **b)
{   
    sa(a, 0);
    sb(b, 0);
    write(1, "ss\n", 3);
    return ;
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void pa(t_stack **a, t_stack **b, int to_print)
{
    t_stack *swap;

    if(*b == NULL)
        return ;
    swap = *b;
    *b = (*b)->next;
    swap->next = *a;
    *a = swap;
    if(to_print)
        write(1, "pa\n", 3);
    return ;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(t_stack **a, t_stack **b, int to_print)
{
    t_stack *swap;

    if(*a == NULL)
        return ;
    swap = *a;
    *a = (*a)->next;
    swap->next = *b;
    *b = swap;
    if(to_print)
        write(1, "pb\n", 3);
    return ;
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void    ra(t_stack **a, int to_print)
{
    if (*a == NULL || (*a)->next == NULL)
        return;

    t_stack *first_node;
    t_stack *second_node;
    t_stack *last_node;

    first_node = *a;
    second_node = first_node->next;
    last_node = second_node;
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = first_node;
    *a = second_node;
    first_node->next = NULL;
    if(to_print)
        write(1, "ra\n", 3);
    return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void    rb(t_stack **b, int to_print)
{
    if (*b == NULL || (*b)->next == NULL)
        return;

    t_stack *first_node;
    t_stack *second_node;
    t_stack *last_node;

    first_node = *b;
    second_node = first_node->next;
    last_node = second_node;
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = first_node;
    *b = second_node;
    first_node->next = NULL;
    if(to_print)
        write(1, "rb\n", 3);
    return ;
}
// rr : ra and rb at the same time.
void    rr(t_stack **a, t_stack **b)
{
    ra(a, 0);
    rb(b, 0);
    write(1, "rr\n", 3);
    return ;
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void    rra(t_stack **a, int to_print)
{
    t_stack *first_node;
    t_stack *last_node;
    t_stack *temp;
    
    if (*a == NULL || (*a)->next == NULL)
        return;
    first_node = *a;
    temp = first_node;
    while(temp->next->next != NULL)
        temp = temp->next;
    last_node = temp->next;
    last_node->next = first_node;
    *a = last_node;
    temp->next = NULL;
    if(to_print)
        write(1, "rra\n", 4);
    return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void    rrb(t_stack **b, int to_print)
{
    t_stack *first_node;
    t_stack *last_node;
    t_stack *temp;
    
    if (*b == NULL || (*b)->next == NULL)
        return;
    first_node = *b;
    temp = first_node;
    while(temp->next->next != NULL)
        temp = temp->next;
    last_node = temp->next;
    last_node->next = first_node;
    *b = last_node;
    temp->next = NULL;
    if(to_print)
        write(1, "rrb\n", 4);
    return ;
}
// rrr : rra and rrb at the same time.
void    rrr(t_stack **a, t_stack **b)
{
    rra(a, 0);
    rrb(b, 0);
    write(1, "rrr\n", 4);
    return ;
}


//////////////// PROTO ///////////////////////

void stash_free(t_stack **a);
void free_array(char **str);
void its_an_error(t_stack **a, char **arg, int splitted, int check);
///////////////// SPLIT ////////////////////// 

/// @brief
/// @param str The intial string
/// @param c Char that splits words
/// @param tab Intialization of tab[2] = {0 , 0} if check 1
/// @param check Check for tab
/// @return 
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
///////////////////// CHECK IF DIGIT /////////////////////////

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/////////////////// ERROR DISPLAY ///////////////////////////
void its_an_error(t_stack **a, char **arg, int split, int check)
{

    if(check == 0)
        write(1, "Error : element(s) outside int range\n", 38);
    if(check == 1)
        write(1, "Error : duplicates\n", 20);
    if(check == 2 || check == 4)
    { 
        write(1, "Error : non-valid arg\n", 23);
        if(check == 2)
        {
            free_array(arg);
        }
        exit(1);
    }
    if(split)
        free_array(arg);
    stash_free(a);
    exit(1);
}

////////// CHECKING ARG TO SEE IF ITS ONLY DIGITS AND CORRECTLY FORMATED /////////////
void    check_digit2(char *arg, int split, int i, int digit)
{
    if(i >= 1 && arg[i] == ' ' && arg[i - 1] == ' ' && digit == 1)
        its_an_error(0, 0, split, 4);
    if(i >= 1 && ft_isdigit(arg[i]) == 1 && digit == 1 && !ft_isdigit(arg[i - 1])){printf("%d \n" ,digit);
        its_an_error(0, 0, split, 4);}
    if(!ft_isdigit(arg[i]))
        if((arg[i] != '-' && arg[i] != '+' && arg[i] != ' ') 
                    || ((arg[i] == '-' || arg[i] == '+') 
                    && (arg[i + 1] == '-' || arg[i + 1] == '+' || arg[i + 1] == '\0')))
            {
            printf("ca saute ici \n");
                its_an_error(0, 0, split, 4);
            }
}
void check_digit(char **arg, int split)
{
    int i;
    int j;
    int digit;

    i = 0;
    j = 0;
    while(arg[j])
    {
        digit = 0;
        if(arg[j][0] == '\0'){printf("ca saute ici \n");
            its_an_error(0, arg, split, 4);}
        while(arg[j][i])
        {   
            
            check_digit2(arg[j], split, i, digit);
            if(arg[j][i] >= '0' && arg[j][i] <= '9')
                digit = 1;
            i++;
        }
        j++;
        i = 0;
    }
}
long ft_atol(char *str)
{
    int sign = 1;
    long nbr;

    nbr = 0;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign = -1;
        ++str;
    }
    while(*str == '0')
        ++str;
    while(*str)
        nbr = nbr * 10 + (*str++ - '0');
    return(nbr * sign);
}
void    free_array(char **str)
{
    int i = -1;
    while(str[i] != NULL)
        free(str[i++]);
    free(str - 1);

}

void	stash_free(t_stack **a)
{
	t_stack	*temp;
    t_stack *cur;

    cur = *a;

	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
    free(cur);
}

t_stack *lastnode(t_stack **temp) {
    t_stack *cur;
    if (!temp || !(*temp)) // Check if temp or *temp is NULL
        return NULL;
    cur = *temp;
    while (cur->next != NULL)
        cur = cur->next;
    return cur;
}

void struct_filler(t_stack **a, long nb) {
    t_stack *end;
    t_stack *temp;

    temp = malloc(sizeof(t_stack));
    if (!temp)
        return ;
    temp->nbr = nb;
    temp->next = NULL;
    if (*a == NULL) 
        *a = temp;
    else 
    {
        end = lastnode(a);
        if (!end) {
            // Handle error condition where end is NULL
            free(temp); // Free allocated memory
            return;
        }
        end->next = temp; // Link the new node to the end of the list
    }
}

int double_check(t_stack **b, long nb)
{
    t_stack *a;

    a = *b;
    if(!a)
        return 0;
    while(a)
    {
        if(a->nbr == nb)
            return (1);
        a = a->next;
    }
    return 0;
}

void init_struct(t_stack **a, char **arg, int splitted)
{
    long nb;
    int i;
    
    i = 0;
    while(arg[i])
    {
        nb = ft_atol(arg[i]);
        if(nb > 2147483647 || nb < -2147483648)
            its_an_error(a, arg, splitted, 0);
        if(double_check(a, nb) == 1)
            its_an_error(a, arg, splitted, 1);
        struct_filler(a, nb);
        ++i;
    }
    if(splitted == 1)
        free_array(arg);

}

int is_sorted(t_stack **a)
{
    t_stack *check;
    check = *a;

    while(check->next != NULL)
    {
        if(check->nbr > check->next->nbr)
            return 1;
        check = check->next;
    }
    return 0;
}

void printStack(t_stack *stack) {
    printf("Printing stack contents:\n");
    while (stack != NULL) {
        printf("nbr: %d, value: %d\n", stack->nbr, stack->value);
        stack = stack->next;
    }
}
int empty(t_stack **b)
{
    return (b == NULL);
}

int sizee(t_stack **a)
{
    t_stack *temp;

    if(*a == NULL)
        return 0;
    int i = 1;

    temp = *a;

    while(temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
int main(int nb, char **arg)
{
    t_stack *a;
    t_stack *b;
    int check;

    check = 0;
    a = NULL;
    b = NULL;
    if(nb == 1)
        return (1);
    // if(nb == 2 && !arg[1][0])
    // {
    //     write(1,"Error\n",7);
    //     return(0);
    // }
    if(nb == 2) // si arg "1 2 3"
    { 
        arg = ft_split(arg[1], ' ');
        if(arg[1] == NULL)
            its_an_error(0, arg + 1, 0, 2);
        // if(arg[2] == NULL)
        // {   free(b);
        //     free_array(arg + 1);
        //     return (0);
        // }
    }
    check_digit(arg + 1, nb == 2);
    if(nb == 2 && wdcount(arg[1], ' ', 0,0) == 1)
        return 1;
    // printf("%s", arg[1]);
    init_struct(&a, arg + 1, 2 == nb);
    printStack(a);
    int size = sizee(&a);
    printf("%d",size);
    // if(a->next->nbr < a->nbr && a->nbr > a->next->next->nbr)
    //     ra(&a, 1);
    if(a->nbr < a->next->nbr && a->next->nbr > a->next->next->nbr && a->next->nbr < a->next->next->nbr)
    {
        rra(&a,1);
    }
    else if(a->nbr > a->next->nbr && a->nbr > a->next->next->nbr && a->next->nbr < a->next->next->nbr)
    {   
        ra(&a, 1);

    }
    else 
    {
        sa(&a,1);
        rra(&a,1);
        rra(&a, 1);
    }
    printStack(a);
    // stash_free(&b);
    stash_free(&a);
    return 1;
}