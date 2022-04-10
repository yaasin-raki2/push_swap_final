/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:45 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:45 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_sort
{
	int		size;
	int		to_push;
	int		min;
	int		mid;
	int		max;
	int		index;
	int		push_side;
	int		last_n_index;
	t_node	*faked_node;
}	t_sort;

typedef struct s_instructions
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_i;

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	parse_av(t_node **a_head, char **av, char ***args);

void	error_exit(void);
void	init_i(t_i *i);
void	init_stack_a(t_node **a_head, int ac, char **av, int check);

void	check_args(int ac, char **av, int check);
int		check_sorted_stack(t_node *head);

t_node	*create_node(int data);
void	add_to_back(t_node **lst, t_node *new);
t_node	*last_node(t_node *lst);
int		last_node_index(t_node *lst);
void	free_list(t_node *list);
t_node	*before_last_node(t_node *lst);
void	index_stack(t_node **head);
int		find_smallest_index(t_node *lst);
int		list_size(t_node *lst);
int		index_of_node(t_node *lst, int data);
void	push_side(t_node *head, t_sort *s, int min, int max);
int		search_for_index(t_node **b_head, int index);

void	sa(t_node **a_head, t_i *i);
void	sb(t_node **b_head, t_i *i);
void	pa(t_node **a_head, t_node **b_head, t_i *i);
void	pb(t_node **b_head, t_node **a_head, t_i *i);
void	ra(t_node **a_head, t_i *i);
void	rb(t_node **b_head, t_i *i);
void	rra(t_node **a_head, t_i *i);
void	rrb(t_node **b_head, t_i *i);
int		check_instructions(t_i *i);
void	write_previous_instruction(t_i *i);

void	sort_three(t_node **head, t_i *i);
void	sort_four(t_node **a_head, t_node **b_head, t_i *i);
void	sort_five(t_node **a_head, t_node **b_head, t_i *i);
void	sort_six_plus(t_node **a_head, t_node **b_head, t_i *i);

#endif