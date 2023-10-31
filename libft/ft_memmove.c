/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:41:27 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dd;
	char	*ss;

	ss = (char *) src;
	dd = (char *) dst;
	if (dd == 0 && ss == 0)
		return (0);
	if (dst < src)
	{
		ft_memcpy(dd, ss, len);
		return (dst);
	}
	while (len > 0)
	{
		dd[len - 1] = ss[len - 1];
		len--;
	}
	return (dst);
}
