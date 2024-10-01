/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:46 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:54 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *destination, int value, size_t num_size)
{
	size_t i;

	i = 0;
	unsigned char *ptr = (unsigned char *) destination;

	while (i < num_size)
	{
		ptr[i] =  (unsigned char) value;
		i++;
	}
	return (destination);
}
/*
int main(void) {
    char buffer[20] = "Hola, Mundo!";

    // Imprimimos la cadena original
    printf("Cadena original: %s\n", buffer);

    // Usamos ft_memset para llenar los primeros 5 bytes con el carácter 'X'
    ft_memset(buffer, 'X', 5);

    // Imprimimos el resultado después de ft_memset
    printf("Cadena modificada: %s\n", buffer);

    return 0;
}
*/