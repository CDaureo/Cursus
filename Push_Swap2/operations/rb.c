/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:01 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack **a, int p)
{
	t_stack	*first;
	t_stack	*current;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	current = *a;
	*a = (*a)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	if (p == 1)
		ft_printf("rb\n");
}
