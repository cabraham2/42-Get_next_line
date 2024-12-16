/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementabraham <clementabraham@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:12 by clementabra       #+#    #+#             */
/*   Updated: 2024/12/16 16:27:49 by clementabra      ###   ########.fr       */
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

char	*ft_strdup(const char *src)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	while (s1 && *s1)
		*joined++ = *s1++;
	while (s2 && *s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (joined - len1 - len2);
}
