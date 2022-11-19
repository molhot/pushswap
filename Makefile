NAME = push_swap.a

SRCS = push_swap_operation/push.c push_swap_operation/rotation_reverse.c \
		push_swap_operation/rotation.c push_swap_operation/swap.c push_swap_operation/operasion_ex.c \
		takeout_basiclistinfo/grasplist_len_mav_miv.c takeout_basiclistinfo/grasp_mediam.c find_LIS.c push_swap_atoi.c \
		quicksort_basicfunc/checking_sortneed.c \
		push_swap.c quicksort_forlist.c

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