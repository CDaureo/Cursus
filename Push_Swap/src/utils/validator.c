/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:03:06 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 15:02:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

int	is_sorted(c_stack **stack)
{
	c_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (*(int *)(tmp->number) > *(int *)(tmp->next->number))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int is_valid_number(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int has_duplicates(c_stack *stack)
{
    c_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (*(int *)(tmp->number) == *(int *)(stack->number))
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

// Devuelve el tamaño del stack
int	stack_size(c_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;  
	}
	return (i);
}