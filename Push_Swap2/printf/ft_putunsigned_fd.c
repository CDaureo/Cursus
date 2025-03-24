/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:23 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:26:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd_printf(unsigned int n, int fd)
{
	char	str[10];
	int		i;
	int		result;

	if (n == 0)
	{
		return (ft_putchar_fd_printf('0', fd));
	}
	i = 0;
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	result = 0;
	while (i > 0)
	{
		result += ft_putchar_fd_printf(str[--i], fd);
	}
	return (result);
}
