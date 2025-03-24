/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:12:34 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:32 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Calcula la raíz cuadrada entera más cercana de un número.
 * @param nbr El número del que se calculará la raíz cuadrada.
 * @return La parte entera de la raíz cuadrada de nbr.
 */
int	ft_sqrt(int nbr)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

/**
 * Empuja elementos del stack 'a' al stack 'b' usando 
 * un rango basado en la raíz cuadrada.
 * @param a Puntero al stack 'a'.
 * @param b Puntero al stack 'b'.
 * @param size_a Puntero al tamaño de 'a'.
 * @param size_b Puntero al tamaño de 'b'.
 */
static void	push_b(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	range;

	range = ft_sqrt(*size_a) * 133 / 100;
	while (*size_a > 0)
	{
		if ((*a)->index <= *size_b)
		{
			pb(a, b, 1);
			(*size_a)--;
			(*size_b)++;
		}
		else if ((*a)->index <= *size_b + range)
		{
			pb(a, b, 1);
			(*size_a)--;
			(*size_b)++;
			if (!((*a)->index <= *size_b + range))
				rr(a, b);
			else
				rb(b, 1);
		}
		else
			ra(a, 1);
	}
}

/**
 * Empuja elementos del stack 'b' de vuelta al stack 'a' 
 * en el orden correcto.
 * @param a Puntero al stack 'a'.
 * @param b Puntero al stack 'b'.
 * @param size_a Puntero al tamaño de 'a'.
 * @param size_b Puntero al tamaño de 'b'.
 */
static void	push_a(t_stack **a, t_stack **b, int *size_a,
		int *size_b)
{
	while (*size_b > 0)
	{
		while ((*b)->index != *size_b - 1)
		{
			if (position(*b, *size_b - 1) <= *size_b / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(a, b, 1);
		(*size_a)++;
		(*size_b)--;
	}
}

/**
 * Ordena el stack 'a' usando un stack auxiliar 'b' y el algoritmo ksort.
 * @param a Puntero al stack 'a'.
 * @param b Puntero al stack 'b'.
 */
void	ksort(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = list_size(*a);
	size_b = list_size(*b);
	push_b(a, b, &size_a, &size_b);
	push_a(a, b, &size_a, &size_b);
}
