/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:04:34 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/10 16:25:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str, t_stack **a)
{
	ft_putstr_fd(str, 2);
	if (ft_lstsize(*a) != 0)
		ft_lstclear(a);
	exit(EXIT_SUCCESS);
}
