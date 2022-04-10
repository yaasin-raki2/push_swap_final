/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:24 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:24 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_i(t_node **a_head, t_node **b_head, int smallest_i, t_i *i)
{
	t_node	*a_lst;
	int		lst_index;

	a_lst = *a_head;
	lst_index = 0;
	while (a_lst)
	{
		if (a_lst->index == smallest_i)
		{
			while ((*a_head)->index != smallest_i)
			{
				if (lst_index > 2)
					rra(a_head, i);
				else
					ra(a_head, i);
			}
			pb(b_head, a_head, i);
			break ;
		}
		lst_index++;
		a_lst = a_lst->next;
	}
}

void	sort_four(t_node **a_head, t_node **b_head, t_i *i)
{
	int		smallest_index;

	if (check_sorted_stack(*a_head) == 0)
		return ;
	smallest_index = find_smallest_index(*a_head);
	push_i(a_head, b_head, smallest_index, i);
	sort_three(a_head, i);
	pa(a_head, b_head, i);
}
