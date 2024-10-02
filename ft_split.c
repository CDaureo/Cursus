/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/27 15:58:38 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/09/27 15:58:38 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
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
static char	*ft_strndup(const char *s, size_t n)
{
	char	*new_str;
	size_t	i;

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
static void	ft_free_split(char **split, int words)
{
	if (words == 0)
	{
		free(split);
		return ;
	}
	free(split[words - 1]);
	ft_free_split(split, words - 1);
}

int	ft_fill_result(char **result, const char *s, char c, int words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = ft_strndup(s + start, end - start);
		if (!result[i])
		{
			ft_free_split(result, i);
			return (0);
		}
		i++;
		start = end;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!s || !result)
		return (NULL);
	if (!ft_fill_result(result, s, c, words))
		return (NULL);
	result[words] = (NULL);
	return (result);
}
