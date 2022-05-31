/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:51:44 by yerraqui          #+#    #+#             */
/*   Updated: 2022/05/31 07:32:20 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	find_instr_2(char **inst, char **p, t_node ***arr, int ac)
{
	if (ft_strcmp(*inst, "sa\n") == 0)
		sa_b(arr[0]);
	else if (ft_strcmp(*inst, "sb\n") == 0)
		sb_b(arr[1]);
	else if (ft_strcmp(*inst, "ss\n") == 0)
		ss_b(arr[0], arr[1]);
	else if (ft_strcmp(*inst, "pa\n") == 0)
		pa_b(arr[0], arr[1]);
	else if (ft_strcmp(*inst, "pb\n") == 0)
		pb_b(arr[1], arr[0]);
	else if (ft_strcmp(*inst, "ra\n") == 0)
		ra_b(arr[0]);
	else if (ft_strcmp(*inst, "rb\n") == 0)
		rb_b(arr[1]);
	else if (ft_strcmp(*inst, "rr\n") == 0)
		rr_b(arr[0], arr[1]);
	else if (ft_strcmp(*inst, "rra\n") == 0)
		rra_b(arr[0]);
	else if (ft_strcmp(*inst, "rrb\n") == 0)
		rrb_b(arr[1]);
	else if (ft_strcmp(*inst, "rrr\n") == 0)
		rrr_b(arr[0], arr[1]);
	else
		free_and_exit(2, inst, p, ac);
}

static void	find_instruction(char **inst, char **p, t_node ***arr, int ac)
{
	if (ft_strcmp(*inst, "\n") == 0)
		error_exit();
	else
		find_instr_2(inst, p, arr, ac);
}

static void	read_instructions(t_node ***arr, int ac)
{
	char	*inst;
	char	*p;

	inst = ft_strdup("");
	p = NULL;
	p = (char *) malloc(sizeof(char) * 2);
	if (p == NULL || read(0, p, 0) == -1)
		exit(0);
	while (read(0, p, 1) > 0)
	{
		p[1] = '\0';
		inst = ft_strjoin(inst, p);
		if (p[0] == '\n')
		{
			find_instruction(&inst, &p, arr, ac);
			free(inst);
			inst = ft_strdup("");
		}
	}
	if (check_sorted_stack(*arr[0]) == 0 && !(*arr[1]))
		free_and_exit(0, &inst, &p, ac);
	else
		free_and_exit(1, &inst, &p, ac);
}

static void	check_first_param_spaces(const char *str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
			n++;
	}
	if (n == i)
		error_exit();
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*b_head;
	char	**args;
	t_node	***stacks_arr;

	a_head = NULL;
	b_head = NULL;
	args = NULL;
	stacks_arr = init_stacks_arr(&a_head, &b_head);
	if (ac > 1)
		check_first_param_spaces(av[1]);
	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
		ac = parse_av(&a_head, av, &args) + 1;
	else
	{
		check_args(ac, av, 1);
		if (ac < 2)
			exit(0);
		init_stack_a(&a_head, ac, av, 1);
	}
	read_instructions(stacks_arr, ac);
	return (0);
}
