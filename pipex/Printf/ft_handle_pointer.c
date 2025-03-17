/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:33:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:04 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	ft_put_in_pointer(void *p)
{
	unsigned long long	ptr;
	char				str[19];
	const char			*hex = "0123456789abcdef";
	int					i;
	int					length;

	if (p == NULL)
		return (ft_put_string("(nil)"));
	i = 18;
	ptr = (unsigned long long)p;
	str[i--] = '\0';
	while (ptr != 0)
	{
		str[i--] = hex[ptr % 16];
		ptr /= 16;
	}
	str[i--] = 'x';
	str[i--] = '0';
	length = ft_put_string(&str[i + 1]);
	return (length);
}
