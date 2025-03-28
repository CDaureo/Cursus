/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:10:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/17 16:58:47 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_put_string(char *s)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	if (!s)
		return (ft_put_string("(null)"));
	while (s[i] != '\0')
	{
		res = ft_putchar(s[i]);
		if (res == -1)
		{
			return (-1);
		}
		j += res;
		i++;
	}
	return (j);
}
