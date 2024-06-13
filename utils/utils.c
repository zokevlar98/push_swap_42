/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:55:22 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/13 21:10:46 by zqouri           ###   ########.fr       */
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
