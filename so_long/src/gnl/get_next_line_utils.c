/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:50 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/28 02:14:22 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;
	i = 0;
	
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *s, int c)
{
	int	i;
	
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dupe;
	size_t	size;


	size = ft_strlen(s);
	dupe = malloc((size + 1) * sizeof(char));
	if (dupe == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char	*ft_strjoin(char *str_storage, char *buff)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!str_storage)
	{
		str_storage = malloc(sizeof(char) + 1);
		if (!str_storage)
			return (0);
		str_storage[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_storage) + ft_strlen(buff)) + 1);
	if (!str)
		return (free(str_storage), str_storage = NULL, NULL);
	i = -1;
	while (str_storage[++i])
		str[i] = str_storage[i];
	c = -1;
	while (buff[++c])
		str[i + c] = buff[c];
	str[i + c] = '\0';
	free(str_storage);
	str_storage = NULL;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;
	size_t	size_len;

	size_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (start > size_len)
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (size_len - start < len)
		len = size_len - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < size_len && i < len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
