/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:12 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/25 02:02:46 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->content;
	second = a->next->content;
	third = a->next->next->content;
	if (first > second && second < third && third > first)
		swap(&a, 'a');
	else if (first > second && second > third && third < first)
	{
		swap(&a, 'a');
		reverse_rotate(&a, 'a');
	}
	else if (first > second && second < third && third < first)
		rotate(&a, 'a');
	else if (first < second && second > third && third > first)
	{
		swap(&a, 'a');
		rotate(&a, 'a');
	}
	else if (first < second && second > third && third < first)
		reverse_rotate(&a, 'a');
	ft_lstclear(&a);
	exit(EXIT_SUCCESS);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (ft_lstsize(a) == 5)
	{
		help_sort_five(&a, &b);
		help_sort_four(&a, &b);
		sort_three(a);
		ft_push(&a, &b, 'a');
		ft_push(&a, &b, 'a');
	}
	else if (ft_lstsize(a) == 4)
	{
		help_sort_four(&a, &b);
		sort_three(a);
		ft_push(&a, &b, 'a');
	}
	ft_lstclear(&a);
	exit(EXIT_SUCCESS);
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
		sort_three(*a);
	else if (len > 3 && len <= 5)
		sort_five(*a, *b);
	else if (len > 5 && len <= 100)
		sort_hundred(a, b, 5);
	else if (len > 100 && len <= 500)
		sort_hundred(a, b, 11);
}
