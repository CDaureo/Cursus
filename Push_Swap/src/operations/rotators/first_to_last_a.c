/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_to_last_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:51:45 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(c_stack **a)
{
	c_stack	*tmp;

	if (*a && (*a) -> next)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp -> next;
		tmp->next = *a;
		*a = (*a) -> next;
		tmp ->next ->next =NULL;
		write (1, "ra\n", 3);
	}
	
}