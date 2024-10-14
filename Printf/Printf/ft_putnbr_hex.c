/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:33:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/14 17:43:16 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

static void ft_putnbr_hex(unsigned long num)
{
	const char *hex = "0123456789abcdef";
	void *p;
	if(num >= 16)
		ft_putnbr_hex(num/16);
	ft_putchar(hex[num%16]);
}
void ft_put_in_pointer(void *p)
{
	ft_put_string("0x");
	ft_putnbr_hex((unsigned long)p);
}