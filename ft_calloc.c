/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:56:45 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/26 14:01:40 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include  "ft_memset.c"

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t t_size;
	void *ptr;
	
	t_size = nmemb * size;
	//Asigno la cantidad de memoria con malloc en el puntero ptr.
	ptr = malloc(t_size);
	if (ptr == 	NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, t_size);
	return (ptr);
}

/*
int main(void) {
    size_t nmemb = 5;
    size_t size = sizeof(int);

    // Uso de ft_calloc para reservar memoria para 5 enteros
    int *arr = (int *)ft_calloc(nmemb, size);

    if (arr == NULL) {
        printf("Error al asignar memoria con ft_calloc\n");
        return 1;  // Salir del programa si hay un error
    }

    // Imprimir los valores inicializados (deben ser todos ceros)
    printf("Valores iniciales:\n");
    for (size_t i = 0; i < nmemb; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Asignar nuevos valores
    for (size_t i = 0; i < nmemb; i++) {
        arr[i] = (int)(i * 10);
    }

    // Imprimir los valores asignados
    printf("Valores asignados:\n");
    for (size_t i = 0; i < nmemb; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Liberar la memoria asignada
    free(arr);

    return 0;
}
*/