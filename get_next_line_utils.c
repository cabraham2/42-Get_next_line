/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementabraham <clementabraham@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:12 by clementabra       #+#    #+#             */
/*   Updated: 2024/12/11 17:44:06 by clementabra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	element;

	element = (unsigned char)c;
	while (*str)
	{
		if (*str == element)
			return ((char *)str);
		str++;
	}
	if (element == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*variablenew;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (src[i])
	{
		i++;
	}
	variablenew = malloc((i + 1) * sizeof(char));
	if (!(variablenew))
		return (NULL);
	while (src[x])
	{
		variablenew[x] = src[x];
		x++;
	}
	variablenew[x] = '\0';
	return (variablenew);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	return (result);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char const *src, unsigned int size)
{
	unsigned int	tdest;
	unsigned int	tsrc;
	unsigned int	concat;

	tdest = 0;
	tsrc = 0;
	concat = 0;
	while (dest[tdest])
		tdest++;
	while (src[tsrc])
		tsrc++;
	if (tdest >= size)
		return (size + tsrc);
	while (concat < (size - tdest - 1) && src[concat])
	{
		dest[tdest + concat] = src[concat];
		concat++;
	}
	dest[tdest + concat] = '\0';
	return (tdest + tsrc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	k;

	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str || !s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (i >= start && k < len)
		{
			sub_str[k] = s[i];
			k++;
		}
		i++;
	}
	sub_str[k] = '\0';
	return (sub_str);
}

unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}