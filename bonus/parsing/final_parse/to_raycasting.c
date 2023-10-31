/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:42:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 17:07:50 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

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
	get_scale(all);
}

void	get_scale(t_all *data)
{
	int		len_rows;
	int		len_cols;

	len_cols = count_cols(data->final);
	len_rows = count_rows(data->final);
	if (len_cols <= 10 || len_rows <= 10)
		data->scale = 4;
	else if (len_cols <= 20 || len_rows <= 20)
		data->scale = 6;
	else if (len_cols <= 30 || len_rows <= 30)
		data->scale = 8;
	else if (len_cols <= 65 || len_rows <= 40)
		data->scale = 10;
}
