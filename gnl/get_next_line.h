/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:55:02 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/21 15:46:14 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

static char	*new_line(char *str_storage);
static char	*cleaner(char *str_storage);
static char	*read_buffer(int fd, char *str_storage);
char	*get_next_line(int fd);
size_t ft_strlen(const char *);
static char *ft_strchr(char *s, int c);
char *ft_strjoin(char *str_storage, char *buff);
void	*ft_memcpy(void *dest, const void *src, size_t n);



# endif