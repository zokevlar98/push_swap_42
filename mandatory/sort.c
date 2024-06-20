/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:12 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/20 18:51:38 by zqouri           ###   ########.fr       */
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
	else if (first < second && second > third && third  < first)
		reverse_rotate(&a, 'a');
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
	// printf("+++++++++++++\n");
	// ft_dis_link(a);
	// printf("==============\n");
	// ft_dis_link(b);
}

void	main_sort(t_stack *a, t_stack *b)
{
	int	len;

	// (void)b;
	len = ft_lstsize(a);
	if (len == 2)
		swap(&a, 'a');
	else if (len <= 3)
		sort_three(a);
	else if (len > 3 && len <= 5)
		sort_five(a, b);
	// else if (len > 5 && len <= 100)
	// 	sort_hundred(a, b);
	// 	else
	// 	sort_five_hundred(a, b);
}
