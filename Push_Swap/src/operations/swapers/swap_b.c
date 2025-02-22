/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:52:28 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:32:31 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sb(c_stack **b)
{
	c_stack	*tmp;

	if (*b && (*b) -> next)
		return ;
	tmp = (*b)->value; //Guarda el valor del primer nodo en una variable temporal
	(*b)->value = (*b) -> next -> value;
	(*b) -> next -> value = tmp;
	write (1, "sb\n", 3);
}