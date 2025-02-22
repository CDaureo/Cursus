/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_to_first_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:51:14 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:25 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rrb(c_stack **b)
{
	c_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next->next)
			tmp = tmp -> next;
		tmp ->next->next = *b;
		*b = tmp -> next;
		tmp->next = NULL;
		write (1, "rrb\n", 4);
	}
}
/*
* Función optimizada para hacer reverse rotation (rra)
*void reverse_rotate(c_stack **stack)
*{
*    c_stack *temp;
*    c_stack *last;
*    c_stack *penultimate;
*
*    if (!*stack || !(*stack)->next) // Si la pila está vacía o tiene un solo nodo, no realizamos rotación
*        return;
*
*    // Inicializamos los punteros
*    temp = *stack;
*    penultimate = NULL;
*    
*    // Recorremos hasta el último nodo para encontrar el penúltimo
*    while (temp->next)
*    {
*        penultimate = temp; // El penúltimo nodo será el que está justo antes del último
*        temp = temp->next; // Mueve al siguiente nodo
*    }
*
*    last = temp; // El último nodo
*
*    // El penúltimo nodo ahora tiene que apuntar a NULL
*    penultimate->next = NULL;
*
*    // El último nodo debe apuntar al principio de la pila
*    last->next = *stack;
*    *stack = last; // El último nodo se convierte en la nueva cabeza
*}*/