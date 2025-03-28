/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:35 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:35 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_unsigned_recursive(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
	{
		c = c + ft_putnbr_unsigned_recursive(n / 10);
	}
	ft_putchar((n % 10) + '0');
	return (c + 1);
}
