/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_last_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:21 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:53:21 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*before_last_node(t_node *lst)
{
	if (lst)
	{
		while (lst->next->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
