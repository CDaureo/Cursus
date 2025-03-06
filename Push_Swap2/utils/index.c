/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:35:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:16:51 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Ordena un arreglo de enteros usando el algoritmo de ordenación por burbuja.
 * @param arr Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 */
void	bsort(int *arr, int n)
{
	int	swapped;
	int	i;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		n--;
	}
}

/**
 * Convierte una lista enlazada en un arreglo de enteros.
 * @param a Puntero a la pila 'a'.
 * @param size Tamaño de la lista.
 * @return Un arreglo de enteros con los valores de la lista.
 */
int	*list_to_array(c_stack *a, int size)
{
	int		*arr;
	int		i;
	c_stack	*tmp;

	i = 0;
	tmp = a;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (tmp)
	{
		arr[i++] = *(int *)(tmp->numbers);
		tmp = tmp->next;
	}
	bsort(arr, size);
	return (arr);
}

/**
 * Asigna un índice a cada elemento de la pila 'a' basado en el orden de los valores.
 * @param a Puntero a la pila 'a'.
 * @param arr Arreglo con los valores ordenados.
 * @param size Tamaño de la lista.
 */
void	index_assign(c_stack *a, int *arr, int size)
{
	int		i;
	c_stack	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = a;
		while (tmp)
		{
			if (arr[i] == *(int *)(tmp->numbers))
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

/**
 * Establece los índices para los elementos de la pila 'a' basándose en el orden de los valores.
 * @param a Puntero al puntero de la pila 'a'.
 * @return La pila 'a' con los índices asignados.
 */
c_stack	*set_index(c_stack **a)
{
	int	size;
	int	*arr;

	size = list_size(*a);
	arr = list_to_array(*a, size);
	if (!arr)
		return (NULL);
	index_assign(*a, arr, size);
	free(arr);
	return (*a);
}