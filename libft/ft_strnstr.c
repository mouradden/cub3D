/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:53:22 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!haystack && len == 0)
		return (0);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			if (ft_strlen(needle) + i <= len)
				return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
