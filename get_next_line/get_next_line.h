/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:47:09 by mdenguir          #+#    #+#             */
/*   Updated: 2023/10/25 16:52:59 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
char	*free_buf(char *buffer);
char	*ft_read_line(char *buffer);

#endif