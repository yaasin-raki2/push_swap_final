/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:49:54 by yerraqui          #+#    #+#             */
/*   Updated: 2022/04/04 17:49:54 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	count_strs(char const *s, char c)
{
	int	strs;
	int	check;
	int	i;

	strs = 0;
	check = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			strs++;
		}
		i++;
	}
	return (strs);
}

static int	strs_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_arr(char **arr_strs, int j)
{
	while (j-- > 0)
		free((void *)arr_strs[j]);
	free(arr_strs);
	return (NULL);
}

static char	**allocate(char const *s, char **arr_strs, char c, int strs_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < strs_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr_strs[j] = (char *)malloc(sizeof(char) * strs_len(s, c, i) + 1);
		if (arr_strs[j] == NULL)
			return (free_arr(arr_strs, j));
		while (s[i] != '\0' && s[i] != c)
			arr_strs[j][k++] = s[i++];
		arr_strs[j][k] = '\0';
		j++;
	}
	arr_strs[j] = 0;
	return (arr_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_strs;
	int		strs;

	if (s == NULL)
		return (NULL);
	strs = count_strs(s, c);
	arr_strs = (char **)malloc(sizeof(char *) * (strs + 1));
	if (arr_strs == NULL)
		return (NULL);
	arr_strs = allocate(s, arr_strs, c, strs);
	return (arr_strs);
}
