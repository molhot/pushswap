/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_commonfunc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:19:20 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 18:32:21 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	over_3_func(t_staccontent **a, t_staccontent **b)
{
	size_t	b_len;

	b_len = grasp_listlen(b);
	while (b_len > 3)
	{
		quicksort_b_to_a(a, b);
		b_len = grasp_listlen(b);
	}
	if (b_len == 3)
		patt_threenum(b);
	else if (b_len == 2)
		patt_twonum(b);
	while (b_len != 0)
	{
		pb(a, b);
		if ((*a)->wedge == true)
			(*a)->wedge = false;
		(*a)->sorted = true;
		push_swap_ra(a);
		b_len--;
	}
}

void	insert_towedge(t_staccontent **a, t_staccontent **b)
{
	while ((*a)->wedge != true)
	{
		pa(a, b);
	}
	pa(a, b);
}

void	quicksort_subfunc(int jd, int b_med, \
t_staccontent **a, t_staccontent **b)
{
	if ((*b)->num >= b_med)
	{
		if (jd == 0)
		{
			(*b)->wedge = true;
			jd++;
		}
		pb(a, b);
	}
	else
		push_swap_rb(b);
}

void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int		b_mediamnum;
	int		judgenum;
	size_t	b_len;

	b_mediamnum = mediam(b);
	judgenum = 0;
	if ((*b)->num >= b_mediamnum)
	{
		judgenum++;
		(*b)->wedge = true;
		pb(a, b);
	}
	b_len = grasp_listlen(b);
	while (b_len != 0)
	{
		quicksort_subfunc(judgenum, b_mediamnum, a, b);
		b_len--;
	}
}

bool	wedge_checker(t_staccontent **sublist)
{
	size_t		listlen;
	bool		judge;

	listlen = grasp_listlen(sublist);
	judge = false;
	while (listlen != 0)
	{
		if ((*sublist)->wedge == true)
			judge = true;
		*sublist = (*sublist)->next;
		listlen--;
	}
	return (judge);
}
