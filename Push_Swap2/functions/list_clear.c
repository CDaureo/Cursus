/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:22:20 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:26:57 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete(t_stack *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->numbers);
	free (lst);
}

void	clear(t_stack **lst, void (*del)(void *))
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		delete(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
