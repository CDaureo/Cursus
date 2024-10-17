/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:31:23 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/17 17:00:41 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

static int	checker(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_put_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_put_in_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned_recursive(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned long)));
	else if (c == 'X')
		return (ft_putnbr_hex_uc(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
	{
		return (0);
	}
}

int	ft_printf(char const *c, ...)
{
	int			i;
	int			counter;
	va_list		args;

	i = 0;
	counter = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			counter += checker(args, c[i + 1]);
			i++;
		}
		else
			counter += ft_putchar(c[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
