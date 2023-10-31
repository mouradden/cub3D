/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inters_horizontals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:41:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/28 12:23:30 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

t_ray	get_inters_horizontals(t_all *data, float angle)
{
	t_ray		ray;
	t_point		p_intercept_h;

	p_intercept_h.y = floor(data->game->position.y / SQUARE_SIZE) * SQUARE_SIZE;
	if (angle > 0 && angle < 180)
		p_intercept_h.y += SQUARE_SIZE;
	if (angle < 0 || angle > 180)
		p_intercept_h.y -= 0.001;
	p_intercept_h.x = data->game->position.x
		+ (p_intercept_h.y - data->game->position.y)
		/ tan(angle * (M_PI / 180));
	get_wall_inters_h(data, &p_intercept_h, angle);
	ray.wall_hit_x = p_intercept_h.x;
	ray.wall_hit_y = p_intercept_h.y;
	ray.angle = angle;
	ray.distance = distace_two_points(data->game->position, p_intercept_h);
	ray.is_horz = 1;
	return (ray);
}

void	get_wall_inters_h(t_all *data, t_point *p_intercept_h, float angle)
{
	float		x_step;
	float		y_step;
	t_point		p_check;

	y_step = SQUARE_SIZE;
	if (angle < 0 || angle > 180)
		y_step *= -1;
	x_step = y_step / tan(angle * (M_PI / 180));
	while (p_intercept_h->x >= 0 && p_intercept_h->y >= 0
		&& p_intercept_h->x < count_cols(data->map) * SQUARE_SIZE
		&& p_intercept_h->y < count_rows(data->map) * SQUARE_SIZE)
	{
		p_check.x = floor(p_intercept_h->x / SQUARE_SIZE);
		p_check.y = floor(p_intercept_h->y / SQUARE_SIZE);
		if ((p_check.y >= count_cols(data->map)
				|| p_check.x >= ft_strlen(data->map[(int) p_check.y]))
			|| data->map[(int) p_check.y][(int) p_check.x] != '0')
			break ;
		else
		{
			p_intercept_h->x += x_step;
			p_intercept_h->y += y_step;
		}
	}
}
