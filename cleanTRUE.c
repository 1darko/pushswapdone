#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

////////////////// STRUCT /////////////////////
typedef struct s_stack
{
    int nbr;
    int value;
    int index;
    int above_median;
    int cost;
    int cheapest;

    struct s_stack      *next;
    struct s_stack      *prev;
    struct s_stack      *target;
}   t_stack;
//// Proto
void    index_setter(t_stack *a);
void valuefiller(t_stack **t);
void stash_free(t_stack **a);
int size_stack(t_stack *a);
void    free_array(char **str);
int    check_digit2(char *arg, int split, int i, int digit);
void check_digit(char **arg, int split);
long ft_atol(char *str);
int double_check(t_stack **b, long nb);
void struct_filler(t_stack **a, long nb);
t_stack *lastnode(t_stack **temp);
int is_sorted(t_stack **a);
void sorting_a(t_stack **a);
t_stack *first_node(t_stack *a);
void its_an_error(t_stack **a, char **arg, int split, int check);
void sort_three(t_stack **full);
void real_sort(t_stack **a, t_stack **b);
void    node_setter_a(t_stack *a, t_stack *b);
void    node_setter_b(t_stack *a, t_stack *b);

void target_filler(t_stack *a, t_stack *b);
t_stack *itsabigboy(t_stack *a);
t_stack *its_on_sale(t_stack *a);

void sa (t_stack **a, int to_print);
void sb (t_stack **b, int to_print);
void ss (t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b, int to_print);
void pb(t_stack **a, t_stack **b, int to_print);

void ra (t_stack **a, int to_print);
void rb (t_stack **b, int to_print);
void rr (t_stack **a, t_stack **b);

void rra (t_stack **a, int to_print);
void rrb (t_stack **b, int to_print);
void rrr (t_stack **a, t_stack **b);

int	ft_isdigit(int c);

/// A enlever

void printStack(t_stack *stack) {
    printf("Printing stack contents:\n");
    while (stack != NULL) {
        printf("nbr: %d, cost: %d\n", stack->nbr, stack->cost);
        // printf("CHEAP FUCK\nnbr : %d \nTarget mediane : %d\nMediane : %d\n", stack->nbr, stack->target->above_median, stack->above_median ); /// Target : %d\nLe choix du pauvre : %d\n", stack->nbr, stack->target->nbr, stack->cheapest);
        //  printf("Le coquin pas cher : %d \n", stack->nbr);
        stack = stack->next;
    }
}
void printStackb(t_stack *stack) {
    printf("Printing stack contents:\n");
    while (stack != NULL) {
        printf("ICI CEST B nbr: %d, cost: %d\n", stack->nbr, stack->cost);
        // printf("CHEAP FUCK\nnbr : %d \nTarget mediane : %d\nMediane : %d\n", stack->nbr, stack->target->above_median, stack->above_median ); /// Target : %d\nLe choix du pauvre : %d\n", stack->nbr, stack->target->nbr, stack->cheapest);
        //  printf("Le coquin pas cher : %d \n", stack->nbr);
        stack = stack->next;
    }
}
///////////////// SPLIT ////////////////////// 

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

//// Massive free
/// Frees the char ** as a whole
void    free_array(char **str)
{
    int i = -1;
    while(str[i] != NULL)
        free(str[i++]);
    free(str - 1);
}
/// Frees the stack and  each node
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


// Looks for the biggets nbr inside struct a
t_stack *itsabigboy(t_stack *a)
{
    t_stack *temp;

    temp = a;
    while(a)
    {
        if(a->nbr > temp->nbr)
            temp = a;
        a = a->next;
    }
    return (temp);
}
// Looks for the best node inside stack b, setting the target inside a->target when found
void target_filler1(t_stack *a, t_stack *b)
{
    t_stack *node;
    t_stack *temp_b;


    long    value;

    value = -2147483648;
    while(a->next != NULL)
    {                    

        value = -2147483648;
        temp_b = b;
        while(temp_b)
        {
            if(temp_b->nbr < a->nbr && temp_b->nbr > value)
            {
                value = temp_b->nbr;
                node = temp_b;
            }
            temp_b = temp_b->next;
        }
        if(value == -2147483648)
        {
            node = itsabigboy(b);
            a->target = node;
        }
        else
            a->target = node;  
        a = a->next;
    }
}
t_stack *itstinyboi(t_stack *a)
{
    t_stack *temp;

    temp = a;
    while(a->next != NULL)
    {
        if(a->nbr < temp->nbr)
            temp = a;
        a = a->next;
    }
    return (temp);
}

