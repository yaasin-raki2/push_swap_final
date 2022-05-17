/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:17 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:17 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	parse_av(t_node **a_head, char **av, char ***args)
{
	int		len;

	len = 0;
	*args = ft_split(av[1], ' ');
	if (*args == NULL)
		error_exit();
	while ((*args)[len])
		len++;
	check_args(len, *args, 0);
	init_stack_a(a_head, len, *args, 0);
	return (len);
}
