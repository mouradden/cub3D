/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:32:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 11:44:56 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	store_colors_(t_all *all)
{
	char	*tmp;
	char	c;

	tmp = ft_strtrim(all->map[all->i], " \t");
	if (!tmp)
		return (1);
	if (!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
	{
		c = tmp[0];
		if (count_virgules(tmp) != 2 \
		|| check_numbers(all, ft_strchr(tmp, c)))
		{
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	free(tmp);
	tmp = NULL;
	all->count++;
	return (0);
}

int	colors(t_all *all)
{
	char	*tmp;

	all->i = 0;
	all->count = 0;
	tmp = NULL;
	while (all->map[all->i] && all->count < 6)
	{
		if (!string_empty(all->map[all->i]))
		{
			if (store_colors_(all))
				return (1);
		}
		all->i++;
	}
	return (0);
}

int	num_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

int	check_numbers_(t_all *all, int i, int num)
{
	i = 0;
	while (all->tmp[i])
	{
		if (only_num(all->tmp[i]) || check_num(all->tmp[i]))
			return (1);
		if (num_len(all->tmp[i]) > 10)
			return (1);
		num = ft_atoi(all->tmp[i]);
		if (!(num >= 0 && num <= 255))
			return (1);
		i++;
	}
	return (0);
}

int	check_numbers(t_all *all, char *str)
{
	int	i;

	i = 0;
	all->tmp = ft_split(str, ',');
	if (!all->tmp)
		return (1);
	while (all->tmp[i])
	{
		if (string_empty(all->tmp[i]))
			return (1);
		i++;
	}
	if (check_numbers_(all, 0, 0))
		return (1);
	if (i != 3)
		return (1);
	free_tmp(all);
	return (0);
}
