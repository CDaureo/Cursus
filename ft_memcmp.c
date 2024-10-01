/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:13 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:42:15 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	*s1temp = (unsigned char *) s1;
	*s2temp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1temp[i] != s2temp[i])
		{
			return (s1temp[i] - s2temp[i]);
		}
		i++;
	}
	return (0);
}
/*
int main(void) {
    const char str1[] = "Hola, Mundo!";
    const char str2[] = "Holb, Mundo!";

    // Comparamos los primeros 12 bytes de str1 y str2
    int result = ft_memcmp(str1, str2, -1);

    if (result == 0) {
        printf("%d Las dos cadenas 
		son iguales en los primeros 12 bytes.\n",result);
    } else if (result > 0) {
        printf("%d, str1 es mayor que str2 en los primeros 12 bytes.\n",result);
    } else {
        printf("%d str1 es menor que str2 en los primeros 12 bytes.\n",result);
    }

    return 0;
}
*/
