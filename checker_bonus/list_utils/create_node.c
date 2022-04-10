/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:51:33 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:51:33 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_node	*create_node(int data)
{
	t_node	*new_element;

	new_element = NULL;
	new_element = (t_node *) malloc(sizeof(t_node));
	if (new_element == NULL)
		return (NULL);
	new_element->data = data;
	new_element->index = 0;
	new_element->next = NULL;
	return (new_element);
}
