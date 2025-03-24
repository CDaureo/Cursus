/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:32:58 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:34 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Verifica si la pila 'a' está ordenada de forma ascendente.
 * @param a Puntero al stack 'a'.
 * @return 1 si la pila está ordenada, 0 si no lo está.
 */
int	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (1);
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (*(int *)(tmp->numbers) > *(int *)(tmp->next->numbers))
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/**
 * Verifica si existen números duplicados en la pila 'a'.
 * @param a Puntero a la pila 'a'.
 * @return 1 si hay duplicados, 0 si no los hay.
 */
int	duplicates(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (*(int *)(tmp->numbers) == *(int *)(a->numbers))
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

/**
 * Valida si una cadena de caracteres contiene solo dígitos.
 * @param str Cadena de caracteres a validar.
 * @return 0 si la cadena contiene solo dígitos, 1 si no.
 */
int	valid_number(const char *str)
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
