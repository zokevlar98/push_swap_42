/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:56 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/16 04:22:31 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, char c)
{
	t_stack	*first;
	t_stack	*second;

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

void	reverse_rotate(t_stack **a, char c)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last_var;

	first = (*a);
	last = ft_lstlast(*a);
	if (!last)
		return ;
	before_last_var = before_last(*a);
	if (!before_last_var)
		return ;
	if ((*a) && (*a)->next)
	{
		last->next = first;
		before_last_var->next = NULL;
		(*a) = last;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		else if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	if (c == 'a')
	{
		tmp = (*b);
		if (!tmp)
			return ;
		(*b) = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_front(a, tmp);
		ft_putstr_fd("pa\n", 1);
	}
	else if (c == 'b')
	{
		tmp = (*a);
		if (!tmp)
			return ;
		(*a) = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_front(b, tmp);
		ft_putstr_fd("pb\n", 1);
	}
}
