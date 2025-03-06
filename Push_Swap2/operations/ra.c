/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:19 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:05:09 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	ra(c_stack **a, int p)
{
	c_stack	*first;
	c_stack	*current;

	first = *a;
	current = *a;
	*a = (*a)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	if (p == 1)
		ft_printf("ra\n");
}
