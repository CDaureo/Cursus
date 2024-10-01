/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:57:24 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/27 15:57:24 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_is_in_set(char c, char const *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *trimmed_str;
    size_t start;
    size_t end;
    size_t len;

    if (!s1 || !set)
        return (NULL);

    // Encuentra el índice de inicio (primer carácter no presente en set)
    start = 0;
    while (s1[start] && ft_is_in_set(s1[start], set))
        start++;

    // Encuentra el índice de fin (último carácter no presente en set)
    end = strlen(s1);
    while (end > start && ft_is_in_set(s1[end - 1], set))
        end--;

    // Calcula la longitud de la nueva cadena y reserva memoria
    len = end - start;
    trimmed_str = (char *)malloc(sizeof(char) * (len + 1));
    if (!trimmed_str)
        return (NULL);

    // Copia la parte recortada en la nueva cadena
    strncpy(trimmed_str, &s1[start], len);
    trimmed_str[len] = '\0';

    return (trimmed_str);
}