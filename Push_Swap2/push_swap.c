/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:56:37 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:23:18 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Convierte los argumentos en un arreglo de enteros y los valida.
 * @param argv El arreglo de argumentos.
 * @param argc El número de argumentos.
 * @param c Puntero al contador de números.
 * @param a Puntero a la pila donde se almacenarán los números.
 * @return Un arreglo de enteros o NULL si ocurre un error.
 */
static int	*int_to_array(const char *argv[], int argc, int *c,
		c_stack **a)
{
	int	i;
	int	*nums;

	i = 1;
	nums = init_nums(&c, a);
	if (!nums)
		return (NULL);
	while (i < argc)
	{
		if ((ft_strcmp((char *)argv[1], "") == 0) 
		|| parser(argv[i], nums, c, a) == -1)
			return (free(nums), NULL);
		i++;
	}
	return (nums);
}
/**
 * Crea un nuevo nodo para la pila y lo añade al final.
 * @param content Puntero al contenido que se almacenará en el nuevo nodo.
 * @param a Puntero a la pila donde se añadirá el nodo.
 * @return 0 en caso de éxito, 1 en caso de fallo.
 */
static int	new_node(int *contnent, c_stack **a)
{
	c_stack	*new_node;
	int		*cpy;

	cpy = malloc(sizeof(int));
	if (!cpy)
		return (1);
	*cpy = *contnent;
	new_node = new(cpy);
	if (!new_node)
	{
		free(cpy);
		clear(a, free);
		return (1);
	}
	add_back(a, new_node);
	return (0);
}

/**
 * Procesa y valida los argumentos, convirtiéndolos en una pila.
 * @param argc El número de argumentos.
 * @param argv El arreglo de argumentos.
 * @param a Puntero a la pila donde se almacenarán los números.
 * @return 0 en caso de éxito, 1 en caso de fallo.
 */
static int	arguments(int argc, char const *argv[], c_stack **a)
{
	int	i;
	int	*nums;
	int	c;

	i = 0;
	nums = int_to_array(argv, argc, &c, a);
	if (nums == NULL)
		return (1);
	while (i < c)
	{
		if (new_node(&nums[i], a) == 1)
			return (1);
		i++;
	}
	free(nums);
	set_index(a);
	return (0);
}

/**
 * Punto de entrada del programa push_swap.
 * @param argc El número de argumentos.
 * @param argv El arreglo de argumentos.
 * @return 0 en caso de éxito, 1 en caso de fallo.
 */
int	main(int argc, char const *argv[])
{
	c_stack	*a;
	c_stack	*aux;

	a = NULL;
	aux = NULL;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		if (arguments(argc, argv, &a) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	if (duplicates(a) == 1)
		return (ft_putstr_fd("Error\n", 2), clear(&a, free), 1);
	if (is_sorted(&a) == 1)
		return (clear(&a, free), 0);
	ksort(&a, &aux);
	return (clear(&a, free), clear(&aux, free), 0);
}
