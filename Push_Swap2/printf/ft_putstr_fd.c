/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:19 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:19:20 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 0;
	if (!s)
		return (ft_putstr_fd_printf("(null)", 1));
	while (s[i] != '\0')
	{
		result = ft_putchar_fd_printf(s[i], fd);
		if (result == -1)
		{
			return (-1);
		}
		j += result;
		i++;
	}
	return (j);
}
