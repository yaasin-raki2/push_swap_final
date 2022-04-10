/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:51:36 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:51:36 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
}
