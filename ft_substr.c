/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:47:14 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/26 18:23:46 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(const char  *s, unsigned int start, size_t len)
{
	char *substring;
	size_t i;
	i = 0;
	if (!s)
		return NULL;
	
	size_t original_len = 0;
	
	while (s[original_len] != '\0') {
		original_len++;
	}	
	if (start >= original_len)
		return ft_strdup("");

	// Reservamos espacio +1 para añadir el NULL
	substring = malloc(len + 1 * sizeof(char));
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	
	return (substring);
}
