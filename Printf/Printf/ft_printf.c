/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:05:42 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/14 17:20:27 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);
	char c;
	char *s;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				ft_putchar(c);
			}
			if (*format == 's')
			{
				s = va_arg(args, char *);
				ft_put_string(s);
			}
			if (*format == 'p')
			{
				/* code */
			}
			if (*format == 'd')
			{
				/* code */
			}			
			if (*format == 'i')
			{
				/* code */
			}			
			if (*format == 'u')
			{
				/* code */
			}
			if (*format == 'x')
			{
				/* code */
			}
			if (*format == 'X')
			{
				/* code */
			}
			if (*format == '%')
			{
				/* code */
			}
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (c);
}