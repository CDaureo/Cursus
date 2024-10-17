/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_int_uc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:48:16 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 11:48:16 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_hex_uc(unsigned long num)
{
	int			c;
	const char	*hex;

	c = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
	{
		c = c + ft_putnbr_hex_uc(num / 16);
	}
	ft_putchar(hex[num % 16]);
	return (c + 1);
}
