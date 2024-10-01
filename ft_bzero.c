/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:46:20 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:38:43 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_bzero(void *destination, size_t num_size)
{
	size_t i;

	i = 0;
	unsigned char *re_dest = (unsigned char*) destination;

	while (i < num_size)
	{
		re_dest[i] =  0;
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
    ft_bzero(buffer, 8);

    // Imprimimos el resultado después de ft_memset
    printf("Cadena modificada: %s\n", buffer);

    return 0;
}
*/