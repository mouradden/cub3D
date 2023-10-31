/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:44:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/28 14:58:34 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	ray_cast(t_all *data, float angle)
{
	t_ray	horz_ray;
	t_ray	vert_ray;

	vert_ray = get_inters_vertical(data, angle);
	horz_ray = get_inters_horizontals(data, angle);
	if (vert_ray.distance < horz_ray.distance)
		return (vert_ray);
	else
		return (horz_ray);
}

void	draw_ray(t_all *data, t_point src, t_ray ray)
{
	float		step;
	int			i;
	t_point		d;

	d.x = ray.wall_hit_x - src.x;
	d.y = ray.wall_hit_y - src.y;
	step = fabs(d.y);
	if (fabs(d.x) > fabs(d.y))
		step = fabs(d.x);
	i = -1;
	while (++i < step)
	{
		if ((src.x / SCALE >= 0 && src.x / SCALE < data->game->img_2d->width)
			&& (src.y / SCALE >= 0
				&& src.y / SCALE < data->game->img_2d->height))
		{
			if (wall_detected(data, src))
				break ;
			mlx_put_pixel(data->game->img_2d, src.x / SCALE,
				src.y / SCALE, 0xFF0000FF);
		}
		increment(&src, d, step);
	}
}

int	wall_detected(t_all *data, t_point src)
{
	if (data->map[(int)(src.y + 1) / SQUARE_SIZE]
	[(int)(src.x) / SQUARE_SIZE] == '1'
		|| data->map[(int)src.y / SQUARE_SIZE]
		[(int)(src.x + 1) / SQUARE_SIZE] == '1'
		|| data->map[(int)(src.y - 1) / SQUARE_SIZE]
		[(int)(src.x) / SQUARE_SIZE] == '1'
		|| data->map[(int)src.y / SQUARE_SIZE]
		[(int)(src.x - 1) / SQUARE_SIZE] == '1')
		return (1);
	else
		return (0);
}

void	increment(t_point *src, t_point d, float step)
{
	src->x += (d.x) / step;
	src->y += (d.y) / step;
}
