/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:49:15 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:11:10 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t n) {
    size_t src_len = 0;
    size_t i = 0;
	size_t dst_len = 0;
    size_t j = 0;


    while (src[src_len] != '\0') {
        src_len++;
    }
	while (dst[dst_len] != '\0') {
		dst_len++;
    }
	
    if (n <= dst_len) {
        return n + src_len;
    }

    j = dst_len;
    while (src[i] != '\0' && j < n - 1) {
        dst[j] = src[i];
        i++;
        j++;
    }
    dst[j] = '\0';

    return dst_len + src_len;
}
/*
int main(void) {
    char buffer[20] = "Hola, ";
    const char *src = "Mundo!";

    // Usamos ft_strlcat para concatenar src a buffer
    size_t total_len = ft_strlcat(buffer, src, sizeof(buffer));

    // Imprimimos el resultado
    printf("Cadena destino (después de concatenar): %s\n", buffer);
    printf("Longitud total intentada: %zu\n", total_len);

    // Ahora probamos con un tamaño menor de buffer
    char small_buffer[10] = "Hola, ";
    total_len = ft_strlcat(small_buffer, src, sizeof(small_buffer));

    printf("Cadena destino con buffer más pequeño: %s\n", small_buffer);
    printf("Longitud total intentada (buffer pequeño): %zu\n", total_len);

    return 0;
}
*/
