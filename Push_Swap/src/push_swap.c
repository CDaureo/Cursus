/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:37:45 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/19 11:37:45 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/stack_utils.h"


// Función para cargar los valores en la pila desde los argumentos
c_stack *load_stack(int argc, char **argv)
{
    c_stack *stack = NULL;
    int i;
	int val;
    i = argc - 1;
    while (i > 0)
	{
		val = atoi(argv[i]);
		push(&stack, val);
		i--;
	}
	
    return stack;
}
void free_stack(c_stack *stack)
{   
    c_stack *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    
}

int main(int argc, char **argv)
{
    c_stack *a = NULL;
    c_stack *b = NULL;

    if (argc < 2)
        return 0;  // No hay nada que hacer si no hay argumentos

    // Validación de los argumentos
    if (validate_args(argc, argv) == -1)
    {
        write(2, "Error\n", 6);
        return 1;
    }

    // Cargar los números en la pila 'a'
    a = load_stack(argc, argv);

    // Si ya está ordenado, no hacer nada
    if (is_sorted(a))
        return (free_stack(a), 0);
    // Llamar a la función de ordenación (como radix_sort o quick_sort)
    quick_sort(&a, &b);
    free_stack(a);
    free_stack(b);

    return 0;
}
