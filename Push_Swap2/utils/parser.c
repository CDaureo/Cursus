/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:19:33 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:18:01 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Libera la memoria ocupada por el arreglo de cadenas de caracteres.
 * @param tmp Doble puntero a un arreglo de cadenas de caracteres.
 */
void	free_split(char ***tmp)
{
	int		j;
	char	**str;

	j = 0;
	str = *tmp;
	while (str[j] != NULL)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

/**
 * Inicializa un arreglo de enteros para almacenar los números.
 * @param c Puntero a un entero donde se almacenará el contador de elementos.
 * @param a Puntero al stack 'a'.
 * @return Un puntero a un arreglo de enteros o NULL si hay un error.
 */
int	*init_nums(int **c, c_stack **a)
{
	int	*nums;

	nums = malloc(2147483646 * sizeof(int));
	if (!nums)
	{
		clear(a, free);
		return (NULL);
	}
	**c = 0;
	return (nums);
}

/**
 * Analiza el argumento pasado como una cadena y procesa los números.
 * Si el argumento contiene espacios, los divide y procesa cada número.
 * @param arg Cadena de caracteres que contiene los números a procesar.
 * @param nums Arreglo donde se almacenarán los números.
 * @param c Puntero a un contador de números procesados.
 * @param a Puntero al stack 'a'.
 * @return 0 si todo está bien, -1 si ocurre un error.
 */
int	parser(const char *arg, int *nums, int *c, c_stack **a)
{
	char	**str;

	if (ft_strchr(arg, ' ') != NULL)
	{
		str = ft_split(arg, ' ');
		if (!str)
		{
			clear(a, free);
			return (-1);
		}
		if (parser_str(str, nums, c, a) == -1)
			return (-1);
	}
	else if (arg[0] != '\0')
	{
		if (validator(arg, nums, c, a) == -1)
			return (-1);
	}
	return (0);
}

/**
 * Analiza y valida cada cadena de números.
 * @param str Arreglo de cadenas que contienen los números a procesar.
 * @param nums Arreglo donde se almacenarán los números.
 * @param c Puntero a un contador de números procesados.
 * @param a Puntero al stack 'a'.
 * @return 0 si todo está bien, -1 si ocurre un error.
 */
int	parser_str(char **str, int *nums, int *c, c_stack **a)
{
	int	j;

	j = 0;
	while (str[j] != NULL)
	{
		if (validator(str[j], nums, c, a) == -1)
		{
			free_split(&str);
			return (-1);
		}
		j++;
	}
	free_split(&str);
	return (0);
}

/**
 * Valida un número pasado como cadena, convirtiéndolo a entero.
 * @param str Cadena que contiene el número a validar.
 * @param nums Arreglo donde se almacenará el número.
 * @param c Puntero a un contador de números procesados.
 * @param a Puntero al stack 'a'.
 * @return 0 si el número es válido, -1 si hay un error.
 */
int	validator(const char *str, int *nums, int *c,
		c_stack **a)
{
	int	comparer;

	comparer = 0;
	nums[*c] = ft_atoi(str, &comparer);
	if (comparer || (nums[*c] == 0 && valid_number(str) == 1))
	{
		clear(a, free);
		return (-1);
	}
	(*c)++;
	return (0);
}
