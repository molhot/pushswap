NAME = push_swap

SRCS = push_swap_atoi.c push_swap.c catch_basiclistinfo/grasp_basicinfo.c\
		operation/push.c operation/rotation_reverse.c operation/rotation.c operation/swap.c\
		show_char/showchar.c\
		inputvalue_checker.c\
		sorted_checker/sorted_or_not.c sorted_checker/find_LIS.c secondstep_func/check_sortedarea.c wedge_func/sorted_count_in_wedge.c\
		operation/push.c quicksort.c sort_2.c sort_3.c quicksort_commonfunc.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes

all : $(NAME)

$(NAME):$(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY:		all clean fclean re bonus