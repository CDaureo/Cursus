/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:10 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:19:10 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putexa_fd_printf(unsigned int num, int fd, char c)
{
	const char		*hex_digits_lower;
	const char		*hex_digits_upper;
	char			buffer[9];
	int				i;

	hex_digits_lower = "0123456789abcdef";
	hex_digits_upper = "0123456789ABCDEF";
	buffer[8] = '\0';
	i = 7;
	if (num == 0)
		return (ft_putchar_fd_printf('0', fd));
	while (i >= 0)
	{
		if (c == 'x')
			buffer[i] = hex_digits_lower[num % 16];
		else if (c == 'X')
			buffer[i] = hex_digits_upper[num % 16];
		num /= 16;
		i--;
	}
	i = 0;
	while (buffer[i] == '0')
		i++;
	return (ft_putstr_fd_printf(&buffer[i], fd));
}
