/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:21 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/26 19:30:25 by cdaureo-         ###   ########.fr       */
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
	int		prevalue;
	int		value;
	prevalue = -1;
	size = stack_size(*a);
	max = get_max_bits(*a);
	if (max > 7)
	max = 7;
	i=0;
	while (i < max)
	{
		pushed = 0;
		j = 0;
		while (j < size)
		{
			value = (*a)->value;
			
			if (((value >> i) & 1) == 0)
			{
				pb(a,b);
				pushed++;
			}
			else{
				if (value != prevalue) // Solo rota si el valor es diferente al anterior
				ra(a);
				prevalue = value; // Actualiza el valor anterior
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



