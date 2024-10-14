/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:30:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/14 17:52:17 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}
/*
int	main(void)
{
	int	fd;

    // Abrimos un archivo en modo escritura para usar su file descriptor
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    if (fd == -1)
    {
        // Error al abrir el archivo
        write(1, "Error abriendo el archivo\n", 26);
        return (1);
    }
    // Llamamos a la función con varios valores para probarla
    ft_putnbr_fd(42, fd);     // Debe escribir "42"
    write(fd, "\n", 1);       // Escribir un salto de línea
    ft_putnbr_fd(-12345, fd); // Debe escribir "-12345"
    write(fd, "\n", 1);
    ft_putnbr_fd(0, fd);      // Debe escribir "0"
    write(fd, "\n", 1);
    ft_putnbr_fd(2147483647, fd); // Debe escribir "2147483647"
    write(fd, "\n", 1);
    ft_putnbr_fd(-2147483648, fd); // Debe escribir "-2147483648"
    write(fd, "\n", 1);
    // Cerramos el archivo
    close(fd);
    
    return (0);
}
*/