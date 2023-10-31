/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:20:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 12:46:19 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	load_animation(t_all *all)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 10)
	{
		path = ft_strjoin_("./textures/", ft_itoa(i));
		all->anim[i] = mlx_load_png(path);
		if (!all->anim[i])
		{
			free(path);
			free_the_end(all);
			free_map(all);
			free_pics(all);
			exit(1);
		}
		free(path);
		path = NULL;
		i++;
	}
}

void	animation(void *p)
{
	t_all				*all;
	static mlx_image_t	*im;
	static int			i;
	static int			s;

	all = p;
	mlx_delete_image(all->game->mlx, im);
	if (s % ANI_SPEED == 0)
		i++;
	if (i == ANI_NUM)
		i = 0;
	im = mlx_texture_to_image(all->game->mlx, all->anim[i]);
	if (!im)
		free_error(all);
	if (mlx_image_to_window(all->game->mlx, im, 1100, 50) == -1)
		free_error(all);
	s++;
	if (s == ANI_SPEED * ANI_NUM)
		s = 0;
}
