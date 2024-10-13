/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:46:03 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 19:14:13 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_n_or_p(int counter, int number, int counter_negatives)
{
	if (counter >= 2)
		return (0);
	else if (counter_negatives == 1)
		number = -number;
	return (number);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	counter;
	int	counter_negatives;

	number = 0;
	counter = 0;
	counter_negatives = 0;
	while (is_whitespace(*nptr))
		nptr++;
	while (is_sign(*nptr))
	{
		counter++;
		if (*nptr == '-')
			counter_negatives++;
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9'))
	{
		number = (number * 10) + (*nptr - '0');
		nptr++;
	}
	number = ft_is_n_or_p(counter, number, counter_negatives);
	return (number);
}
/*
int main() {
    char str1[] = "   -123";
    char str2[] = "+456";
    char str3[] = "789abc";
    char str4[] = "   ---42";
    char str5[] = "  ++10";
    
    printf("'%s' -> %d\n", str1, ft_atoi(str1));  // -123
    printf("'%s' -> %d\n", str2, ft_atoi(str2));  // 456
    printf("'%s' -> %d\n", str3, ft_atoi(str3)); 
	 // 789 (se detiene en el primer carácter no numérico)
    printf("'%s' -> %d\n", str4, ft_atoi(str4));  
	// 0 (porque los signos dobles no son válidos)
    printf("'%s' -> %d\n", str5, ft_atoi(str5)); 
	 // 0 (signos dobles no son válidos)

    return 0;
}
*/