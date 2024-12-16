/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementabraham <clementabraham@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:13:20 by clementabra       #+#    #+#             */
/*   Updated: 2024/12/11 17:39:56 by clementabra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_to_stash(char *stash, const char *readed)
{
	char	*new_stash;

	if (!readed)
		return (stash);
	if (!stash)
		return (ft_strdup(readed));
	if (readed[0] == '\0')
		return (stash);
	new_stash = ft_strjoin(stash, readed);
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

int		line_finded(char *stash)
{
	int	i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	extract_line(char **stash)
{
	int	newline_index;
	char	*line;
	char	*tmp;

	if (!*stash || !**stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	newline_index = line_finded(*stash);
	if (newline_index >= 0)
	{
		line = ft_substr(*stash, 0, newline_index + 1);
		tmp = ft_strdup(*stash + newline_index + 1);
	}
	else
	{
		line = ft_strdup(*stash);
		tmp = NULL;
	}
	free(*stash);
	*stash = tmp;
	return (line);
}

char	read_file(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = malloc((sizeof (char)) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!save || !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[bytes] = add_to_stash(save, buff);
		if (!save)
			return (free(buff), NULL);
	}
	free(buff);
	return (save);
}

char	get_next_line(int fd)
{
	if (fd < 1 || BUFFER_SIZE <= 0)
		return (NULL);
	
}