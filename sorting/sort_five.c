/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:17 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:17 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_elms(t_node **a_head, t_node **b_head, int smallest_i, t_i *i)
{
	t_node	*lst;
	int		in;

	lst = *a_head;
	while (lst)
	{
		if (lst->index == smallest_i || lst->index == smallest_i + 1)
		{
			while ((*a_head)->index != lst->index)
			{
				in = index_of_node(*a_head, lst->data);
				if (in > 2)
					rra(a_head, i);
				else
					ra(a_head, i);
			}
			lst = lst->next;
			pb(b_head, a_head, i);
		}
		else
			lst = lst->next;
	}
}

void	sort_five(t_node **a_head, t_node **b_head, t_i *i)
{
	int		smallest_index;

	if (check_sorted_stack(*a_head) == 0)
		return ;
	smallest_index = find_smallest_index(*a_head);
	push_elms(a_head, b_head, smallest_index, i);
	sort_three(a_head, i);
	pa(a_head, b_head, i);
	pa(a_head, b_head, i);
	if (check_sorted_stack(*a_head) != 0)
		sa(a_head, i);
}
