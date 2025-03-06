/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_post.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:18:00 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 16:27:55 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	position(c_stack *head, int p)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index == p)
			return (i);
		head = head->next;
		i++;
	}
	return (i);
}