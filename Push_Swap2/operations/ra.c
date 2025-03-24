/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:19 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:00 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int p)
{
	t_stack	*first;
	t_stack	*current;

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
