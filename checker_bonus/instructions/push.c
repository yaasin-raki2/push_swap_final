/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:21 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:21 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	push(t_node **first_head, t_node **second_head)
{
	t_node	*temp;

	if (*second_head)
	{
		temp = *second_head;
		*second_head = (*second_head)->next;
		temp->next = *first_head;
		*first_head = temp;
	}
}

void	pa_b(t_node **a_head, t_node **b_head)
{
	push(a_head, b_head);
}

void	pb_b(t_node **b_head, t_node **a_head)
{
	push(b_head, a_head);
}
