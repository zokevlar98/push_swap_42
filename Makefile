NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -I ./includes 

RM = rm -rf

SRCS =	mandatory/push_swap.c			\
		mandatory/operation.c			\
		utils/ft_atoi.c					\
		utils/ft_exit.c					\
		utils/parsing.c					\
		utils/ft_put_fd.c				\
		utils/clear_link_utils.c		\
		utils/ft_split.c 				\
		utils/ft_strlen.c 				\
		utils/ft_strjoin.c 				\
		utils/link_utils.c				\
		utils/ft_strdup.c				\
		utils/utils.c					\
		mandatory/sort.c				\
		mandatory/utils_algo.c			\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean