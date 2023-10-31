/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:09:47 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/28 18:16:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_h_texture(t_all *data, t_ray ray, mlx_texture_t **texture)
{
	*texture = data->textures[0];
	if (ray.angle < 0 || ray.angle > 180)
		*texture = data->textures[1];
}

void	choose_v_texture(t_all *data, t_ray ray, mlx_texture_t **texture)
{
	*texture = data->textures[2];
	if (ray.angle < 270 && ray.angle > 90)
		*texture = data->textures[3];
}

void	draw_text(t_all *data, t_d_point d_point, float h, mlx_texture_t *tex)
{
	t_int_point		p1;
	t_int_point		p2;
	uint8_t			*px;
	uint8_t			*pi;

	p1.x = d_point.texture.x;
	p1.y = 2;
	p2.x = d_point.my_image.x;
	p2.y = d_point.my_image.y - 1;
	if (h > data->game->img_3d->height)
		p1.y = (h - data->game->img_3d->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int)data->game->img_3d->height - 1 && ++p1.y < h - 1)
	{
		d_point.texture.y = p1.y * (float)tex->height / h;
		if (d_point.texture.y < tex->height
			&& (d_point.texture.y * tex->width + p1.x)
			< tex->width * tex->height)
		{
			px = get_px_index(tex, d_point, p1);
			pi = get_pi_index(data, tex, p2);
			ft_memmove(pi, px, tex->bytes_per_pixel);
		}
	}
}
