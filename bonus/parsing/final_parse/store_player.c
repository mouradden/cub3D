/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:43:31 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 17:01:49 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	store_player(t_all *all)
{
	int	i;
	int	j;

	i = identify_the_start(all);
	j = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'N' || all->map[i][j] == 'E'
			|| all->map[i][j] == 'S' || all->map[i][j] == 'W')
			{
				all->player = all->map[i][j];
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
