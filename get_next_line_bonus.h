/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementabraham <clementabraham@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:12:18 by clementabra       #+#    #+#             */
/*   Updated: 2024/12/16 17:06:17 by clementabra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strlen(char const *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*get_next_line(int fd);

#endif