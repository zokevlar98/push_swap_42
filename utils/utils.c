/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:55:22 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/25 02:01:20 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*before_last(t_stack *a)
{
	while (a && a->next->next)
		a = a->next;
	return (a);
}

void	ft_dis_link(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
}

int	ft_check_small(t_stack *a)
{
	int	index;
	int	lower;
	int	lower_index;

	index = 0;
	lower_index = 0;
	lower = INT_MAX;
	while (a)
	{
		if (a->content < lower)
		{
			lower = a->content;
			lower_index = index;
		}
		a = a->next;
		index++;
	}
	return (lower_index);
}

void	help_sort_five(t_stack **a, t_stack **b)
{
	int	index;

	index = ft_check_small(*a);
	if (index == 1)
		rotate(a, 'a');
	if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
	}
	if (index == 3)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
	}
	if (index == 4)
		reverse_rotate(a, 'a');
	ft_push(a, b, 'b');
}

void	help_sort_four(t_stack **a, t_stack **b)
{
	int	index;

	index = ft_check_small(*a);
	if (index == 1)
		swap(a, 'a');
	if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
	}
	if (index == 3)
		reverse_rotate(a, 'a');
	ft_push(a, b, 'b');
}
