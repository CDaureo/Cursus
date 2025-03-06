/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:08:03 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 15:21:43 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

void	bubble_sort(int *arr, int n)
{
	int	swap;
	int	i;
	int	tmp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
		n--;
	}
}
int	*sorted_indexes(c_stack *a, int size)
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
		arr[i++] = *(int *)(tmp->number);
		tmp = tmp->next;
	}
	bubble_sort(arr, size);
	return (arr);
}
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
			if (arr[i] == *(int *)(tmp->number))
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

c_stack	*set_index(c_stack **a)
{
	int	size;
	int	*arr;

	size = stack_size(*a);
	arr = sorted_indexes(*a, size);
	if (!arr)
		return (NULL);
	index_assign(*a, arr, size);
	free(arr);
	return (*a);
}