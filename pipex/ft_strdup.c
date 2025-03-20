/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:57:03 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/17 17:06:21 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dupe;
	size_t	size;

	i = 0;
	size = ft_strlen((char *)s);
	dupe = malloc(size + 1 * sizeof(char));
	if (dupe == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
/*
int	main(void) {
    const char *original = "Hola, mundo!";
    char *duplicado = ft_strdup(original);

    if (duplicado != NULL) {
        printf("Cadena original: %s\n", original);
        printf("Cadena duplicada: %s\n", duplicado);

    } else {
        printf("Error al duplicar la cadena\n");
    }

    return (0);
}
*/