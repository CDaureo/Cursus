/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:07:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:57:42 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void) {
    // Ejemplo 1: Escribir en stdout
    ft_putchar_fd('A', 1); // Escribe 'A' en la salida estándar

    // Ejemplo 2: Escribir en un archivo
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
        ft_putchar_fd('B', fd); // Escribe 'B' en el archivo
        close(fd); // Cerramos el archivo
    return (0);
}
*/