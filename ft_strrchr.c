/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:08 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 20:12:41 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		else
			i--;
	}
	if (c == '\0')
	{
		return ((char *)(&s[i]));
	}
	return (NULL);
}
/*
int main (void)
{
	char* s1 = "hohla";
	printf ("%d", ft_strlen(s1));
	printf("%s"	,ft_strrchr(s1, 'w'));
}
*/
