/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:31:38 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 17:02:39 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	check_path(t_all *all)
{
	char	*test;

	all->i = 0;
	all->count = 0;
	test = NULL;
	while (all->map[all->i] && all->count < 6)
	{
		if (!string_empty(all->map[all->i]))
		{
			test = ft_strtrim(all->map[all->i], " \t");
			if (!test)
				return (1);
			if (path(test))
			{
				free(test);
				return (1);
			}
			free(test);
			test = NULL;
			all->count++;
		}
		all->i++;
	}
	return (0);
}

int	path(char *s)
{
	if (!ft_strncmp(s, "NO", 2) \
	|| !ft_strncmp(s, "SO", 2) \
	|| !ft_strncmp(s, "EA", 2) \
	|| !ft_strncmp(s, "WE", 2))
	{
		if (ft_strncmp(s + ft_strlen(s) - 4, ".png", 4) != 0)
			return (1);
	}
	return (0);
}
