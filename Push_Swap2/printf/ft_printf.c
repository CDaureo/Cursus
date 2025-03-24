/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:39 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:27:19 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_c(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd_printf(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_printf(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putpointer_fd_printf(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_printf(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunsigned_fd_printf(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putexa_fd_printf(va_arg(args, unsigned int), 1, c));
	else if (c == '%')
		return (ft_putchar_fd_printf('%', 1));
	else
	{
		return (0);
	}
}

int	ft_printf(char const *c, ...)
{
	int			i;
	int			count;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			count += handle_c(args, c[i + 1]);
			i++;
		}
		else
			count += ft_putchar_fd_printf(c[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
