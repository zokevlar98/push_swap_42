/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/07 17:15:09 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	int x;
	
	atexit(before_exit);
	x = ft_atoi(argv[1]);
	printf("%d\n", x * 2);
	return (0);
}