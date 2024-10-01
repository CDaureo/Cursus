/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:49:48 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:26:52 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return (unsigned char)s1[i] - (unsigned char)s2[i];
		}
		i++;
	}
	return (0);
}
/*
int main(void) {
    const char *str1 = "";
    const char *str2 = "Hola, Mand!";

    // Comparación de los primeros 5 caracteres
    int result = ft_strncmp(str1, str2, 6);
    if (result == 0) {
        printf("%d \n", result);
    } else if (result > 0) {
        printf("%d \n", result);
    } else {
        printf("%d \n", result);
    }

    // Comparación de los primeros 10 caracteres
    result = ft_strncmp(str1, str2, 10);
    if (result == 0) {
        printf("%d \n", result);
    } else if (result > 0) {
        printf("%d \n", result);
    } else {
        printf("%d \n", result);
    }

    // Comparación de los primeros 12 caracteres
    result = ft_strncmp(str1, str2, 24);
    if (result == 0) {
        printf("%d \n", result);
    } else if (result > 0) {
        printf("%d \n", result);
    } else {
        printf("%d \n", result);

    }

    return 0;
}*/
