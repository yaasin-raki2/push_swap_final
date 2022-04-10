/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:41 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:41 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(int nums, t_node **a_head, t_node **b_head)
{
	t_i	i;

	init_i(&i);
	if (nums == 2 && check_sorted_stack(*a_head) != 0)
	{
		sa(a_head, &i);
		write_previous_instruction(&i);
		return ;
	}
	else if (nums == 2)
		return ;
	else
		index_stack(a_head);
	if (nums == 3)
		sort_three(a_head, &i);
	else if (nums == 4)
		sort_four(a_head, b_head, &i);
	else if (nums == 5)
		sort_five(a_head, b_head, &i);
	else
		sort_six_plus(a_head, b_head, &i);
	write_previous_instruction(&i);
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*b_head;
	char	**args;

	a_head = NULL;
	b_head = NULL;
	args = NULL;
	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
		parse_av(&a_head, av, &args);
	else
	{
		check_args(ac, av, 1);
		if (ac <= 2)
			exit(0);
		init_stack_a(&a_head, ac, av, 1);
	}
	if (check_sorted_stack(a_head) == 0)
		return (0);
	sort_stack(ac - 1, &a_head, &b_head);
	return (0);
}
