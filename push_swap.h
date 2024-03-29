/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakojic <dakojic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:02:54 by dakojic           #+#    #+#             */
/*   Updated: 2024/03/29 11:06:06 by dakojic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

////////////////// STRUCT /////////////////////
typedef struct s_stack
{
	int				nbr;
	int				value;
	int				index;
	int				above_median;
	int				cost;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;
//// Proto
void	index_setter(t_stack *a);
void	valuefiller(t_stack **t);
void	stash_free(t_stack **a);
int		size_stack(t_stack *a);
void	free_array(char **str);
int		check_digit2(char *arg, int split, int i, int digit);
void	check_digit(char **arg, int split);
long	ft_atol(char *str);
int		double_check(t_stack **b, long nb);
void	struct_filler(t_stack **a, long nb);
t_stack	*lastnode(t_stack **temp);
int		is_sorted(t_stack **a);
void	sorting_a(t_stack **a);
t_stack	*first_node(t_stack *a);
void	its_an_error(t_stack **a, char **arg, int split, int check);
void	sort_three(t_stack **full);
void	real_sort(t_stack **a, t_stack **b);
void	node_setter_a(t_stack *a, t_stack *b);
void	node_setter_b(t_stack *a, t_stack *b);
void	push_a_to_b(t_stack **a, t_stack **b);
void	push_b_to_a(t_stack **a, t_stack **b);
void	target_filler(t_stack *a, t_stack *b);
t_stack	*itsabigboy(t_stack *a);
t_stack	*itstinyboi(t_stack *a);
t_stack	*its_on_sale(t_stack *a);
void	rotate_up_a(t_stack **a, t_stack **b, t_stack *cheap);
void	rotate_down_a(t_stack **a, t_stack **b, t_stack *cheap);
void	rotate_up_b(t_stack **a, t_stack **b, t_stack *cheap);
void	rotate_down_b(t_stack **a, t_stack **b, t_stack *cheap);
void	target_filler1(t_stack *a, t_stack *b);
void	target_filler2(t_stack *true_a, t_stack *b);
void	cost_setter(t_stack *a, t_stack *b);
void	cheapest_setter(t_stack *a);
void	cost_setter(t_stack *a, t_stack *b);
void	set_a_on_top(t_stack **a, t_stack *cheap);
void	set_b_on_top(t_stack **b, t_stack *target);
void	set_b_on_top2(t_stack **b, t_stack *cheap);
void	set_a_on_top2(t_stack **a, t_stack *target);
void	sa(t_stack **a, int to_print);
void	sb(t_stack **b, int to_print);
void	ss(t_stack **a, t_stack **b, int to_print);
void	pa(t_stack **a, t_stack **b, int to_print);
void	pb(t_stack **a, t_stack **b, int to_print);
void	ra(t_stack **a, int to_print);
void	rb(t_stack **b, int to_print);
void	rr(t_stack **a, t_stack **b, int to_print);
void	rra(t_stack **a, int to_print);
void	rrb(t_stack **b, int to_print);
void	rrr(t_stack **a, t_stack **b, int to_print);
char	**ft_split(char const *str, char c);
void	init_struct(t_stack **a, char **arg, int split);
int		ft_isdigit(int c);
#endif
