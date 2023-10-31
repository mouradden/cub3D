/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:03 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/27 20:08:55 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	mouse_hook(t_all *all)
{
	int32_t		tmp_mouse;

	tmp_mouse = all->game->mouse_x;
	mlx_get_mouse_pos(all->game->mlx, &all->game->mouse_x, &all->game->mouse_y);
	if (tmp_mouse > all->game->mouse_x)
	{
		if (all->game->mouse_x < WIDTH && all->game->mouse_x >= 0
			&& all->game->mouse_y < HEIGHT && all->game->mouse_y >= 0)
			all->game->player_ang = bound_angle(all->game->player_ang - 3);
	}
	if (tmp_mouse < all->game->mouse_x)
	{
		if (all->game->mouse_x < WIDTH && all->game->mouse_x >= 0
			&& all->game->mouse_y < HEIGHT && all->game->mouse_y >= 0)
			all->game->player_ang = bound_angle(all->game->player_ang + 3);
	}
}

void	mouse(double x, double y, void	*par)
{
	t_all	*all;

	(void)y;
	all = par;
	mlx_set_cursor_mode(all->game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(all->game->mlx, WIDTH / 2, HEIGHT / 2);
	all->game->player_ang = bound_angle(all->game->player_ang
			+ ((x - WIDTH / 2) * SENS));
}
