/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:57:01 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/21 17:10:40 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	numwords(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == 32 || s[i] == '\t') && s[i] != '\0')
			i++;
		if (s[i] != 32 && s[i] != '\t' && s[i] != '\0')
			count++;
		while (s[i] != 32 && s[i] != '\t' && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**splitpath(char *s, char **p, int i)
{
	int		j;
	int		k;
	int		len;

	j = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '\t' || s[i] == 32)
			i++;
		j = i - 1;
		while (s[++j] != '\t' && s[j] != 32 && s[j] != '\0')
			len++;
		if (s[i] == '\0')
		{
			p[k] = 0;
			break ;
		}
		p[k++] = ft_substr(s, i, len);
		len = 0;
		i = j;
	}
	return (p);
}

char	**split_two(char *s)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((numwords(s) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (splitpath(s, p, i));
}
