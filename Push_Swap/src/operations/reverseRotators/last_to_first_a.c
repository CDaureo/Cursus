/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_to_first_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:50:54 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rra(c_stack **a)
{
	c_stack	*prev;
	c_stack	*last;

	if (!a || !*a || !(*a)->next) // Si hay menos de 2 elementos, no hace nada
		return ;
	prev = NULL;
	last = *a;
	while (last->next)  // Recorremos hasta el último nodo
	{
		prev = last;  // Guardamos el penúltimo nodo
		last = last->next;
	}
	prev->next = NULL;  // El penúltimo nodo ahora es el último
	add_first_stack(a, last);  // Movemos el último nodo al frente
}