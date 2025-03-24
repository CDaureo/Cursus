/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:24 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:30:23 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	temp2 = (char *)src;
	temp1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}
