/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:50 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/21 15:46:09 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	int i;
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
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	temp2 = (char *)src;
	temp1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}

char *ft_strjoin(char *str_storage, char *buff)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	len1 = ft_strlen(str_storage);
	len2 = ft_strlen(buff);
	if (!str_storage || !buff)
		return (NULL);
	total_len = len1 + len2;
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str_storage, len1);
	ft_memcpy(new_str + len1, buff, len2);
	new_str[total_len] = '\0';
	return (new_str);
}
