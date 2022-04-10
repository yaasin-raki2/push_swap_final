/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:52:01 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:52:01 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted_stack(t_node *list)
{
	int	num;

	num = list->data;
	while (list->next)
	{
		list = list->next;
		if (num >= list->data)
			return (1);
		num = list->data;
	}
	return (0);
}
