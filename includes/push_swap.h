/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:38 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/07 19:03:43 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct	s_stack
{
	int		stack;
	void	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		number;
	t_stack *tmp;
}	t_data;

int		ft_atoi(const char *str);
void	ft_exit(char *str);
void	ft_isdigit(char *str);
void	ft_check_empty(char *str);


#endif



./push_swap 12 "34 56" 78 90 7 "54 36" 78 "241 54" 587

ft_tabon_join ====> "12 34 56 78 90 7 54 36 78 241 54 587"
ft_split ===> [12] [34] [56] [78] [90] [7] [54] [36] [78] [241] [54] [587]
stack_A = [12] [34] [56] [78] [90] [7] [54] [36] [78] [241] [54] [587]




int **stack_a;
char **tmp;
char *gathered_arguments = ft_strdup("");
whiel(argv[i++])
{
	gathered_arguments = ft_strjoin(gathered_arguments, argv[i]);
}
tmp = ft_split(gathered_arguments, " ");


ra(){

	printf("ra\n");
}

pa

5 6 8 9  (ra) => 6 8 9 5

