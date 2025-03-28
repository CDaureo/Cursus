#include "../includes/so_long.h"

int ft_strlen2(const char *s)
{
	int i;
	i = 0;
	
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int is_map_rectangular(char **map)
{
    int width;
    int y;

    // Verificar si el mapa está vacío
    if (!map || !map[0])
        return (0);

    // Obtenemos el ancho de la primera fila
    width = ft_strlen2(map[0]);

    y = 0;
    while (map[y])  // Iteramos sobre todas las filas
    {
        // Asegurarnos de que las filas tengan la misma longitud y no tengan saltos de línea inesperados
        if (ft_strlen2(map[y]) != width)
		{
			printf("cac");
			return (0);  // No es rectangular

		}

        // Verificamos que no haya saltos de línea adicionales al final de las filas
        if (map[y][ft_strlen(map[y]) - 1] == '\n')
        {
            // Eliminar el salto de línea al final de la fila si lo hay
            map[y][ft_strlen(map[y]) - 1] = '\0';
        }

        y++;
    }
    return (1);  // Es rectangular
}

int is_map_closed(char **map)
{
    int x;
    int y;
    int width;
    int height;

    height = 0;
    while (map[height])
        height++;  // Contamos el número de filas
    width = ft_strlen2(map[0]);  // Obtenemos el ancho de la primera fila

    // Comprobar las primeras y últimas filas
    x = 0;
    while (x < width)
    {
        if (map[0][x] != '1' || map[height - 1][x] != '1')
            return (0);
        x++;
    }

    // Comprobar las primeras y últimas columnas de cada fila
    y = 0;
    while (y < height)
    {
        if (map[y][0] != '1' || map[y][width - 1] != '1')
            return (0);
        y++;
    }

    return (1);  // El mapa está cerrado
}