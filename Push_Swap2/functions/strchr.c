/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:39 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:27:09 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	int				size;
	unsigned char	c2;

	i = 0;
	c2 = (unsigned char )c;
	size = ft_strlen(s);
	while (i < size +1)
	{
		if ((unsigned char)s[i] == c2)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
