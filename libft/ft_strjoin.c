/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:25:34 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/30 11:04:18 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p;
	size_t	j;

	i = -1;
	j = 0;
	if (!s2[0] && !s1)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	p = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free((char *)s1);
	return (p);
}

char	*ft_strjoin_(char const *s1, char const *s2)
{
	size_t	i;
	char	*p;
	size_t	j;

	i = -1;
	j = 0;
	if (!s2[0] && !s1)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	p = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free((char *)s2);
	return (p);
}
