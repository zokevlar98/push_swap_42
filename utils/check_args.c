/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:28:01 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/15 16:47:26 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char *argv[])
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		if (ft_check_empty(argv[1]) || ft_isdigit(argv[1]) || check_int(argv[1]))
		{
			ft_exit("Error\n");
		}
		exit(EXIT_SUCCESS);
	}
}
