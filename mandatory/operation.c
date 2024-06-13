/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:56 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/13 21:51:08 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, char c)
{
	t_stack *first;
	t_stack *second;

	first = *a;
	second = (*a)->next;
	if (first)
	{
		first->next = second->next;
		second->next = first;
		*a = second;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (c == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}
void	rotate(t_stack **a, char c)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	first = (*a);
	second = (*a)->next;
	last = ft_lstlast(*a);
	if (*a && (*a)->next)
	{
		last->next = first;
		first->next = NULL;
		*a = second;
		if (c == 'a')
			ft_putstr_fd("ra\n", 1);
		else if (c == 'b')
			ft_putstr_fd("rb\n", 1);
	}
}

void 	reverse_rotate(t_stack **a, char c)
{
	t_stack *first;
	t_stack	*last;
	t_stack	*before_last;

	first = (*a);
	last = ft_lstlast(*a);
	before_last = Before_last(*a);
	if ((*a) && (*a)->next)
	{
		last->next = first;
		before_last->next = NULL;
		(*a) = last;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		else if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack *first_a;
	t_stack *first_b;
	t_stack *second_a;
	t_stack *second_b;

	first_a = (*a);
	first_b = (*b);
	second_a = (*a)->next;
	second_b = (*b)->next;
	if (!(*b) || !(*a))
		return ;
	if (c == 'a')//push a "de stack b vers stack a"
	{
		first_b->next = first_a;
		(*a) = first_b;
		(*b) = second_b;
		ft_putstr_fd("pa\n", 1);
	}
	else if (c == 'b')//push b "de stack a vers stack b"
	{
		first_a->next = first_b;
		*b = first_a;
		*a = second_a;
		ft_putstr_fd("pb\n", 1);
	}
}
