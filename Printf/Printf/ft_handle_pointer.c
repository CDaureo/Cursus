/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:33:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 12:38:08 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"



static int ft_putnum_hex(unsigned long num)
{
	const char *hex;
	hex = "0123456789abcdef";
	int c;
	c = 0;
	
	if(num >= 16)
		c =+ ft_putnum_hex(num/16);
	ft_putchar(hex[num%16]);
	return (c);
}
int ft_put_in_pointer(void *p)
{
	int c;
	c = 0;
	c =+ ft_put_string("0x");
	c =+ ft_putnum_hex((unsigned long)p);
	return (c);
}