/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:20 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 11:58:20 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_character(va_list args)
{
	char c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	print_string(va_list args)
{
	char *s = va_arg(args, char *);
	return (ft_put_string(s));
}

int	print_pointer(va_list args)
{
	void *p = va_arg(args, void *);
	return (ft_put_in_pointer(p));
}
