/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 16:55:08 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


c_stack	*new(void *cont)
{
	c_stack	*node;

	node = (c_stack *)malloc(sizeof(c_stack));
	if (!node)
		return (NULL);
	node->numbers = cont;
	node->next = NULL;
	return (node);
}