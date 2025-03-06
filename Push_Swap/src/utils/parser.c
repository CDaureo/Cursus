/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:15 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 15:46:43 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_utils.h"

static void	free_split(char ***c)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = *c;
	while (tmp[j] != NULL)
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

int	*loader(int **c, c_stack **a)
{
	int	*nums;

	nums = malloc(2147483646 * sizeof(int));
	if (!nums)
	{
		clear(a, free);
		return (NULL);
	}
	**c = 0;
	return (nums);
}

int	parse_tmps(char **tmps, int *nums, int *c, c_stack **a)
{
	int	j;

	j = 0;
	while (tmps[j] != NULL)
	{
		if (validator(tmps[j], nums, c, a) == -1)
		{
			free_split(&tmps);
			return (-1);
		}
		j++;
	}
	free_split(&tmps);
	return (0);
}

int	parser(const char *arg, int *nums, int *c, c_stack **a)
{
	char	**tmps;

	if (ft_strchr(arg, ' ') != NULL)
	{
		tmps = ft_split(arg, ' ');
		if (!tmps)
		{
			clear(a, free);
			return (-1);
		}
		if (parse_tmps(tmps, nums, c, a) == -1)
			return (-1);
	}
	else if (arg[0] != '\0')
	{
		if (validator(arg, nums, c, a) == -1)
			return (-1);
	}
	return (0);
}


int	validator(const char *tmp, int *nums, int *c, c_stack **a)
{
	int	comparer;

	comparer = 0;
	nums[*c] = ft_atoi(tmp, &comparer);
	if (comparer || (nums[*c] == 0 && is_valid_number(tmp) == 1))
	{
		clear(a, free);
		return (-1);
	}
	(*c)++;
	return (0);
}

