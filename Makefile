NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -I ./includes 

RM = rm -rf

SRCS =	mandatory/push_swap.c			\
		utils/ft_atoi.c					\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/so_long.h gnl/get_next_line.h
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean