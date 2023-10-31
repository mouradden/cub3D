/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:04:13 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s) - start)
		return (ft_strdup(s + start));
	p = (char *) malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (i < len && start <= ft_strlen(s))
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
