/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:27 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:27 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = last_node(*head);
		temp->next = *head;
		*head = (*head)->next;
		temp->next->next = NULL;
	}
}

void	ra_b(t_node **a_head)
{
	rotate(a_head);
}

void	rb_b(t_node **b_head)
{
	rotate(b_head);
}

void	rr_b(t_node **a_head, t_node **b_head)
{
	rotate(a_head);
	rotate(b_head);
}
