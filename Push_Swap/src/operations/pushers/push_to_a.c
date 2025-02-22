/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:30:24 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	pa(c_stack **a, c_stack **b)
{
	c_stack	*tmp;

	if (!b || !*b)  // Si b está vacío, no hace nada
		return ;
	write (1, "pa\n", 3);
	tmp = extract(b);  // Extrae el primer nodo de b
	add_first_stack(a, tmp);  // Lo agrega al inicio de a
}
