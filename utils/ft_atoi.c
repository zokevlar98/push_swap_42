/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:37:37 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/16 04:26:47 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long long	resu;

	i = 0;
	signe = 1;
	resu = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resu = 10 * resu + str[i] - '0';
		if ((resu > INT_MAX && signe == 1)
			|| ((resu * -1) < INT_MIN && signe == -1))
			return (resu * signe);
		i++;
	}
	return (resu * signe);
}
