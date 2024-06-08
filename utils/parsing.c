/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:29:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/08 19:32:18 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void before_exit(void)
{
	system("leaks push_swap");
	printf("before exit\n");
}


void	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		ft_exit("Error\n");
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		ft_exit("Error\n");
}

void	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit("Error\n");
		i++;
	}
}
void	check_int(char *str)
{
	int	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		ft_exit("ERROR");
}



// argv[i] -> split ==== char **p  p[j] -> push


// ./push_swap 12 "34 56" 78 90 7 "54 36" 78 "241 54" 587

// argv[i] = 12        =====>     split   ====> [12]
// argv[i] = "34 56"        =====>     split   ====>  [34] [56]
// argv[i] = 78        =====>     split   ====> [78]
// argv[i] = 90        =====>     split   ====> [90]
// argv[i] = 7        =====>     split   ====> [7]
// argv[i] = "54 36"        =====>     split   ====> [54] [36]
// argv[i] = 78        =====>     split   ====> [78]
// argv[i] = "241 54"        =====>     split   ====> [241] [54]
// argv[i] = 587        =====>     split   ====> [587]

// ./push_swap 5 6 9 8 2 3 "06 13 15 89 65"


// stack_a;
// char **p;
// while(argv[i++])
// {
// 	char  **tmp = split(argv[i]);
// 	while(tmp[j++])
// 	{
// 		push(stack_a, create_node(ft_atoi(tmp[j])));
// 	}
// }


// tmp[0] = {"12"}
// tmp[1] = {"12", "56"}
// tmp[2] = {"78"}
// tmp[3] = {"90"}
// tmp[4] = {"7"}
// tmp[5] = {"54", "36"}
// tmp[6] = {"78"}
// tmp[7] = {"241", "54"}
// tmp[8] = {"587"}