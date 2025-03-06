/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:08 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 16:09:30 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	pa(c_stack **a, c_stack **b, int p)
{
	c_stack	*first_node;

	if (*b == NULL)
		return ;
	first_node = *b;
	*b = first_node->next;
	first_node->next = *a;
	*a = first_node;
	if (p == 1)
		ft_printf("pa\n");
}
