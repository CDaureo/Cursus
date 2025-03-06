/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:30 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:05:24 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(c_stack **a, int p)
{
	c_stack	*current;
	c_stack	*last;
	c_stack	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	current = *a;
	while (current->next->next != NULL)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	if (p == 1)
		ft_printf("rrb\n");
}
