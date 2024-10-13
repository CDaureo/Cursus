/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:47:58 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:35:32 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		if (temp[i] == (unsigned char) c)
		{
			return (&temp[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void) {
    const char str[] = "Hola, Mundo!";
    char c = 'M';
    
    // Llamamos a ft_memchr para 
	encontrar el primer 'M' en los primeros 12 bytes
    char *result = (char *)ft_memchr(str, c, 7);

    if (result != NULL) {
        printf("Carácter '%c' encontrado: %s\n", c, result);
    } else {
        printf("Carácter '%c' no encontrado en los primeros 12 bytes.\n", c);
    }

    return 0;
}
*/
