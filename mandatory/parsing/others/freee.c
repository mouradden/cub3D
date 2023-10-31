/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:18:52 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 12:35:26 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_line_map(t_all *all)
{
	if (all->line)
	{
		free(all->line);
		all->line = NULL;
	}
	free_map(all);
}

void	free_map_pics_game(t_all *all)
{
	if (all->game)
	{
		free(all->game);
		all->game = NULL;
	}
	free_map(all);
	free_pics(all);
	exit (1);
}

void	free_map_two(t_all *all)
{
	int	i;

	i = 0;
	if (all->final)
	{
		while (all->final[i])
		{
			free(all->final[i]);
			i++;
		}
		free(all->final);
		all->final = NULL;
	}
}
