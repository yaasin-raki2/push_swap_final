/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_last_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:51:30 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:51:30 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
