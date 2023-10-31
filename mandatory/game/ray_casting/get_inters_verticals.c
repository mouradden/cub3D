/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inters_verticals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:36:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/28 12:24:44 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	get_inters_vertical(t_all *data, float angle)
{
	t_ray		ray;
	t_point		p_intercept_v;

	p_intercept_v.x = floor((double)data->game->position.x / SQUARE_SIZE)
		* SQUARE_SIZE;
	if (angle < 90 || angle > 270)
		p_intercept_v.x += SQUARE_SIZE;
	if (angle > 90 && angle < 270)
		p_intercept_v.x -= 0.001;
	p_intercept_v.y = data->game->position.y
		+ ((p_intercept_v.x - data->game->position.x)
			* tan(angle * (M_PI / 180)));
	get_wall_inters_v(data, &p_intercept_v, angle);
	ray.wall_hit_x = p_intercept_v.x;
	ray.wall_hit_y = p_intercept_v.y;
	ray.angle = angle;
	ray.distance = distace_two_points(data->game->position, p_intercept_v);
	ray.is_horz = 0;
	return (ray);
}

void	get_wall_inters_v(t_all *data, t_point *p_intercept_v, float angle)
{
	float		x_step;
	float		y_step;
	t_point		p_check;

	x_step = SQUARE_SIZE;
	if (angle < 270 && angle > 90)
		x_step *= -1;
	y_step = x_step * tan(angle * (M_PI / 180));
	while (p_intercept_v->x >= 0 && p_intercept_v->y >= 0
		&& p_intercept_v->x < count_cols(data->map) * SQUARE_SIZE
		&& p_intercept_v->y < count_rows(data->map) * SQUARE_SIZE)
	{
		p_check.x = floor(p_intercept_v->x / SQUARE_SIZE);
		p_check.y = floor(p_intercept_v->y / SQUARE_SIZE);
		if ((p_check.y < count_cols(data->map)
				&& p_check.x < count_cols(data->map))
			&& data->map[(int)p_check.y][(int)p_check.x] == '1')
			break ;
		else
		{
			p_intercept_v->x += x_step;
			p_intercept_v->y += y_step;
		}
	}
}
