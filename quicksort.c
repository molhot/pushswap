/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 15:22:37 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	int			stack_mediam_a;
	size_t		counter;

	stack_mediam_a = mediam(a);
	if ((*a)->num <= stack_mediam_a)
		pa(a, b);
	counter = grasp_listlen(a);
	while (counter != 0)
	{
		if ((*a)->num <= stack_mediam_a)
			pa(a, b);
		else
			*a = (*a)->next;
		counter--;
	}
}

void	quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	while ((*a)->sorted != true)
		pa(a, b);
}

// void	insert_towedge(t_staccontent **a, t_staccontent **b)
// {
// 	while ((*a)->wedge != true)
// 	{
// 		pa(a, b);
// 	}
// 	pa(a, b);
// }

// void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
// {
// 	int		b_mediamnum;
// 	int		judgenum;
// 	size_t	b_len;

// 	b_mediamnum = mediam(b);
// 	judgenum = 0;
// 	if ((*b)->num >= b_mediamnum)
// 	{
// 		judgenum++;
// 		(*b)->wedge = true;
// 		pb(a, b);
// 	}
// 	b_len = grasp_listlen(b);
// 	while (b_len != 0)
// 	{
// 		if ((*b)->num >= b_mediamnum)
// 		{
// 			if (judgenum == 0)
// 			{
// 				(*b)->wedge = true;
// 				judgenum++;
// 			}
// 			pb(a, b);
// 		}
// 		else
// 			push_swap_rb(b);
// 		b_len--;
// 	}
// }

// void	over_3_func(t_staccontent **a, t_staccontent **b)
// {
// 	size_t	b_len;

// 	b_len = grasp_listlen(b);
// 	while (b_len > 3)
// 	{
// 		quicksort_b_to_a(a, b);
// 		b_len = grasp_listlen(b);
// 	}
// 	if (b_len == 3)
// 		patt_threenum(b);
// 	else if (b_len == 2)
// 		patt_twonum(b);
// 	while (b_len != 0)
// 	{
// 		pb(a, b);
// 		if ((*a)->wedge == true)
// 			(*a)->wedge = false;
// 		(*a)->sorted = true;
// 		push_swap_ra(a);
// 		b_len--;
// 	}
// }

// bool	wedge_checker(t_staccontent **sublist)
// {
// 	size_t		listlen;
// 	bool		judge;

// 	listlen = grasp_listlen(sublist);
// 	judge = false;
// 	while (listlen != 0)
// 	{
// 		if ((*sublist)->wedge == true)
// 			judge = true;
// 		*sublist = (*sublist)->next;
// 		listlen--;
// 	}
// 	return (judge);
// }

void	quicksort_dividearrange(t_staccontent **a, t_staccontent **b)
{
	while (1)
	{
		insert_towedge(a, b);
		over_3_func(a, b);
		if (wedge_checker(a) == false)
			return ;
	}
}

void	quicksort_main(t_staccontent **a, t_staccontent **b)
{
	quicksort_firststep(a, b);
	over_3_func(a, b);
	if (wedge_checker(a) == true)
		quicksort_dividearrange(a, b);
	quicksort_secondstep(a, b);
	over_3_func(a, b);
	if (wedge_checker(a) == true)
		quicksort_dividearrange(a, b);
}
