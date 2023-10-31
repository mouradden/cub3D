/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:22:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	long	i;
	long	count;

	i = n;
	count = 0;
	if (i < 0)
	{
		i = i * (-1);
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

static char	*kteb(char *p, long len, long bo, long i)
{
	while (len >= bo)
	{
		p[len] = i % 10 + 48;
		i = i / 10;
		len--;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*p;
	int		bo;

	i = n;
	bo = 0;
	len = length(i);
	p = (char *) malloc (len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (i < 0)
	{
		bo = 1;
		i = i * (-1);
		p[0] = '-';
	}
	len--;
	return (kteb(p, len, bo, i));
}
