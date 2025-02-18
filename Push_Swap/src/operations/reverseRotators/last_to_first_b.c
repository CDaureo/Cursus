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
	c_stack	*prev;
	c_stack	*last;

	if (!b || !*b || !(*b)->next) // Si hay menos de 2 elementos, no hace nada
		return ;
	prev = NULL;
	last = *b;
	while (last->next)  // Recorremos hasta el último nodo
	{
		prev = last;  // Guardamos el penúltimo nodo
		last = last->next;
	}
	prev->next = NULL;  // El penúltimo nodo ahora es el último
	add_first_stack(b, last);  // Movemos el último nodo al frente
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