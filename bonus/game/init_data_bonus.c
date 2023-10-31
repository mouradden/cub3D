/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:04:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/30 15:54:53 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_data(t_all *all)
{
	all->game->position.x = -1;
	all->game->position.y = -1;
	all->game->mouse_x = 0;
	all->game->mouse_y = 0;
	if (all->player == 'N')
		all->game->player_ang = 270;
	else if (all->player == 'W')
		all->game->player_ang = 0;
	else if (all->player == 'S')
		all->game->player_ang = 90;
	else if (all->player == 'E')
		all->game->player_ang = 180;
	load_textures(all);
}

void	load_textures(t_all *all)
{
	int		i;

	i = -1;
	while (++i < 4)
		all->textures[i] = mlx_load_png(all->pics[i]);
	if (!all->textures[0] || !all->textures[1] \
	|| !all->textures[2] || !all->textures[3])
		free_map_pics_game(all);
	i = -1;
	while (++i < 4)
	{
		if (all->textures[i]->width != 512 \
		|| all->textures[i]->height != 512)
		{
			printf("Error\n");
			free_the_end(all);
			free_map_pics_game(all);
		}
	}
	load_animation(all);
}
