/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:29:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 11:42:12 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialize_vars(t_all *all)
{
	all->i = 0;
	all->count = 0;
	all->no = 0;
	all->so = 0;
	all->ea = 0;
	all->we = 0;
	all->f = 0;
	all->c = 0;
	all->wid = 0;
}

void	count_characters(t_all *all)
{
	char	*test;

	test = ft_strtrim(all->map[all->i], " \t");
	if (!test)
	{
		free_line_map(all);
		exit(1);
	}
	if (!ft_strncmp(test, "NO", 2))
		all->no++;
	if (!ft_strncmp(test, "SO", 2))
		all->so++;
	if (!ft_strncmp(test, "EA", 2))
		all->ea++;
	if (!ft_strncmp(test, "WE", 2))
		all->we++;
	if (!ft_strncmp(test, "F", 1))
		all->f++;
	if (!ft_strncmp(test, "C", 1))
		all->c++;
	free(test);
	test = NULL;
}

int	all_characters_exits(t_all *all)
{
	char	*test;
	int		j;

	test = NULL;
	initialize_vars(all);
	j = identify_the_start(all);
	while (all->map[all->i] && all->i < j)
	{
		if (!string_empty(all->map[all->i]))
			count_characters(all);
		all->i++;
	}
	if (all->no != 1 || all->so != 1 || all->ea != 1 \
	|| all->we != 1 || all->f != 1 || all->c != 1)
		return (1);
	return (0);
}

int	names_correct(t_all *all)
{
	all->i = 0;
	while (all->line[all->i])
	{
		if ((!ft_strncmp(&all->line[all->i], "NO", 2) \
		|| !ft_strncmp(&all->line[all->i], "SO", 2) \
		|| !ft_strncmp(&all->line[all->i], "EA", 2) \
		|| !ft_strncmp(&all->line[all->i], "WE", 2)) \
		&& (all->line[all->i + 2] != 32 && all->line[all->i + 2] != '\t'))
			return (1);
		if ((!ft_strncmp(&all->line[all->i], "F", 1) \
		|| !ft_strncmp(&all->line[all->i], "C", 1)) \
		&& (all->line[all->i + 1] != 32 && all->line[all->i + 1] != '\t'))
			return (1);
		all->i++;
	}
	return (0);
}
