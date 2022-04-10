/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:24 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:24 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = before_last_node(*head);
		temp->next->next = *head;
		*head = temp->next;
		temp->next = NULL;
	}
}

void	rra_b(t_node **a_head)
{
	reverse_rotate(a_head);
}

void	rrb_b(t_node **b_head)
{
	reverse_rotate(b_head);
}	

void	rrr_b(t_node **a_head, t_node **b_head)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
}
