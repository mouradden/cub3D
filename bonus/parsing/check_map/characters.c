/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:34:44 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 17:00:55 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	check_map_characters(t_all *all)
{
	initialize_vars(all);
	all->i = identify_the_start(all);
	if (!all->map[all->i])
		return (1);
	all->str = ft_strnstr(all->line, all->map[all->i], ft_strlen(all->line));
	if (!all->str)
		return (1);
	all->i = 0;
	if (count_chars(all))
		return (1);
	if ((all->no == 1 || all->so == 1 || all->ea == 1 || all->we == 1) \
	&& (all->no + all->so + all->ea + all->we == 1))
		return (0);
	return (1);
}

int	identify_the_start(t_all *all)
{
	int	i;

	i = 0;
	while (all->map[i] && (string_empty(all->map[i]) \
	|| (ft_strnstr(all->map[i], "NO", ft_strlen(all->map[i])) \
	|| ft_strnstr(all->map[i], "SO", ft_strlen(all->map[i])) \
	|| ft_strnstr(all->map[i], "WE", ft_strlen(all->map[i])) \
	|| ft_strnstr(all->map[i], "EA", ft_strlen(all->map[i])) \
	|| ft_strnstr(all->map[i], "F", ft_strlen(all->map[i])) \
	|| ft_strnstr(all->map[i], "C", ft_strlen(all->map[i])))))
	{
		i++;
	}
	return (i);
}

int	count_chars(t_all *all)
{
	while (all->str[all->i])
	{
		if (all->str[all->i] == 'N')
			all->no++;
		else if (all->str[all->i] == 'S')
			all->so++;
		else if (all->str[all->i] == 'E')
			all->ea++;
		else if (all->str[all->i] == 'W')
			all->we++;
		else if (all->str[all->i] != 'W' && all->str[all->i] != 'E'\
		&& all->str[all->i] != 'S' && all->str[all->i] != 'N'\
		&& all->str[all->i] != '\n' && all->str[all->i] != '1'\
		&& all->str[all->i] != '0' && all->str[all->i] != '\t' \
		&& all->str[all->i] != 32)
			return (1);
		all->i++;
	}
	return (0);
}
