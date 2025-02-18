/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:28:50 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 18:13:12 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


c_stack *new_node(int value)
{
    c_stack *node = malloc(sizeof(c_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void print_stack(c_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int	main()
{
 // Crear una pila con al menos dos nodos
 c_stack *a = new_node(10);
 a->next = new_node(20);
 a->next->next = new_node(30);
 c_stack *b = new_node(99);
 b->next = new_node(55);


 printf("Antes (STACK A): ");
 print_stack(a);
 printf("Antes (STACK B): ");
 print_stack(b);
 
 ss(&a, &b);
 
 printf("Despues (STACK A): ");
 print_stack(a);
 printf("Despues (STACK B): ");
 print_stack(b);

}