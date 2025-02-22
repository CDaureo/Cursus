/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_to_last_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:51:41 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:56 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rb(c_stack **b)
{
	c_stack	*tmp;

	if (*b && (*b) -> next)
	{
		tmp = *b;
		while (tmp->next)
			tmp = tmp -> next;
		tmp->next = *b;
		*b = (*b) -> next;
		tmp ->next ->next =NULL;
		write (1, "rb\n", 3);
	}
	
}