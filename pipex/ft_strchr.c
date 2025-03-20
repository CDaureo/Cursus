/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:49:06 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/17 17:04:58 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
		{
			return ((char *)(&s[i]));
		}
		else
			i++;
	}
	if (uc == '\0')
	{
		return ((char *)(&s[i]));
	}
	return (NULL);
}
/*
int main (void)
{
	char* s1 = "hohla";
	printf("%s"	,ft_strchr(s1, 'a'));
}
*/
