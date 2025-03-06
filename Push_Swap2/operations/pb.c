/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:02 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:04:57 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	pb(c_stack **a, c_stack **b, int p)
{
	c_stack	*first_node;

	if (*a == NULL)
		return ;
	first_node = *a;
	*a = first_node->next;
	first_node->next = *b;
	*b = first_node;
	if (p == 1)
		ft_printf("pb\n");
}
