/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:49:06 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/24 17:41:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return (char *)(&s[i]);
		}		
		else 
			i++;		
	}
	if (c == '\0')
	{
		return (char *)(&s[i]);
	}
	return (0);
}
/*
int main (void)
{
	char* s1 = "hohla";
	printf("%s"	,ft_strchr(s1, 'a'));
}
*/
