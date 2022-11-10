#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>


typedef struct stac
{
	int				num;
	struct stac 	*prev;
	struct stac		*next;
}stac_content;


void			push_swap(size_t arg_num, char **num_ch);
int				ft_atoi(const char *str);
void			push_swap_ra(stac_content **a);

# endif