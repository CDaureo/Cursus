/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:24 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:55:45 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	temp2 = (char *)src;
	temp1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}
/*
 int main(void) {
	char src[20] = "Hola, Mundo!";
	char dest[20] = "ca";
	printf("Cadena no copiada: %s\n", dest);

	// Copiamos los primeros 12 bytes de src a dest
	ft_memcpy(dest, src, 9);

	// Aseguramos que la cadena copiada en dest sea terminada en '\0'
   // dest[12] = '\0';

	// Imprimimos el resultado
	printf("Cadena copiada: %s\n", dest);

	return (0);

 }
*/