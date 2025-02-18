/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:50:18 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:48:10 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	pb(c_stack **a, c_stack **b)
{
	c_stack	*tmp;

	if (!a || !*a)  // Si b está vacío, no hace nada
		return ;
	tmp = extract(a);  // Extrae el primer nodo de b
	add_first_stack(b, tmp);  // Lo agrega al inicio de a
}
