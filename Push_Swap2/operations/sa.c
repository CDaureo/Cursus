/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:34 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a, int p)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (p == 1)
		ft_printf("sa\n");
}
