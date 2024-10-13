/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:10:26 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/01 17:10:26 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_num_to_str(char *str, long num, int len)
{
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
}

static int	ft_check_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//Funcion Principal
char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;

	num = n;
	len = ft_check_len(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	ft_convert_num_to_str(str, num, len);
	return (str);
}

/*
int main(void) {
    int numbers[] = {0, 123, -123, 2147483647, -2147483648};
    char *result;
    int i;

    for (i = 0; i < 5; i++) {
        result = ft_itoa(numbers[i]);
        if (result) {
            printf("El número %d convertido 
			a string es: %s\n", numbers[i], result);
            free(result); // Recuerda liberar la memoria después de usarla
        } else {
            printf("Error al convertir el número %d\n", numbers[i]);
        }
    }

    return 0;
}
*/