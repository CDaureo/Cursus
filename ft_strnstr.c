/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:49:59 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:13:37 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i = 0;
	size_t j = 0;
	
	//COMPROBACION DE MISMO TEXTO
	if (little[0] == '\0') {
		return (char *)big;
	}
	//
	while (big[i] != '\0' && i < len) {
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len) {
			j++;
			if (little[j] == '\0') {
				return (char *)&big[i];
			}
		}
		i++;
	}
	return (0);
}
/*
int main(void) {
    const char *big = "Hola, este es un ejemplo.";
    const char *little = "este";

    // Caso 1: La subcadena existe en los primeros 20 caracteres
    char *result = ft_strnstr(big, little, 20);
    if (result) {
        printf("Subcadena encontrada: %s\n", result);
    } else {
        printf("Subcadena no encontrada.\n");
    }

    // Caso 2: La subcadena no existe en los primeros 10 caracteres
    result = ft_strnstr(big, little, 10);
    if (result) {
        printf("Subcadena encontrada: %s\n", result);
    } else {
        printf("Subcadena no encontrada.\n");
    }

    // Caso 3: Buscar una cadena vacía (debería devolver el inicio de big)
    result = ft_strnstr(big, "", 20);
    if (result) {
        printf("Subcadena vacía encontrada: %s\n", result);
    }

    return 0;
}
*/
