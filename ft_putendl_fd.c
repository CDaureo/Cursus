/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:30:30 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 17:20:27 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	if (!s)
        return;
	int size = ft_strlen(s);
	int i; 
	i = 0;
	while (i < size)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int main() {
    // Escribir en stdout (la consola)
    ft_putendl_fd("Hola, mundo!\n", 1);

    // Escribir en un archivo
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        ft_putendl_fd("Escribiendo en un archivo.\n", fd);
        close(fd);
    }
    
    return 0;
}
*/