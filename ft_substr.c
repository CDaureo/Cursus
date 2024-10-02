/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:47:14 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/02 14:24:17 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_allocate_substring(size_t len)
{
	char	*substring;

	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	return (substring);
}

size_t	ft_adjust_len(const char *s, unsigned int start, size_t len)
{
	size_t	original_len;

	original_len = ft_strlen(s);
	if (start >= original_len)
		return (0);
	if (len > original_len - start)
		return (original_len - start);
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	original_len;

	original_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= original_len)
	{
		substring = (char *)malloc(1);
		if (substring)
			substring[0] = '\0';
		return (substring);
	}
	len = ft_adjust_len (s, start, len);
	substring = ft_allocate_substring(len);
	if (!substring)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring[i] = '\0', substring);
}
