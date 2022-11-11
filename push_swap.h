/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:22 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 22:07:45 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t		num;
	struct stac	*prev;
	struct stac	*next;
}t_staccontent;

void		push_swap(int arg_num, char **num_ch);
int			ft_atoi(const char *str);
void		push_swap_ra(t_staccontent **a);
void		push_swap_rb(t_staccontent **b);
void		push_swap_rr(t_staccontent **a, t_staccontent **b);
void		push_swap_sa(t_staccontent **a);

#endif