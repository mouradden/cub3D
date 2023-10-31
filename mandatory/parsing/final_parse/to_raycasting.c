/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:42:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 17:05:48 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parsing(t_all *all)
{
	store_player(all);
	store_colors(all);
	store_pictures(all);
	store_map(all);
	free_line_map(all);
	if (count_rows(all->final) > 40 || count_cols(all->final) > 65)
	{
		printf("Error\n");
		free_pics(all);
		free_map_two(all);
		exit (1);
	}
}
