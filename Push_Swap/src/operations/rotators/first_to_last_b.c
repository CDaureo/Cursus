/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_to_last_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:51:41 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:56 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rb(c_stack **b)
{
	c_stack	*tmp;

	if (!b || !*b || !(*b)->next) // Si hay menos de 2 elementos, no hace nada
		return ;
	tmp = extract(b);  // Extrae el primer nodo
	add_last_stack(b, tmp);  // Lo agrega al final del stack
	
	
}