/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:25:46 by yerraqui          #+#    #+#             */
/*   Updated: 2022/05/31 07:25:55 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_node	***init_stacks_arr(t_node **a_head, t_node **b_head)
{
	t_node	***stacks_arr;

	stacks_arr = (t_node ***)malloc((sizeof(t_node **) * 2) + 1);
	stacks_arr[0] = a_head;
	stacks_arr[1] = b_head;
	stacks_arr[2] = NULL;
	return (stacks_arr);
}
