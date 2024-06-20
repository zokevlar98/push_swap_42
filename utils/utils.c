/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:55:22 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/20 18:48:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*Before_last(t_stack *a)
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

int	ft_is_biggest_or_smallest(t_stack **a, int content)
{
	int	biggest;
	int	smallest;
	t_stack	*tmp;

	biggest = INT_MIN;
	smallest = INT_MAX;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->content > biggest)
			biggest = tmp->content;
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	if (content > biggest)
		return (1);
	if (content < smallest)
		return (-1);
	return (0);
}

int	ft_check_smoll(t_stack *a)
{
	int	index;
	int lower;
	int lower_index;

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
	int index;
	index = ft_check_smoll(*a);
	// printf("index = %d\n", index);
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
	int index;
	index = ft_check_smoll(*a);
	if (index == 1)
		swap(a, 'a');// swap work
	if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
	}
	if (index == 3)
		reverse_rotate(a, 'a');
	ft_push(a, b, 'b');
}
