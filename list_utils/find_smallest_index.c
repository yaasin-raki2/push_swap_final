/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:28 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:28 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest_index(t_node *lst)
{
	int	smallest;

	smallest = lst->index;
	while (lst)
	{
		if (lst->index < smallest)
			smallest = lst->index;
		lst = lst->next;
	}
	return (smallest);
}
