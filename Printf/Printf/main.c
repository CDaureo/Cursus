/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:16:34 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 12:52:47 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

int main(void)
{
	ft_printf("Prueba de caracteres: %c\n",'a');
	ft_printf("===============================================\n");
	ft_printf("Prueba de string: %s\n", "Hola mundo");
	ft_printf("===============================================\n");
	ft_printf("Prueba de hexadecimal con puntero: %p\n", 123);			
	ft_printf("===============================================\n");
	ft_printf("Prueba de numero decimal: %d\n", 444431231231);	
	ft_printf("===============================================\n");
	ft_printf("Prueba de numero entero: %i\n ", 1234235);		
	ft_printf("===============================================\n");
	ft_printf("Prueba de numero entero (sin signo): %u\n ", 1234235);
	ft_printf("===============================================\n");
	ft_printf("Prueba de numero hexadecimal con minusculas: %x\n ", 123);		
	ft_printf("===============================================\n");
	ft_printf("Prueba de hexadecimal con mayusculas: %X\n ", 123);		
	ft_printf("===============================================\n");
	ft_printf("Prueba de imprimir porcentaje %%\n");		
	ft_printf("===============================================\n");
	return 0;
}
