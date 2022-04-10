/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:52:58 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:52:58 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	write_previous_instruction(t_i *i)
{
	if (i->sa == 1)
		write(1, "sa\n", 3);
	else if (i->sb == 1)
		write(1, "sb\n", 3);
	else if (i->pa == 1)
		write(1, "pa\n", 3);
	else if (i->pb == 1)
		write(1, "pb\n", 3);
	else if (i->ra == 1)
		write(1, "ra\n", 3);
	else if (i->rb == 1)
		write(1, "rb\n", 3);
	else if (i->rra == 1)
		write(1, "rra\n", 4);
	else if (i->rrb == 1)
		write(1, "rrb\n", 4);
	init_i(i);
}

int	check_instructions(t_i *i)
{
	if (i->ra == 1 && i->rb == 1)
	{
		write(1, "rr\n", 3);
		init_i(i);
		return (1);
	}
	else if (i->rra == 1 && i->rrb == 1)
	{
		write(1, "rrr\n", 4);
		init_i(i);
		return (1);
	}
	else
		return (0);
}
