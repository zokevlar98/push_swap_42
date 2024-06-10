/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:29:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/10 16:27:36 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	before_exit(void)
{
	system("leaks push_swap");
	printf("before exit\n");
}

int	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_int(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = ft_atoi(str);
	while (str[i] == 48)
		i++;
	if (num > INT_MAX || num < INT_MIN || ft_strlen(str + i) > 11)
		return (1);
	return (0);
}

int	ft_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_size(str) == 0)
		ft_exit("Error\n");
	while (i < ft_size(str) - 1)
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
