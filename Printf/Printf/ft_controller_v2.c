/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:59:28 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 11:59:28 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_integer(va_list args)
{
	int d = va_arg(args, int);
	return (print_number(d));
}

int	print_unsigned(va_list args)
{
	unsigned int u = va_arg(args, unsigned int);
	return (ft_putnbr_unsigned_recursive(u));
}

int	print_hex_lower(va_list args)
{
	unsigned long x = va_arg(args, unsigned long);
	return (ft_putnbr_hex(x));
}

int	print_hex_upper(va_list args)
{
	unsigned long X = va_arg(args, unsigned long);
	return (ft_putnbr_hex_uc(X));
}