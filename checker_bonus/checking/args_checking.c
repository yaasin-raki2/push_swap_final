/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:49:22 by yerraqui          #+#    #+#             */
/*   Updated: 2022/05/15 11:15:58 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	check_if_int(int ac, char **av, int check)
{
	int	i;
	int	l;

	if (!check)
		l = 0;
	else
		l = 1;
	while (l < ac)
	{
		i = 0;
		while (av[l][i])
		{
			if ((av[l][i] >= '0' && av[l][i] <= '9')
				|| (i == 0 && av[l][i] == '-') || (i == 0 && av[l][i] == '+'))
				i++;
			else
				error_exit();
		}
		l++;
	}
}

static void	check_if_empty(int ac, char **av, int check)
{
	int	i;

	if (!check)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			error_exit();
		i++;
	}
}

void	check_args(int ac, char **av, int check)
{
	check_if_empty(ac, av, check);
	check_if_int(ac, av, check);
}
