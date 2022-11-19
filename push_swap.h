/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:22 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 21:29:00 by satushi          ###   ########.fr       */
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
	int		pivot_or_not;
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
void		push_swap_pb(t_staccontent **a, t_staccontent **b);

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

int			check_remaingnumis_overpivot(t_staccontent **subject);

int			quicksortfunc(t_staccontent **a, t_staccontent **b);
void		quicksortrepeat(t_staccontent **a, t_staccontent **b);

void		adda_endoflist(t_staccontent **a_sub, t_staccontent **b_sub);
void		addb_endoflist(t_staccontent **a_sub, t_staccontent **b_sub);

#endif