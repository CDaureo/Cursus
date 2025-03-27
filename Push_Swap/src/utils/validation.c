/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:15 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/27 15:55:09 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>  // Para definir el rango de enteros

// Función para verificar si un número es un valor válido
int is_valid_number(const char *str)
{
    long long num;
    char *endptr;

    // Verifica que la cadena no sea vacía y que el valor esté dentro del rango de enteros
    num = strtol(str, &endptr, 10);  // Convertir la cadena a un número

    if (*endptr != '\0')  // Si no se convierte toda la cadena a número, es inválido
        return 0;

    if (num < INT_MIN || num > INT_MAX)  // Verificar si está dentro del rango de enteros
        return 0;

    return 1;
}

// Función para verificar si hay duplicados
int has_duplicates(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)  // Recorremos los argumentos
    {
        for (int j = i + 1; j < argc; j++)  // Comparamos cada argumento con los demás
        {
            if (strcmp(argv[i], argv[j]) == 0)  // Si son iguales, es un duplicado
                return 1;
        }
    }
    return 0;
}

// Función para validar los argumentos
int validate_args(int argc, char **argv)
{
    if (argc < 2)
        return -1;  // Si no hay suficientes argumentos, es un error

    // Verificar cada argumento para asegurarse de que son números válidos
    for (int i = 1; i < argc; i++)
    {
        if (!is_valid_number(argv[i]))  // Si el número no es válido
            return (write(2, "Error", 6), -1);
    }

    // Verificar si hay duplicados
    if (has_duplicates(argc, argv))
		return (write(2,"dupe", 4), -1);


    return 0;  // Todo es válido
}