void target_filler2(t_stack *a, t_stack *b)
{
    t_stack *node;
    t_stack *temp;


    long    value;

    while(b)
    {                    

        value = 2147483647;
        temp = a;
        while(temp)
        {
            if(temp->nbr > b->nbr && temp->nbr < value)
            {
                value = temp->nbr;
                node = temp;
            }
            temp = temp->next;
        }
        if(value == 2147483647)
        {
            b->target = itstinyboi(a);
        }
        else
            b->target = node;  
        b = b->next;
    }
}
/// Sets the cost for each node required to push from a to b
void cost_setter(t_stack *a, t_stack *b)
{
    
    long size_a;
    long size_b;

    size_a = size_stack(a);

    size_b = size_stack(b);
    
    if(!a)
        return ;
    while(a->next != NULL)
    {
        // printf("EEEEEEee On est a %d\n", a->nbr);
        a->cost = a->index;
        if(a->above_median == 0)
            a->cost = size_a - a->index;
        if(a->target->above_median == 0)
            a->cost += size_b - a->target->index;
        else
            a->cost += a->target->index;
        a = a->next;
    }
}
// Returns the node with the first found and lowest a->cost from the stack
t_stack *its_on_sale(t_stack *a)
{
    t_stack *temp;

    temp = a;
    if(!a)
        return 0;
    while(a->next != NULL)
    {
        if(temp->cost > a->cost)
            temp = a;
        a = a->next;
    }
    return (temp);

}

void cheapest_setter(t_stack *a)
{
    int cheap;
    t_stack *temp;

    cheap = 2147483647;
    if(!a)
        return ;

    while (a->next != NULL)
    {
        if (cheap > a->cost)
        {
            cheap = a->cost;
            temp = a;
        }
        a = a->next;
    }
    if(a->cost < cheap)
        temp = a;
    temp->cheapest = 1;

}

// void cheapest_setter2(t_stack **b)
// {
//     long cheap = 2147483647;
//     t_stack *temp = NULL;
//     t_stack *a = *b;

//     // Find the cheapest element
//     while (a->next != NULL)
//     {
//         if (cheap > a->cost)
//         {
//             cheap = a->cost;
//             temp = a;
//         }
//         a = a->next;
//     }
//     if(a)
//         if (cheap > a->cost)
//         {
//             cheap = a->cost;
//             temp = a;
//         }
//     // Set the cheapest flag for the cheapest element
//     if (temp != NULL)
//         temp->cheapest = 1;

// }

// void cheapest_setter(t_stack **b)
// {
//     long cheap;
//     t_stack *temp;
//     t_stack *a;

//     a = *b;
//     cheap = 2147483647;
//     while(a->next != NULL)
//     {
//         if(cheap > a->cost)
//         {
//             cheap = a->cost;
//             temp = a;
//         }
//         a = a->next;
//     }
//     temp->cheapest = 1;
//     printf("test %d\n",(*b)->cheapest);
// }

/// Sorting

/// 3

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

/// Big sort
void set_a_on_top(t_stack **a, t_stack *cheap, t_stack **b)
{
int i = 0;
    if(cheap->above_median == 1)
        while((*a)->nbr != cheap->nbr){    i++; if(i > 40)exit(0);printf("je suis dedans;)\n");
            ra(a, 0);}
    else
        while((*a)->nbr != cheap->nbr)
            rra(a, 1);
}

void set_b_on_top(t_stack **b, t_stack *target)
{

    if(target->above_median == 1)
        while((*b)->nbr != target->nbr)
            rb(b, 1);
    else
        while((*b)->nbr != target->nbr)
            rrb(b, 1);
}
void set_b_on_top2(t_stack **b, t_stack *cheap)
{
    if(cheap->above_median == 1)
        while((*b)->nbr != cheap->nbr)
            rb(b, 1);
    else
        while((*b)->nbr != cheap->nbr)
            rrb(b, 1);
}

void set_a_on_top2(t_stack **a, t_stack *cheap, t_stack **b)
{

    if(cheap->above_median == 1)
        while((*a)->nbr != cheap->nbr)
            ra(a, 1);
    else
        while((*a)->nbr != cheap->nbr)
            rra(a, 1);
}
void    rotate_up_a(t_stack *a, t_stack *b, t_stack *cheap)
{
    while(a->nbr != cheap->nbr && b->nbr != cheap->target->nbr)
        rrr(&a, &b);
        index_setter(a);
    index_setter(b);
}

