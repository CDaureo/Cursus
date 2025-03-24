/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:31:46 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:57 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str, int *s)
{
	int		i;
	long	sum;
	int		mult;

	i = check_spaces(str);
	sum = 0;
	mult = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		sum = (sum * 10) + (str[i] - '0');
		if ((sum > 2147483647 && mult == 1) || (sum > 2147483648 && mult == -1))
			return (*s = 1, 0);
		i++;
	}
	return (sum * mult);
}
