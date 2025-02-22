/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_to_first_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:50:54 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rra(c_stack **a)
{
	c_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp -> next;
		tmp ->next->next = *a;
		*a = tmp -> next;
		tmp->next = NULL;
		write (1, "rra\n", 4);
	}

}