/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:55:52 by cdaureo-            #+#    #+#             */
/*   Updated: 2024/09/27 15:55:52 by cdaureo-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *new_str;
    size_t len1;
    size_t len2;
    size_t total_len;

    if (!s1 || !s2)
        return (NULL);
    
    len1 = strlen(s1);
    len2 = strlen(s2);
    total_len = len1 + len2;

    // Reservamos memoria para la nueva cadena, incluyendo el carácter nulo al final
    new_str = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!new_str)
        return (NULL);

    // Copiamos la primera cadena (s1) en la nueva cadena
    ft_memcpy(new_str, s1, len1);

    // Concatenamos la segunda cadena (s2) a continuación de la primera
    ft_memcpy(new_str + len1, s2, len2);

    // Agregamos el carácter nulo al final
    new_str[total_len] = '\0';

    return new_str;
}