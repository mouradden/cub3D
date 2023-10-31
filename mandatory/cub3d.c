/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:15:14 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/30 13:51:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_the_end(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(all->textures[i]);
		i++;
	}
	if (all->game)
	{
		free(all->game);
		all->game = NULL;
	}
	free_map(all);
	free_pics(all);
}

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
	read_map(av[1], &all);
	if (is_map_valid(&all))
	{
		printf("Error\n");
		return (1);
	}
	parsing(&all);
	all.map = all.final;
	create_window_and_images(&all);
	init_data(&all);
	mlx_loop_hook(all.game->mlx, close_window, &all);
	mlx_loop_hook(all.game->mlx, moving_hook, &all);
	mlx_loop(all.game->mlx);
	mlx_terminate(all.game->mlx);
	free_the_end(&all);
	return (EXIT_SUCCESS);
}
