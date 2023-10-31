/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:35:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**splitpath(char *s, char **p, char c, int i)
{
	int		j;
	int		k;
	int		len;

	j = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i - 1;
		while (s[++j] != c && s[j] != '\0')
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

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((numwords(s, c) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (splitpath(s, p, c, i));
}
