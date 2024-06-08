/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:38 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/08 17:58:48 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_stack
{
	int		content;
	struct s_stack	*next;
}	t_stack;

//utils
int		ft_atoi(const char *str);
void	ft_exit(char *str);
void	ft_isdigit(char *str);
void	ft_check_empty(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);


//TEST
void before_exit(void);
#endif



// ./push_swap 12 "34 56" 78 90 7 "54 36" 78 "241 54" 587

// ft_tabon_join ====> "12 34 56 78 90 7 54 36 78 241 54 587"
// ft_split ===> [12] [34] [56] [78] [90] [7] [54] [36] [78] [241] [54] [587]
// stack_A = [12] [34] [56] [78] [90] [7] [54] [36] [78] [241] [54] [587]




// int **stack_a;
// char **tmp;
// char *gathered_arguments = ft_strdup("");
// whiel(argv[i++])
// {
// 	gathered_arguments = ft_strjoin(gathered_arguments, argv[i]);
// }
// tmp = ft_split(gathered_arguments, " ");


// ra(){

// 	printf("ra\n");
// }

// pa

// 5 6 8 9  (ra) => 6 8 9 5

