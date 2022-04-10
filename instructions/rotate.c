/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:08 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:08 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = last_node(*head);
		temp->next = *head;
		temp->next->previous = temp;
		*head = (*head)->next;
		(*head)->previous = NULL;
		temp->next->next = NULL;
	}
}

void	ra(t_node **a_head, t_i *i)
{
	rotate(a_head);
	i->ra++;
	if (!check_instructions(i))
	{
		i->ra--;
		write_previous_instruction(i);
		i->ra = 1;
	}
}

void	rb(t_node **b_head, t_i *i)
{
	rotate(b_head);
	i->rb++;
	if (!check_instructions(i))
	{
		i->rb--;
		write_previous_instruction(i);
		i->rb = 1;
	}
}
