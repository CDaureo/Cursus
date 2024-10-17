/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:30:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/17 17:01:42 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putnbr_recursive(int n)
{
	char	c;
	int		i;

	i = 0;
	if (n > 9)
		i = i + ft_putnbr_recursive(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (i + 1);
}

int	print_number(int num)
{
	int	c;

	c = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		c++;
		num = -num;
	}
	c += ft_putnbr_recursive(num);
	return (c);
}
