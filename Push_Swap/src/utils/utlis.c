/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:41 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:34:04 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

//Crear un nuevo nodo del stack
c_stack	*new_stack(int c)
{
	c_stack *new;

	new = (c_stack *)malloc(sizeof(c_stack));
	if (!new)
		return (NULL);
	new->value = c;
	new->next = NULL;
	return(new);
}

int is_sorted(c_stack *stack)
{
    if (!stack || !stack->next)
        return 1;  // Si la pila tiene 0 o 1 elemento, ya está ordenada

    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;  // Si encontramos un valor mayor que el siguiente, no está ordenada
        stack = stack->next;
    }
    return 1;  // Si no encontramos desorden, la pila está ordenada
}
// Función para añadir un nuevo elemento a la pila
void push(c_stack **stack, int value)
{
    c_stack *new_node = new_stack(value);
    if (!new_node)
        exit(1);  // Manejar error en caso de no poder asignar memoria
    new_node->next = *stack;
    *stack = new_node;
}

// Devuelve el tamaño del stack
int	stack_size(c_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;  
	}
	return (i);
}