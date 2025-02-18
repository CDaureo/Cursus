
#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stdlib.h> // Para malloc y free
# include "push_swap.h"

// Funciones para manipulación del stack
c_stack	*new_stack(int c); // Crea un nuevo nodo del stack
void	add_last_stack(c_stack **stack, c_stack *new_stack); // Agrega un nodo al final del stack
void	add_first_stack(c_stack **stack, c_stack *new_stack); // Agrega un nodo al inicio del stack
c_stack	*extract(c_stack **stack); // Extrae el primer nodo del stack y lo devuelve
int		stack_size(c_stack *stack); // Retorna el número de elementos en el stack

#endif
