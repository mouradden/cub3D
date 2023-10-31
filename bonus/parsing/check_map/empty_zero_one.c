/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_zero_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:39:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 17:01:05 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	empty(t_all *all, char c)
{
	if (all->map[all->i][all->j + 1] == c \
	|| all->map[all->i][all->j - 1] == c \
	|| all->map[all->i - 1][all->j] == c \
	|| all->map[all->i + 1][all->j] == c)
		return (1);
	return (0);
}

int	cmp(t_all *all)
{
	if ((ft_strlen(all->map[all->i - 1]) < ft_strlen(all->map[all->i]) \
	&& (ft_strlen(all->map[all->i - 1]) - 1 < (unsigned long)all->j)) \
	|| (ft_strlen(all->map[all->i + 1]) < ft_strlen(all->map[all->i]) \
	&& (ft_strlen(all->map[all->i + 1]) - 1 < (unsigned long)all->j)))
		return (1);
	return (0);
}

int	check_empty(t_all *all)
{
	all->i = identify_the_start(all);
	all->j = 0;
	while (all->map[all->i])
	{
		while (all->map[all->i][all->j])
		{
			if (all->map[all->i][all->j] == '0'\
			|| all->map[all->i][all->j] == 'N'\
			|| all->map[all->i][all->j] == 'W'\
			|| all->map[all->i][all->j] == 'E'\
			|| all->map[all->i][all->j] == 'S')
			{
				if (cmp(all))
					return (1); 
				if (empty(all, 32) || empty(all, '\t') \
				|| empty(all, '\0'))
					return (1);
			}
			all->j++;
		}
		all->j = 0;
		all->i++;
	}
	return (0);
}

int	last_line(t_all *all)
{
	int	i;

	i = identify_the_start(all);
	while (all->map[i])
		i++;
	if (string_empty_one(all->map[i - 1]))
		return (1);
	return (0);
}
