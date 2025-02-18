/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:00:12 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/02/11 18:11:12 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct p_stack
{
	int 		value;
	struct p_stack *next;
}	c_stack;

#include "stack_utils.h"

void	sa(c_stack **a);
void	sb(c_stack **b);
void	ss(c_stack **a, c_stack **b);
void	pa(c_stack **a, c_stack **b);
void	pb(c_stack **a, c_stack **b);
void	ra(c_stack **a);
void	rb(c_stack **b);
void	rr(c_stack **a, c_stack **b);
void	rra(c_stack **a);
void	rrb(c_stack **b);
void	rrr(c_stack **a, c_stack **b);


#endif