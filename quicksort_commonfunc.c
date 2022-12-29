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

/*static void print_node(t_staccontent **a)
{
	t_staccontent *node;
	t_staccontent *first;
	node = *a;
	first = *a;
	int i = 0;

	while (node -> next != *a)
	{
		printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
		i++;
		node = node->next;
	}
	printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
	*a = first;
}*/


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
	{
		//printf("b_len is not zero!\n");
		patt_threenum(b);
	}
	else if (b_len == 2)
	{
		//printf("blen is not zero!!\n");
		patt_twonum(b);
	}
	//printf("blen is not zero!!\n");
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
		pa(a, b);
	pa(a, b);
}

// ここも少し変えられる
//
void	quicksort_subfunc(int *jd, int b_med, \
t_staccontent **a, t_staccontent **b)
{
	if ((*b)->num >= b_med)
	{
		if (*jd == 0)
		{
			(*b)->wedge = true;
			*jd = *jd + 1;
		}
		pb(a, b);
	}
	else
		push_swap_rb(b);
}

bool should_continue_subfunc(t_staccontent **list, size_t listlen, int b_mediam)
{
	t_staccontent	*f_list;
	t_staccontent	*node;

	f_list = *list;
	node = *list;
	while (listlen != 0)
	{
		if (node->num >= b_mediam)
		{
			*list = f_list;
			return (true);
		}
		node = node->next;
		listlen--;
	}
	*list = f_list;
	return (false);
}

void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int		b_mediamnum;
	int		judgenum;
	size_t	b_len;

	b_mediamnum = mediam(b);
	judgenum = 0;
	//print_node(b);
	if ((*b)->num >= b_mediamnum)
	{
		judgenum++;
		(*b)->wedge = true;
		pb(a, b);
	}
	//blen が全権探索する必要はないのでは
	b_len = grasp_listlen(b);
	// if (subfunc_is_notneed(b, b_len, b_mediamnum) == false)
	// 	return ;
	while (b_len != 0)
	{
		//printf("%s\n", "this is moved");
		if (should_continue_subfunc(b, b_len, b_mediamnum) == false)
			return ;
		quicksort_subfunc(&judgenum, b_mediamnum, a, b);
		b_len--;
	}
	//printf("---------\n");
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
