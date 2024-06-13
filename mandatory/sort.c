/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:12 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/13 20:56:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_three(t_stack *a)
// {
	
// }

void	main_sort(t_stack *a, t_stack *b)
{
	int	len;

	len = ft_lstsize(a);
	if (len == 2)
		;//swap a
	else if (len <= 3)
		sort_three(a);
	else if (len > 3 && len <= 5)
		sort_five(a, b);
	else if (len > 5 && len <= 100)
		sort_hundred(a, b);
		else
		sort_five_hundred(a, b);
}
