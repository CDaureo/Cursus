/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:30:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/22 14:30:49 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

// Función auxiliar para mover elementos menores que el pivote al stack b
static void partition(c_stack **a, c_stack **b, int pivot)
{
    int stack_size_a = stack_size(*a);
    int rotations = 0;

    while (stack_size_a--)
    {
        if ((*a)->value <= pivot)
            pb(a, b); // Mueve el elemento al stack b
        else
        {
            ra(a); // Rota el stack a
            rotations++;
        }
    }

    // Devuelve los elementos rotados al final del stack a
    while (rotations--)
        rra(a);
}

static int find_pivot(c_stack *stack)
{
    int size = stack_size(stack);
    int sum = 0;

    while (stack)
    {
        sum += stack->value;
        stack = stack->next;
    }
    return (sum / size); // Valor medio como pivote
}

// Función principal de Quick Sort
void quick_sort(c_stack **a, c_stack **b)
{
    if (is_sorted(*a)) // Si el stack ya está ordenado, termina
        return;

    int pivot = find_pivot(*a); // Encuentra un pivote (por ejemplo, el valor medio)
    partition(a, b, pivot);     // Particiona el stack a usando el pivote

    quick_sort(a, b); // Ordena el stack a
    quick_sort(b, a); // Ordena el stack b

    // Mueve todos los elementos de b de vuelta a a
    while (*b)
        pa(a, b);
}