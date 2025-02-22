
#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stdlib.h> // Para malloc y free
# include "push_swap.h"

// Funciones para manipulación del stack
c_stack	*new_stack(int c); // Crea un nuevo nodo del stack
int		stack_size(c_stack *stack); // Retorna el número de elementos en el stack
int is_sorted(c_stack *stack);
void push(c_stack **stack, int value);
c_stack *load_stack(int argc, char **argv);
int get_max_bits(c_stack *stack);
void	radix_sort(c_stack **a, c_stack **b);
int validate_args(int argc, char **argv);
void	quick_sort(c_stack **a, c_stack**b);
void    partition(c_stack **a, c_stack **b, int pivot);
char	*ft_itoa(int n);

#endif
