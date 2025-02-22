/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:21 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 16:19:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//INFO: >> Desplaza los bits a la derecha

int get_max_bits(c_stack *stack)
{
	int max;
	int bits;

	max = 0;
	bits = 0;
	if (!stack)
		return (0);
	max = stack->value;
	bits = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack -> value;
		stack = stack -> next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

//TODO: Aplicar el Radix 
//INFO: & 1 toma el bit mas bajo del numero resultante 

void	radix_sort(c_stack **a, c_stack **b)
{
	int 	i;
	int 	j;
	int 	size;
	int 	max;
	int		pushed;
	c_stack	*stack;
	
	size = stack_size(*a);
	max = get_max_bits(*a);
	i=0;
	while (i < max)
	{
		pushed = 0;
		j = 0;
		while (j < size)
		{
			stack = *a;
			if (((stack->value >> i) & 1) == 0)
			{
				pb(a,b);
				pushed++;
			}
			else{
				ra(a);
			}
			j++;
		}
		while (pushed > 0)
		{
			pa(a, b);
			pushed--;
		}
		i++;
		}
	
}
