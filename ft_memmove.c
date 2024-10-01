/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:36 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:56:26 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && s + n > d)
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
/*
int	main(void) {
	char str[50] = "Hola, Mundo!";

	// Imprimimos la cadena original
	printf("Cadena original: %s\n", str);

	// Usamos ft_memmove para copiar parte de la cadena sobre sí misma
	ft_memmove(str + 7, str, 6);  // Copiamos "Hola, " sobre "Mundo!"

	// Imprimimos el resultado después de ft_memmove
	printf("Resultado después de ft_memmove: %s\n", str);

	return (0);
}
*/