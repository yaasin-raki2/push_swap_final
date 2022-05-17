/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:53:49 by yerraqui          #+#    #+#             */
/*   Updated: 2022/05/16 13:57:54 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_dup_m(t_node **a_head)
{
	t_node *tmp;
	t_node *tmp2;
	
	tmp = *a_head;
	while (tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->data == tmp2->data)
				error_exit();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	init_stack_a(t_node **a_head, int ac, char **av, int check)
{
	int		i;
	t_node	*new_node;

	if (!check)
		i = -1;
	else
		i = 0;
	while (++i < ac)
	{
		if ((!check && i == -1) || (check == 1 && i == 0))
			*a_head = create_node(ft_atoi(av[i]));
		else
		{
			new_node = create_node(ft_atoi(av[i]));
			add_to_back(a_head, new_node);
		}
	}
	check_dup_m(a_head);
}
