/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:10:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkfirst(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && checkfirst(s1[i], set) == 1)
		i++;
	s1 = s1 + i;
	len = ft_strlen(s1);
	while (len > 0 && checkfirst(s1[len - 1], set) == 1)
		len--;
	p = (char *) malloc (len + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s1, len);
	p[len] = '\0';
	return (p);
}
