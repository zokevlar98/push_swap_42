/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/16 04:07:25 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**put_tab_parse(char *argv[])
{
	int		i;
	char	*tmp;
	char	**tab_parse;

	i = 0;
	tmp = ft_strdup("");
	while (argv[++i])
	{
		if (ft_check_empty(argv[i]) == 1)
		{
			free(tmp);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		tmp = ft_strjoin(tmp, argv[i], ' ');
	}
	tab_parse = ft_split(tmp, ' ');
	free(tmp);
	return (tab_parse);
}

void	check_parse(char *argv[], t_stack **a)
{
	int		i;
	char	**tab_parse;
	t_stack	*node;

	i = -1;
	tab_parse = put_tab_parse(argv);
	if (!tab_parse)
	{
		ft_free(tab_parse);
		ft_putstr_fd("Error Malloc!\n", 2);
		exit(EXIT_FAILURE);
	}
	while (tab_parse[++i])
	{
		if (ft_isdigit(tab_parse[i]) || check_int(tab_parse[i])
			|| check_duplicate(tab_parse))
			ft_exit("Error\n", a);
		node = ft_lstnew(ft_atoi(tab_parse[i]));
		if (!node)
			ft_exit("Error\n", a);
		ft_lstadd_back(a, node);
	}
	check_sort(*a);
	ft_free(tab_parse);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	check_parse(argv, &a);
	get_position(&a);
	main_sort(&a, &b);
	return (0);
}