void    rotate_down_a(t_stack *a, t_stack *b, t_stack *cheap)
{
    while(a->nbr != cheap->nbr && b->nbr != cheap->target->nbr)
        rr(&a, &b);
    index_setter(a);
    index_setter(b);

}
void    rotate_up_b(t_stack *a, t_stack *b, t_stack *cheap)
{
    while(b->nbr != cheap->nbr && a->nbr != cheap->target->nbr)
        rrr(&a, &b);
        index_setter(a);
    index_setter(b);
}

void    rotate_down_b(t_stack *a, t_stack *b, t_stack *cheap)
{
    while(b->nbr != cheap->nbr && a->nbr != cheap->target->nbr)
        rr(&a, &b);
        index_setter(a);
    index_setter(b);
}
void push_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheap;
    t_stack *temp_a;
    t_stack *temp_b;
    

    // temp_a = *a;

    cheap = its_on_sale(*a);

    // printStack(*a);
    // printf("ICI \n");
    // printStack(*a);
    // exit(0);
        // printf("Target de A : %d \n", cheap->nbr);
        // printf("A est a : %d \n", (*a)->nbr);
        // printf("Target de B : %d \n", cheap->target->nbr);
        // printf("B est a : %d \n", (*b)->nbr);
        // exit(0);
    if(cheap->above_median == 1 && cheap->target->above_median == 1)
            rotate_up_a(*a, *b, cheap);
    if (cheap->above_median == 0 && cheap->target->above_median == 0)
            rotate_down_a(*a, *b, cheap);
    printf("Cheap : %d\n", cheap->nbr);
    printStack(*a);printStack(*b);
    set_a_on_top(a, cheap, b);
    set_b_on_top(b, cheap->target);
    pb(a, b, 1);
}


void push_b_to_a(t_stack **a, t_stack **b)
{
            
    t_stack *cheap;

    cheap = its_on_sale(*b);

    // while ((*b)->nbr != cheap->nbr || (*a)->nbr != cheap->target->nbr)
    // {
    if(cheap->above_median == 1 && cheap->target->above_median == 1)
        rotate_up_b(*a, *b, cheap);
    if (cheap->above_median == 0 && cheap->target->above_median == 0)
            rotate_down_b(*a, *b, cheap);
    set_b_on_top2(b, cheap);
    // printf("ici %d", cheap->nbr);
    // exit(0);
    set_a_on_top2(a, cheap->target, b);
    pa(a, b, 1);
}

void    node_setter_a(t_stack *a, t_stack *b)
{
        index_setter(a);
        index_setter(b);
        target_filler1(a, b);
        cost_setter(a, b);
        cheapest_setter(a);
}

void node_setter_b(t_stack *a, t_stack *b)
{
        index_setter(a);
        index_setter(b);

        target_filler2(a, b);


        cost_setter(b, a);

        cheapest_setter(b);
        // printStack(b);
    // printf("SPLIT\n");
    // printStack(a);
}

void real_sort(t_stack **a, t_stack **b)
{
    int size;
    int size_b;
    // b = malloc(sizeof(t_stack));

    size  = size_stack(*a);

    if(size-- > 3 && is_sorted(a) == 1)
        pb(a, b, 1);
    if(size-- > 3 && is_sorted(a) == 1)
        pb(a, b, 1);
    // exit(0);
    while(size > 3 && is_sorted(a) == 1)
    {

        node_setter_a(*a, *b);     
        push_a_to_b(a, b);
        // size--;
        size--;
    }

    if(size == 3 && is_sorted(a))
        sort_three(a);

    // exit(1);
    size = size_stack(*b);
   
    while(size)
    {   
        node_setter_b(*a, *b);
        push_b_to_a(a, b);

        size--;
    }
    sorting_a(a); 
}

/// LF first node by value 
t_stack *first_node(t_stack *t)
{
    t_stack *a = t;
    while(a->value != 1)
        a = a->next;
    return (a);
}
/// Final push
/// Rotates the stack a until the node-> is set at the beggining
void sorting_a(t_stack **a)
{
    t_stack *first_node_value;
// printStack(a);
    // exit(0); 
    index_setter(*a);
    first_node_value = first_node(*a);
    

    while(is_sorted(a))
    {
        if(first_node_value->above_median == 1)
            ra(a, 1);
        else
           { rra(a, 1);printStack(*a);}
    }

}

