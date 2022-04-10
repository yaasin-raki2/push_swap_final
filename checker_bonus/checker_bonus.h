/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:51:48 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:51:48 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

void	error_exit(void);
void	free_and_exit(int x, char **inst, char **p);

void	check_args(int ac, char **av, int check);
int		check_sorted_stack(t_node *list);

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	parse_av(t_node **a_head, char **av, char ***args);

t_node	*create_node(int data);
void	init_stack_a(t_node **a_head, int ac, char **av, int check);
void	add_to_back(t_node **lst, t_node *new);
t_node	*before_last_node(t_node *lst);
t_node	*last_node(t_node *lst);

void	pa_b(t_node **a_head, t_node **b_head);
void	pb_b(t_node **b_head, t_node **a_head);
void	sa_b(t_node **a_head);
void	sb_b(t_node **b_head);
void	ss_b(t_node **a_head, t_node **b_head);
void	ra_b(t_node **a_head);
void	rb_b(t_node **b_head);
void	rr_b(t_node **a_head, t_node **b_head);
void	rra_b(t_node **a_head);
void	rrb_b(t_node **b_head);
void	rrr_b(t_node **a_head, t_node **b_head);

#endif