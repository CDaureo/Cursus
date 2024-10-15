/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:12:54 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/15 12:40:37 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
void	ft_putchar(char c);
int	ft_put_string(char *s);
int	ft_put_in_pointer(void *p);
int	print_number(int num);
int	ft_putnbr_unsigned_recursive(unsigned int n);
int	ft_putnbr_hex(unsigned long num);
int	ft_putnbr_hex_uc(unsigned long num);
int	print_character(va_list args);
int	print_string(va_list args);
int	print_pointer(va_list args);
int	print_integer(va_list args);
int	print_unsigned(va_list args);
int	print_hex_lower(va_list args);
int	print_hex_upper(va_list args);
int	ft_strlen(const char *str);

#endif