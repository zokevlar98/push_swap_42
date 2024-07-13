/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:42:33 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/25 02:11:58 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **a)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	tmp_1 = (*a);
	while (tmp_1)
	{
		tmp_1->position = 0;
		tmp_2 = (*a);
		while (tmp_2)
		{
			if (tmp_1->content > tmp_2->content)
				tmp_1->position++;
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
}

int	get_index(t_stack **a, int position)
{
	t_stack	*tmp;
	int		index;

	tmp = (*a);
	index = 0;
	while (tmp)
	{
		if (tmp->position == position)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_it(t_stack **a, t_stack **b, int c_chunk, int last_e)
{
	int	middle;

	middle = c_chunk / 2;
	while ((*a) && c_chunk > 0)
	{
		if ((*a)->position <= last_e)
		{
			if ((*a)->position >= last_e - middle)
			{
				ft_push(a, b, 'b');
				rotate(b, 'b');
			}
			else
				ft_push(a, b, 'b');
			c_chunk--;
		}
		else
			rotate(a, 'a');
	}
}

void	push_it_back(t_stack **a, t_stack **b)
{
	int		index;

	while (ft_lstsize(*b) > 0)
	{
		index = get_index(b, (ft_lstsize(*b) - 1));
		if (index == -1)
			ft_exit("Error\n", a);
		else if (index == 0)
			ft_push(a, b, 'a');
		else if (index <= (ft_lstsize(*b) / 2))
			rotate(b, 'b');
		else if (index > (ft_lstsize(*b) / 2))
			reverse_rotate(b, 'b');
	}
}
