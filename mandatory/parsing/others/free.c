/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:54:54 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 18:18:43 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_tmp(t_all *all)
{
	int	i;

	i = 0;
	if (all->tmp)
	{
		while (all->tmp[i])
		{
			free(all->tmp[i]);
			i++;
		}
		free(all->tmp);
		all->tmp = NULL;
	}
}

void	free_map(t_all *all)
{
	int	i;

	i = 0;
	if (all->map)
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map);
		all->map = NULL;
	}
}

void	free_all_ccs(t_all *all)
{
	int	i;

	i = 0;
	if (all->cc)
	{
		while (all->cc[i])
		{
			free(all->cc[i]);
			i++;
		}
		free(all->cc);
		all->cc = NULL;
	}
	i = 0;
	if (all->cc1)
	{
		while (all->cc1[i])
		{
			free(all->cc1[i]);
			i++;
		}
		free(all->cc1);
		all->cc1 = NULL;
	}
}

void	free_pics(t_all *all)
{
	int	i;

	i = 0;
	if (all->pics)
	{
		while (all->pics[i])
		{
			free(all->pics[i]);
			i++;
		}
		free(all->pics);
		all->pics = NULL;
	}
}
