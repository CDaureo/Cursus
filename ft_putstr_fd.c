/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:13:02 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:58:01 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;
	int	i;

	if (!s)
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
int	main(void) {
    // Escribir en stdout (la consola)
    ft_putstr_fd("Hola, mundo!\n", 1);

    // Escribir en un archivo
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        ft_putstr_fd("Escribiendo en un archivo.\n", fd);
        close(fd);
    }
    
    return (0);
}
*/