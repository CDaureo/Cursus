/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:10:44 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 17:31:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sa(c_stack **a)
{
	c_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next; //Guarda el valor del primer nodo en una variable temporal
	(*a)->next = tmp->next;
	tmp ->next = *a;
	*a = tmp;
}