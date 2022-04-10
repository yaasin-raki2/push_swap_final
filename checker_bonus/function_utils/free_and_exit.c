/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:49:46 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:49:46 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	free_and_exit(int x, char **inst, char **p)
{
	free(*inst);
	free(*p);
	if (x == 0)
		write(1, "OK\n", 3);
	else if (x == 1)
		write(1, "KO\n", 3);
	else if (x == 2)
		error_exit();
	exit(0);
}
