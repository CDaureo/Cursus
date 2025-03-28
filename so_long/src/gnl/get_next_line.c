/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:53 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 00:48:19 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*new_line(char *str_storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str_storage, '\n');
	len = (ptr - str_storage) + 1;
	line = ft_substr(str_storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*cleaner(char *str_storage)
{
	char	*new_storage;
	char	*ptr;

	ptr = ft_strchr(str_storage, '\n');
	if (!ptr || !*(ptr + 1))
		return (free(str_storage), NULL);
	new_storage = ft_strdup(ptr + 1);
	free(str_storage);
	return (new_storage);
}

static char	*reader(int fd, char *str_storage)
{
	ssize_t	i;
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str_storage), NULL);
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		temp = ft_strjoin(str_storage, buff);
		str_storage = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (i == -1)
		return (free(str_storage), NULL);
	return (str_storage);
}

char	*get_next_line(int fd)
{
	static char *str_storage = NULL;
	char *line;


	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!str_storage || !ft_strchr(str_storage, '\n'))
	{
		str_storage = reader(fd ,str_storage);
	}
	if (!str_storage)
		return (NULL);
	
	line = new_line(str_storage);
	if (!line)
	{
		return (free(str_storage), str_storage = NULL, NULL);
	}
	str_storage = cleaner(str_storage);
	return (line);
}