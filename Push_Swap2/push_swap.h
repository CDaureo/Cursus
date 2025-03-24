/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:40 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:24:00 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "printf/ft_printf.h"

typedef struct t_list
{
	void			*numbers;
	struct t_list	*next;
	int				index;
}	t_stack;

/******************************************************************
*							OPERATORS							  *
*******************************************************************/
void	pa(t_stack **a, t_stack **b, int p);
void	pb(t_stack **b, t_stack **a, int p);
void	ra(t_stack **a, int p);
void	rb(t_stack **a, int p);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int p);
void	rrb(t_stack **a, int p);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a, int p);
void	sb(t_stack **head_b, int p);
void	rra(t_stack **a, int p);
/******************************************************************
*							FUNCTIONS							  *
*******************************************************************/
int		list_size(t_stack *lst);
int		position(t_stack *a, int p);
void	clear(t_stack **lst, void (*del)(void *));
void	delete(t_stack *lst, void (*del)(void*));
t_stack	*new(void *cont);
void	add_back(t_stack **lst, t_stack *new);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, int *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
/******************************************************************
*							PARSER								  *
*******************************************************************/
int		*init_nums(int **c, t_stack **a);
int		parser(const char *arg, int *nums, int *c, t_stack **a);
int		parser_str(char **str, int *nums, int *c, t_stack **a);
int		validator(const char *str, int *nums, int *c, t_stack **a);
/******************************************************************
*							VALIDATOR							  *
*******************************************************************/
int		is_sorted(t_stack **a);
int		duplicates(t_stack *a);
int		valid_number(const char *str);
/******************************************************************
*								INDEX							  *
*******************************************************************/
void	bsort(int *arr, int n);
int		*list_to_array(t_stack *a, int size);
void	index_assign(t_stack *a, int *arr, int size);
t_stack	*set_index(t_stack **a);
/******************************************************************
*								SORTERS							  *
*******************************************************************/
void	ksort(t_stack **a, t_stack **b);
#endif