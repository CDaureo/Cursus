/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:40 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/06 17:19:51 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void			*numbers;
	struct s_list	*next;
	int				index;
}	c_stack;

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "printf/ft_printf.h"
/******************************************************************
*							OPERATORS							  *
*******************************************************************/
void	pa(c_stack **a, c_stack **b, int p);
void	pb(c_stack **b, c_stack **a, int p);
void	ra(c_stack **a, int p);
void	rb(c_stack **a, int p);
void	rr(c_stack **a, c_stack **b);
void	rra(c_stack **a, int p);
void	rrb(c_stack **a, int p);
void	rrr(c_stack **a, c_stack **b);
void	sa(c_stack **a, int p);
void	sb(c_stack **head_b, int p);
void	rra(c_stack **a, int p);
/******************************************************************
*							FUNCTIONS							  *
*******************************************************************/
int		list_size(c_stack *lst);
int		position(c_stack *a, int p);
void	clear(c_stack **lst, void (*del)(void *));
void	delete(c_stack *lst, void (*del)(void*));
c_stack	*new(void *cont);
void	add_back(c_stack **lst, c_stack *new);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, int *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
/******************************************************************
*							PARSER								  *
*******************************************************************/
int		*init_nums(int **c, c_stack **a);
int		parser(const char *arg, int *nums, int *c, c_stack **a);
int		parser_str(char **str, int *nums, int *c, c_stack **a);
int		validator(const char *str, int *nums, int *c, c_stack **a);
/******************************************************************
*							VALIDATOR							  *
*******************************************************************/
int	is_sorted(c_stack **a);
int	duplicates(c_stack *a);
int	valid_number(const char *str);
/******************************************************************
*								INDEX							  *
*******************************************************************/
void	bsort(int *arr, int n);
int	*list_to_array(c_stack *a, int size);
void	index_assign(c_stack *a, int *arr, int size);
c_stack	*set_index(c_stack **a);
/******************************************************************
*								SORTERS							  *
*******************************************************************/
void	ksort(c_stack **a, c_stack **b);
#endif