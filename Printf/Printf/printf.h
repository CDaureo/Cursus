/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:12:54 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/14 17:52:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
void	ft_putchar(char c);
void	ft_put_string(char *s);
void	ft_put_in_pointer(void *p);
void	ft_putnbr_fd(int n, int fd);

#endif