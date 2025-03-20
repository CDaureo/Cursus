/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:56:21 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/17 16:56:34 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_cleaner_aux(char *str, char r)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || !*str)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != r)
			tmp[j++] = str[i];
		i++;
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*ft_cleaner(char *str, char *r)
{
	int	i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (r[i] != '\0')
	{
		str = ft_cleaner_aux(str, r[i]);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}