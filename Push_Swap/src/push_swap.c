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



c_stack *new_node(int value)
{
	c_stack *node = malloc(sizeof(c_stack));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return node;
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
    c_stack *new_node = malloc(sizeof(c_stack));
    if (!new_node)
        exit(1);  // Manejar error en caso de no poder asignar memoria
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Función para cargar los valores en la pila desde los argumentos
c_stack *load_stack(int argc, char **argv)
{
    c_stack *stack = NULL;
    int i;

    for (i = argc - 1; i > 0; i--)  // Empezamos desde el último argumento
    {
        int value = atoi(argv[i]);  // Convertir el argumento a un entero
        push(&stack, value);
    }
    return stack;
}
// Function to print the stack (for debugging purposes)
void	print_stack(c_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
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
        return 0;
    print_stack(a);
    // Llamar a la función de ordenación (como radix_sort o quick_sort)
    radix_sort(&a, &b);
    print_stack(a);
    return 0;
}