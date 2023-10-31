/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:55:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/29 13:48:44 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') \
		&& (str[i] != 32 && str[i] != '\t'))
			return (1);
		i++;
	}
	return (0);
}

int	check_num(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] == '\t' || tmp[i] == ' ')
		i++;
	while (tmp[i] >= '0' && tmp[i] <= '9')
		i++;
	while (tmp[i] == '\t' || tmp[i] == ' ')
		i++;
	if (tmp[i])
		return (1);
	return (0);
}

int	string_empty(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	string_empty_one(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
		return (0);
	return (1);
}
