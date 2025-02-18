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

#include "../../includes/stack_utils.h"

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
//Agrega un nodo al final del stack
void	add_last_stack(c_stack **stack, c_stack *new_stack)
{
	c_stack *tmp;
	if (!stack || !new_stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else 
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_stack;
	}
}

//Agrega un nodo al inicio del stack

void	add_first_stack(c_stack **stack, c_stack *new_stack)
{
	if (!stack || !new_stack)
		return ;
	new_stack->next = *stack;
	*stack = new_stack;
}
//Extrae el primer nodo del stack y lo devuelve
c_stack *extract (c_stack **stack)
{
	c_stack *first;
	if (!stack || !(*stack))
		return (NULL);
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	return (first);
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