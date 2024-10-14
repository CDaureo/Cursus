/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:05:42 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/14 17:53:26 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);
	char c;
	char *s;
	void *p;
	int	d;
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
				p = va_arg(args,void *);
				ft_put_in_pointer(p);
			}
			if (*format == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr_fd(d,1);
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