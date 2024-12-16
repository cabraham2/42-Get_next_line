/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementabraham <clementabraham@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:12:18 by clementabra       #+#    #+#             */
/*   Updated: 2024/12/16 15:43:40 by clementabra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 9223372036854775806
#	undef BUFFER_SIZE
#	define BUFFER_SIZE 0
# endif

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char const *src, unsigned int size);

#endif