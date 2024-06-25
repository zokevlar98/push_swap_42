/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:38 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/25 01:58:05 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int		content;
	int		position;
	struct s_stack	*next;
}	t_stack;

//utils
int		ft_atoi(char *str);
void	ft_exit(char *str);
void	check_args(int argc, char *argv[]);
int		ft_isdigit(char *str);
int		ft_check_empty(char *str);
int		check_int(char *str);
int		check_duplicate(char **str);
int		check_sort(t_stack *a);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, char del);
char	**ft_split(char const *s, char c);
void	ft_free(char **tab);
char	*ft_strdup(char *s1);
void	get_position(t_stack **a);
int		get_index(t_stack **a, int position);
//linked_list
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
t_stack	*Before_last(t_stack *a);
//operations
void	swap(t_stack **a, char c);
void	rotate(t_stack **a, char c);
void 	reverse_rotate(t_stack **a, char c);
void	ft_push(t_stack **a, t_stack **b, char c);
//sort
void	main_sort(t_stack *a, t_stack *b);
int		ft_check_small(t_stack *a);
void	help_sort_five(t_stack **a, t_stack **b);
void	help_sort_four(t_stack **a, t_stack **b);
void	push_it(t_stack **a, t_stack **b, int c_chunk, int last_e);
void	push_it_back(t_stack **a, t_stack **b);
//TEST
void	before_exit(void);
void	ft_display(char **str);
void	ft_dis_link(t_stack *a);
#endif