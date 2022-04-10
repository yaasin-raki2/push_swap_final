/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:08 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:08 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_side(t_node *head, t_sort *s, int min, int max)
{
	t_node	*tail;

	tail = last_node(head);
	while (!(head->index >= min && head->index <= max)
		&& !(tail->index >= min && tail->index <= max))
	{
		head = head->next;
		tail = tail->previous;
	}
	if (head->index >= min && head->index <= max)
		s->push_side = 0;
	else if (tail->index >= min && tail->index <= max)
		s->push_side = 1;
}
