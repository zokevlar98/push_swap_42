/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/10 16:32:19 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**put_tab_parse(int argc, char *argv[])
{
	int		i;
	char	*tmp;
	char	**tab_parse;

	i = 0;
	(void)argc;
	tmp = ft_strdup("");
	while (argv[++i])
	{
		if (ft_check_empty(argv[i]) == 1)
		{
			free(tmp);
			ft_exit("Error\n");
		}
		tmp = ft_strjoin(tmp, argv[i], ' ');
	}
	tab_parse = ft_split(tmp, ' ');
	free(tmp);
	return (tab_parse);
}

void	check_parse(int argc, char *argv[], t_stack **a)
{
	int		i;
	char	**tab_parse;
	t_stack	*node;

	tab_parse = put_tab_parse(argc, argv);
	i = 0;
	if (!tab_parse)
		ft_exit("Error\n");
	while (tab_parse[i])
	{
		if (ft_isdigit(tab_parse[i]) || check_int(tab_parse[i])
			|| check_duplicate(tab_parse))
			ft_exit("Error\n");
		node = ft_lstnew(ft_atoi(tab_parse[i]));
		if (!node)
			ft_exit("Error\n");
		ft_lstadd_back(a, node);
		i++;
	}
	ft_free(tab_parse);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		i;

	atexit(before_exit);
	a = NULL;
	i = 1;
	if (argc >= 1)
	{
		check_parse(argc, argv, &a);
		ft_lstclear(&a);
	}
	else
		exit(0);
	return (0);
}
