/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:12:54 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/17 17:01:15 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *c, ...);
int	ft_putchar(char c);
int	ft_put_string(char *s);
int	ft_put_in_pointer(void *p);
int	print_number(int num);
int	ft_putnbr_unsigned_recursive(unsigned int n);
int	ft_putnbr_hex(unsigned long num);
int	ft_putnbr_hex_uc(unsigned long num);

#endif