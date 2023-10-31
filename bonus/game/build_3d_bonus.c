/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:38:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/27 22:09:26 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	build_wall(t_all *data, t_ray ray, int i)
{
	t_point		p;

	p.x = i;
	p.y = ((HEIGHT / 2) - (((HEIGHT / 2) * SQUARE_SIZE) / ray.distance));
	draw_columns(data, p, HEIGHT - (p.y * 2), ray);
}

void	draw_columns(t_all *data, t_point p, float height, t_ray ray)
{
	t_d_point		d_point;
	mlx_texture_t	*texture;
	float			width_ratio;

	d_point.my_image.x = p.x;
	d_point.my_image.y = p.y;
	if (ray.is_horz)
	{
		choose_h_texture(data, ray, &texture);
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		d_point.texture.x = fmod(ray.wall_hit_x, SQUARE_SIZE) * (width_ratio);
		if (ray.angle > 0 && ray.angle < 180)
			d_point.texture.x = texture->width - 1 - d_point.texture.x;
	}
	else
	{
		choose_v_texture(data, ray, &texture);
		width_ratio = (float)(texture->width / SQUARE_SIZE);
		d_point.texture.x = fmod(ray.wall_hit_y, SQUARE_SIZE) * (width_ratio);
		if (ray.angle < 270 && ray.angle > 90)
			d_point.texture.x = texture->width - 1 - d_point.texture.x;
	}
	draw_text(data, d_point, height, texture);
}

uint8_t	*get_px_index(mlx_texture_t *tex, t_d_point d_point, t_int_point p1)
{
	return (&tex->pixels[((int)d_point.texture.y * tex->width + p1.x)
			* tex->bytes_per_pixel]);
}

uint8_t	*get_pi_index(t_all *data, mlx_texture_t *tex, t_int_point p2)
{
	return (&data->game->img_3d->pixels[(p2.y
				* (data->game->img_3d->width) + p2.x)
			* tex->bytes_per_pixel]);
}
