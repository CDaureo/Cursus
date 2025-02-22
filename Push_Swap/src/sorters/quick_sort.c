/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:30:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/22 14:30:49 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

void    partition(c_stack **a, c_stack **b, int pivot)
{
	int size;
	int i;
	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((*a) -> value <= pivot)
		{
			pb(a, b);
		} 
		else 
			ra(a);
		i++;
	}
}

void	quick_sort(c_stack **a, c_stack**b)
{
	int pivot;
	
	if (is_sorted(*a))
		return;
	pivot = (*a) -> value;
	partition(a,b,pivot);
	quick_sort(a,b);
	while (*b)
	{
		pa(a,b);
	}
	
}