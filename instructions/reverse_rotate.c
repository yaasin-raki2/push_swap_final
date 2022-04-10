/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:05 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:05 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = before_last_node(*head);
		temp->next->next = *head;
		*head = temp->next;
		temp->next = NULL;
		(*head)->previous = NULL;
		(*head)->next->previous = *head;
	}
}

void	rra(t_node **a_head, t_i *i)
{
	reverse_rotate(a_head);
	i->rra++;
	if (!check_instructions(i))
	{
		i->rra--;
		write_previous_instruction(i);
		i->rra = 1;
	}
}

void	rrb(t_node **b_head, t_i *i)
{
	reverse_rotate(b_head);
	i->rrb++;
	if (!check_instructions(i))
	{
		i->rrb--;
		write_previous_instruction(i);
		i->rrb = 1;
	}
}
