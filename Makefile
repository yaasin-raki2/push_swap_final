
NAME = push_swap

SRCS = push_swap.c sorting/sort_six_plus.c sorting/sort_five.c sorting/sort_four.c sorting/sort_three.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c instructions/check_instructions.c function_utils/ft_atoi.c function_utils/ft_strcmp.c function_utils/error_exit.c function_utils/ft_strchr.c function_utils/ft_split.c function_utils/parse_av.c list_utils/add_to_back.c list_utils/create_node.c list_utils/last_node.c list_utils/free_list.c list_utils/before_last_node.c list_utils/index_stack.c list_utils/find_smallest_index.c list_utils/list_size.c list_utils/index_of_node.c list_utils/push_side.c list_utils/last_node_index.c list_utils/search_for_index.c list_utils/init_i.c list_utils/init_stack_a.c checking/args_checking.c checking/stack_checking.c 

OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker

BONUS_SRCS = checker_bonus/checker_bonus.c checker_bonus/checking/args_checking.c checker_bonus/checking/stack_checking.c checker_bonus/list_utils/create_node.c checker_bonus/list_utils/init_stack_a.c checker_bonus/list_utils/add_to_back.c checker_bonus/list_utils/before_last_node.c checker_bonus/list_utils/last_node.c checker_bonus/function_utils/error_exit.c checker_bonus/function_utils/free_and_exit.c checker_bonus/function_utils/ft_strcmp.c checker_bonus/function_utils/ft_atoi.c checker_bonus/function_utils/ft_strlen.c checker_bonus/function_utils/ft_strjoin.c checker_bonus/function_utils/ft_strdup.c checker_bonus/function_utils/ft_strchr.c checker_bonus/function_utils/ft_split.c checker_bonus/function_utils/parse_av.c checker_bonus/instructions/swap.c checker_bonus/instructions/push.c checker_bonus/instructions/rotate.c checker_bonus/instructions/reverse_rotate.c checker_bonus/function_utils/init_stack_arr.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -I ./checker_bonus/.

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re test bonus