//// Struc manipulation

/////////////////// A CONTINUER

// Sets the acctual index for each node
void    index_setter(t_stack *a)
{
    int i;
    int median;
    // t_stack *a;

    // a = *stack;
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
// Fills the true placement for each node
void valuefiller(t_stack **t) 
{
    t_stack *current = *t;
    t_stack *compare;

    // Iterate over each node in the list
    while (current != NULL) {
        compare = *t; // Reset comparison pointer to the start of the list
        int smaller_nbr_count = 0; // Counter for smaller nbrs

        // Compare current node's nbr with others to find its position
        while (compare != NULL) {
            if (compare->nbr < current->nbr)
                smaller_nbr_count++; // Increment counter if compared nbr is smaller
            compare = compare->next;
        }

        // Set the current node's value to its position in the sorted order
        current->value = smaller_nbr_count + 1; // Add 1 to convert from 0-based index to 1-based index
        current = current->next; // Move to the next node in the list
    }
}
/// strlen for struct (starts at 1 returns 0 if *a == NULL)
int size_stack(t_stack *a)
{

    if(a == NULL || !a)
        return 0;
    int i = 1;

    while(a->next != NULL)
    {
        a = a->next;
        i++;
    }
    return i;
}
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
/// Checks if there are only digits 
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
        if(arg[j][0] == '\0')
            its_an_error(0, arg, split, 4);
        while(arg[j][i])
        {   
            
            if(check_digit2(arg[j], split, i, digit) == 1)
                its_an_error(0, arg, split, 4);
            if(arg[j][i] >= '0' && arg[j][i] <= '9')
                digit = 1;
            i++;
        }
        j++;
        i = 0;
    }
}

int     check_digit2(char *arg, int split, int i, int digit)
{
    if(i >= 1 && arg[i] == ' ' && arg[i - 1] == ' ' && digit == 1)
        its_an_error(0, 0, split, 4);
    if(i >= 1 && ft_isdigit(arg[i]) == 1 && digit == 1 && !ft_isdigit(arg[i - 1]))
        its_an_error(0, 0, split, 4);
    if(!ft_isdigit(arg[i]))
        if((arg[i] != '-' && arg[i] != '+' && arg[i] != ' ') 
                    || ((arg[i] == '-' || arg[i] == '+') 
                    && (arg[i + 1] == '-' || arg[i + 1] == '+' || arg[i + 1] == '\0')))
            {
                return 1;
            }
    return 0;
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

int is_sorted(t_stack **a)
{
    t_stack *check;
    check = *a;

    while(check->next != NULL)
    {
        if(check->nbr > check->next->nbr)
            return (1);
        check = check->next;
    }
    return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

//// Other
long ft_atol(char *str)
{
    int sign;
    long nbr;

    sign = 1;
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

t_stack *lastnode(t_stack **temp) {
    t_stack *cur;

    if (!temp) // Check if temp or *temp is NULL
        return NULL;
    cur = *temp;
    
    while (cur->next != NULL)
        cur = cur->next;
    return cur;
}




/// Moves 

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
void rra(t_stack **b, int to_print)
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
        return ;
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

int main(int ac, char **arg)
{
    t_stack *a;
    t_stack *b;

    b = malloc(sizeof(t_stack));
    a = NULL;
    b = NULL;
    if(ac == 1)
        return (1);
    if(ac == 2) // si arg "1 2 3"
    { 
        arg = ft_split(arg[1], ' ');
        if(arg[1] == NULL)
            its_an_error(0, arg + 1, ac == 2, 2);
    }
    check_digit(arg + 1, ac == 2);
    init_struct(&a, arg + 1, ac == 2);
    valuefiller(&a);
    if(is_sorted(&a))
    {
        if(size_stack(a) == 2)
            ra(&a, 1);
        if (size_stack(a) == 3)
            sort_three(&a);
        else
            real_sort(&a, &b);
    }
    // printStack(a);
    // printStack(a);
//  printStack(a);
//   printStack(b);
//   pb(&a, &b, 0);
//     pb(&a, &b, 0);
//       pb(&a, &b, 0);
//         pb(&a, &b, 0);
//           pb(&a, &b, 0);
          
   printStack(a);
//   printStack(b);
//   rrr(&a ,&b);
    //  printStack(a);
//   printStack(b);
    stash_free(&a);
    stash_free(&b);

    return (0);
}
