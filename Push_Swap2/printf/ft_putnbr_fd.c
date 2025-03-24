/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:15 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:26:28 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int nb, int fd)
{
	int		result;
	char	str[10];
	int		i;

	result = 0;
	i = 0;
	if (nb < 0)
	{
		result += ft_putchar_fd_printf('-', fd);
		nb = -nb;
	}
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i > 0)
	{
		result += ft_putchar_fd_printf(str[--i], fd);
	}
	return (result);
}

int	ft_putnbr_fd_printf(int n, int fd)
{
	if (n == 0)
	{
		return (ft_putchar_fd_printf('0', fd));
	}
	else if (n == 2147483647)
	{
		return (ft_putstr_fd_printf("2147483647", fd));
	}
	else if (n == -2147483648)
	{
		return (ft_putstr_fd_printf("-2147483648", fd));
	}
	else
	{
		return (ft_putnbr(n, fd));
	}
}
