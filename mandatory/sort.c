/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:12 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/16 22:57:04 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a)
		return ;
	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && third > first)
		swap(a, 'a');
	else if (first > second && second > third && third < first)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (first > second && second < third && third < first)
		rotate(a, 'a');
	else if (first < second && second > third && third > first)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (first < second && second > third && third < first)
		reverse_rotate(a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 4)
	{
		help_sort_four(a);
		ft_push(a, b, 'b');
		sort_three(a);
		ft_push(a, b, 'a');
	}
	else if (ft_lstsize(*a) == 5)
	{
		help_sort_five(a);
		ft_push(a, b, 'b');
		help_sort_four(a);
		ft_push(a, b, 'b');
		sort_three(a);
		ft_push(a, b, 'a');
		ft_push(a, b, 'a');
	}
}

void	sort_hundred(t_stack **a, t_stack **b, int nbr_chunk)
{
	int	current_chunk;
	int	nbr_last_element;

	current_chunk = ft_lstsize(*a) / nbr_chunk;
	nbr_last_element = current_chunk;
	while (ft_lstsize(*a) != 0)
	{
		push_it(a, b, current_chunk, nbr_last_element);
		nbr_last_element += current_chunk;
	}
	push_it_back(a, b);
}

void	main_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 1)
		return ;
	else if (len == 2)
		swap(a, 'a');
	else if (len <= 3)
		sort_three(a);
	else if (len > 3 && len <= 5)
		sort_five(a, b);
	else if (len > 5 && len <= 100)
		sort_hundred(a, b, 5);
	else
		sort_hundred(a, b, 11);
	ft_lstclear(a);
	exit(EXIT_SUCCESS);
}
