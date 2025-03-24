/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:27 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:28:04 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a, int p)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	current = *a;
	last = NULL;
	second_last = NULL;
	while (current->next->next != NULL)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	if (p == 1)
		ft_printf("rra\n");
}
