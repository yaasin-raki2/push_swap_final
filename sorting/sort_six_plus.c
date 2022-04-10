/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:28 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:28 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_b(t_sort *s, t_node **a_head, t_node **b_head, t_i *i)
{
	push_side(*a_head, s, s->min, s->max);
	while (!((*a_head)->index >= s->min && (*a_head)->index <= s->max))
	{
		if (s->push_side)
			rra(a_head, i);
		else
			ra(a_head, i);
	}
	pb(b_head, a_head, i);
	if ((*b_head)->index < s->mid && list_size(*b_head) > 1)
		rb(b_head, i);
}

static void	push_wanted_index(int index, t_node **b_head, t_sort *s, t_i *i)
{
	push_side(*b_head, s, index, index);
	if (s->push_side)
		rrb(b_head, i);
	else
		rb(b_head, i);
}

static void	pick(t_node **a_head, t_node **b_head, t_sort *s, t_i *i)
{
	if (search_for_index(b_head, s->index) == 0)
	{
		if ((*b_head)->index < (*a_head)->index
			&& (*b_head)->index > last_node_index(*a_head))
		{
			pa(a_head, b_head, i);
			if ((*a_head)->index != s->index)
				ra(a_head, i);
		}
		else
			push_wanted_index(s->index, b_head, s, i);
	}
	else
		rra(a_head, i);
}

static void	sort_rest(t_node **a_head, t_node **b_head, t_sort *s, t_i *i)
{
	s->faked_node = last_node(*a_head);
	s->last_n_index = s->faked_node->index;
	s->faked_node->index = -1;
	while (*b_head)
	{
		s->index = (*a_head)->index - 1;
		pick(a_head, b_head, s, i);
	}
	s->faked_node->index = s->last_n_index;
	while (check_sorted_stack(*a_head) != 0)
		rra(a_head, i);
}

void	sort_six_plus(t_node **a_head, t_node **b_head, t_i *i)
{
	t_sort	s;

	s.size = list_size(*a_head);
	while (s.size > 5)
	{
		s.to_push = (s.size - 5) / 3 + 1;
		s.min = find_smallest_index(*a_head);
		s.max = s.min + s.to_push - 1;
		s.mid = (s.min + s.max) / 2;
		while (s.to_push)
		{
			push_to_b(&s, a_head, b_head, i);
			s.to_push--;
		}
		s.size = list_size(*a_head);
	}
	sort_five(a_head, b_head, i);
	sort_rest(a_head, b_head, &s, i);
}
