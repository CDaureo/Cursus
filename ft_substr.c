/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:47:14 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 17:42:08 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(const char  *s, unsigned int start, size_t len)
{
	char *substring;
	size_t i;
	size_t original_len;
	original_len = 0;
	i = 0;

	if (!s)
		return NULL;
	
	
	while (s[original_len] != '\0') {
		original_len++;
	}	
	
	if (start >= original_len)
	{
		substring = (char *)malloc(1);
        if (substring)
            substring[0] = '\0';
        return substring;
	}
	
	if (len > original_len - start)
        len = original_len - start;


	// Reservamos espacio +1 para añadir el NULL
	substring = (char *)malloc((len + 1) * sizeof(char));

	if (!substring)
        return NULL;

	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	
	return (substring);
}
