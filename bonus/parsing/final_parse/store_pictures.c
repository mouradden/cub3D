/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pictures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:45:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 17:01:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	to_pics(t_all *all, char *tmp, char *tmp1)
{
	if (!ft_strncmp(tmp, "NO", 2))
		all->pics[0] = ft_substr(tmp1, 0, ft_strlen(tmp1));
	else if (!ft_strncmp(tmp, "EA", 2))
		all->pics[1] = ft_substr(tmp1, 0, ft_strlen(tmp1));
	else if (!ft_strncmp(tmp, "SO", 2))
		all->pics[2] = ft_substr(tmp1, 0, ft_strlen(tmp1));
	else if (!ft_strncmp(tmp, "WE", 2))
		all->pics[3] = ft_substr(tmp1, 0, ft_strlen(tmp1));
}

void	store_them(t_all *all)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strtrim(all->map[all->i], " \t");
	if (!tmp)
	{
		free_line_map(all);
		exit (1);
	}
	tmp1 = ft_strtrim(tmp + 2, " \t");
	if (!tmp1)
	{
		free(tmp);
		free_line_map(all);
		exit (1);
	}
	to_pics(all, tmp, tmp1);
	all->count++;
	free(tmp);
	tmp = NULL;
	free(tmp1);
	tmp1 = NULL;
}

void	store_pictures(t_all *all)
{
	all->pics = malloc(sizeof(char *) * 5);
	if (!all->pics)
	{
		free_line_map(all);
		exit (1);
	}
	all->i = 0;
	all->count = 0;
	while (all->map[all->i] && all->count < 6)
	{
		if (!string_empty(all->map[all->i]))
			store_them(all);
		all->i++;
	}
	all->pics[4] = NULL;
}
