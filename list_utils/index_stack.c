/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:41 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:41 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_stack(t_node **head)
{
	t_node	*node_to_index;
	t_node	*lst;

	node_to_index = *head;
	while (node_to_index)
	{
		lst = *head;
		while (lst)
		{
			if (node_to_index->data > lst->data)
				node_to_index->index++;
			lst = lst->next;
		}
		node_to_index = node_to_index->next;
	}
}
