/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:54:11 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:54:11 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_for_index(t_node **b_head, int index)
{
	t_node	*lst;

	lst = *b_head;
	while (lst)
	{
		if (lst->index == index)
			return (0);
		lst = lst->next;
	}
	return (1);
}
