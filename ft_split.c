/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:58:38 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/27 15:58:38 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Contador de palabras
static int ft_count_words(char const *s, char c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
        {
            in_word = 0;
        }
        s++;
    }
    return (count);
}

// Función auxiliar para copiar una subcadena
static char *ft_strndup(const char *s, size_t n)
{
    char *new_str;
    size_t i;

    new_str = (char *)malloc(sizeof(char) * (n + 1));
    if (!new_str)
        return (NULL);

    i = 0;
    while (i < n)
    {
        new_str[i] = s[i];
        i++;
    }
    new_str[n] = '\0';

    return (new_str);
}

// Función para liberar el array en caso de error
static void ft_free_split(char **split, int words)
{
    if (words == 0)
    {
        free(split); // Libera el array de punteros una vez terminada la recursión
        return;
    }
    free(split[words - 1]); // Libera la última subcadena
    ft_free_split(split, words - 1); // Llama recursivamente para liberar el resto
}

// Función principal
char **ft_split(char const *s, char c)
{
	char **result;
	int words;	
	int i;
	int start;
	int end;
	i = 0;
	start = 0;
	end = 0;

	if (!s)
	    return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
	    return (NULL);	
	while (i < words)
	{
	    // Encontramos el inicio de la subcadena
	    while (s[start] && s[start] == c)
	        start++;
	    end = start;
	    // Encontramos el final de la subcadena 
	    while (s[end] && s[end] != c)
	        end++;
	    // Copiamos la subcadena
	    result[i] = ft_strndup(s + start, end - start);
	    if (!result[i])
	    {
	        ft_free_split(result, i);
	        return (NULL);
	    }
	    i++;
	    start = end;
	}
    result[i] = NULL; // Terminamos el array con un puntero NULL
    return result;
}

/*int main(void)
{
    char **result;
    char *str = "Hola,,esto,,es,una,prueba,,de,split,";
    char delimiter = ',';
    int i = 0;

    // Llamamos a ft_split para dividir la cadena
    result = ft_split(str, delimiter);

    // Verificamos si se pudo reservar memoria
    if (!result)
    {
        printf("Error en la asignación de memoria\n");
        return (1);
    }

    // Imprimimos las subcadenas resultantes
    printf("Cadena original: '%s'\n", str);
    printf("Subcadenas separadas por '%c':\n", delimiter);
    while (result[i] != NULL)
    {
        printf("Subcadena %d: '%s'\n", i + 1, result[i]);
        i++;
    }

    // Liberamos la memoria asignada para el array de subcadenas
    i = 0;
    while (result[i])
    {
        free(result[i]); // Liberamos cada subcadena
        i++;
    }
    free(result); // Finalmente liberamos el array de punteros

    return (0);
}*/
