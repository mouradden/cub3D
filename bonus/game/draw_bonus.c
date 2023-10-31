/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:42:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:54 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_rays(t_all *data)
{
	int			i;
	t_ray		ray;
	float		var_ang;
	float		ang_step;

	ang_step = 60.0 / WIDTH;
	var_ang = data->game->player_ang - 30;
	var_ang = bound_angle(var_ang);
	i = -1;
	while (++i < WIDTH)
	{
		ray = ray_cast(data, var_ang);
		ray.distance = ray.distance
			* cos((var_ang - data->game->player_ang) * (M_PI / 180));
		draw_ray(data, data->game->position, ray);
		build_wall(data, ray, i);
		var_ang += ang_step;
		var_ang = bound_angle(var_ang);
	}
}

void	draw_block(t_all *data, mlx_image_t *canvas, \
	double point[2], long color)
{
	int				col;
	int				row;
	t_point			pos;

	pos.x = point[0];
	pos.y = point[1];
	row = -1;
	while (++row < SQUARE_SIZE)
	{
		col = -1;
		while (++col < SQUARE_SIZE)
		{
			if ((pos.x + col) / data->scale > 0
				&& (pos.y + row) / data->scale > 0
				&& (pos.x + col) / data->scale < canvas->width
				&& (pos.y + row) / data->scale < canvas->height)
				mlx_put_pixel(canvas, (pos.x + col) / data->scale,
					(pos.y + row) / data->scale, color);
		}
	}
}

void	draw_play(t_all *all, long color)
{
	int				col;
	int				row;
	t_point			pos;

	pos.x = all->game->position.x;
	pos.y = all->game->position.y;
	row = -1;
	while (++row < PLAYER_SIZE)
	{
		col = -1;
		while (++col < PLAYER_SIZE)
		{
			if ((pos.x + col) / all->scale > 0
				&& (pos.x + col) / all->scale < WIDTH
				&& (pos.y + row) / all->scale > 0
				&& (pos.y + row) / all->scale < HEIGHT)
				mlx_put_pixel(all->game->img_2d, (pos.x + col) / all->scale,
					(pos.y + row) / all->scale, color);
		}
	}
}
