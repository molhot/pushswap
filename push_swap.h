/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:22 by satushi           #+#    #+#             */
/*   Updated: 2022/11/17 22:14:24 by satushi          ###   ########.fr       */
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
# include <stdint.h>

typedef struct stac
{
	int		num;
	struct stac	*prev;
	struct stac	*next;
}t_staccontent;

typedef struct LISinfo
{
	size_t	LISlen;
	struct stac	*LISf_addr;
	struct stac	*LISe_addr;
}lisinfo;

void		push_swap(int arg_num, char **num_ch);
int			ft_atoi(const char *str);
void		push_swap_sa(t_staccontent **a);
void		push_swap_sb(t_staccontent **b);
void		push_swap_ss(t_staccontent **a,t_staccontent **b);

void		push_swap_pa(t_staccontent **a, t_staccontent **b);


void		push_swap_ra(t_staccontent **a);
void		push_swap_rb(t_staccontent **b);
void		push_swap_rr(t_staccontent **a, t_staccontent **b);

void		push_swap_rra(t_staccontent **a);
void		push_swap_rrb(t_staccontent **b);
void		push_swap_rrr(t_staccontent **a, t_staccontent **b);

lisinfo		*find_LIS(t_staccontent **subjectlist);

size_t    	grasp_listlen(t_staccontent **subject_list2);
void		grasp_listmaxvalue(t_staccontent **subject_list);
void		grasp_listmaxvalue(t_staccontent **subject_list);

size_t		grasp_mediamnum_oflist(t_staccontent **subject);

#endif