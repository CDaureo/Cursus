/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:26:59 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new(void *cont)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->numbers = cont;
	node->next = NULL;
	return (node);
}
