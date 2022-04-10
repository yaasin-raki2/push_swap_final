/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:32 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:32 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_index(int *min, int *mid, t_node **head)
{
	t_node	*l;

	l = *head;
	*min = find_smallest_index(*head);
	if (l->index < l->next->index && l->index < l->next->next->index)
	{
		if (l->next->index < l->next->next->index)
			*mid = l->next->index;
		else
			*mid = l->next->next->index;
	}
	else if (l->next->index < l->index && l->next->index < l->next->next->index)
	{
		if (l->index < l->next->next->index)
			*mid = l->index;
		else
			*mid = l->next->next->index;
	}
	else
	{
		if (l->index < l->next->index)
			*mid = l->index;
		else
			*mid = l->next->index;
	}
}

static void	sort_stack(int min, int mid, t_node **head, t_i *i)
{
	if ((*head)->index == min)
	{
		rra(head, i);
		sa(head, i);
	}
	else if ((*head)->index == mid)
	{
		if ((*head)->next->index == min)
			sa(head, i);
		else
			rra(head, i);
	}
	else
	{
		ra(head, i);
		if ((*head)->next->index == min)
			sa(head, i);
	}
}

void	sort_three(t_node **head, t_i *i)
{
	int	min;
	int	mid;

	if (check_sorted_stack(*head) == 0)
		return ;
	set_index(&min, &mid, head);
	sort_stack(min, mid, head, i);
}
