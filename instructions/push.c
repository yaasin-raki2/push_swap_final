/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:01 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:01 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **first_head, t_node **second_head)
{
	t_node	*temp;

	if (*second_head)
	{
		temp = *second_head;
		*second_head = (*second_head)->next;
		if (*second_head)
			(*second_head)->previous = NULL;
		temp->next = *first_head;
		if (*first_head)
			(*first_head)->previous = temp;
		*first_head = temp;
	}
}

void	pa(t_node **a_head, t_node **b_head, t_i *i)
{
	write_previous_instruction(i);
	push(a_head, b_head);
	i->pa = 1;
}

void	pb(t_node **b_head, t_node **a_head, t_i *i)
{
	write_previous_instruction(i);
	push(b_head, a_head);
	i->pb = 1;
}
