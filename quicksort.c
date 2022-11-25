/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 22:40:30 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	int	stack_mediam_a;
	size_t counter;

	stack_mediam_a = mediam(a);
	if ((*a)->num <= stack_mediam_a)
		pa(a, b);
	counter = grasp_listlen(a);
	while(counter != 0)
	{
		if ((*a)->num <= stack_mediam_a)
			pa(a, b);
		else
			*a = (*a)->next;
		counter--;
	}
}

void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int b_mediamnum;
	int	judgenum;
	size_t b_len;

	b_mediamnum = mediam(b);
	judgenum = 0;
	if ((*b)->num >= b_mediamnum)
	{
		judgenum++;
		(*b)->wedge = true;
		pb(a, b);
	}
	b_len = grasp_listlen(b);
	while(b_len != 0)
	{
		if ((*b)->num >= b_mediamnum)
		{
			if (judgenum == 0)
			{
				(*b)->wedge = true;
				judgenum++;
			}
			pb(a, b);
		}
		else
			*b = (*b)->next;
		b_len--;
	}
}

void quicksort_main(t_staccontent **a, t_staccontent **b)
{
	size_t	b_len;

	////////////////////////
	t_staccontent **a_alt;
	t_staccontent **b_alt;
	t_staccontent *b_node;
	t_staccontent *a_node;
	///////////////////////

	quicksort_firststep(a, b);

	///////////////////////
	a_alt = a;
	b_alt = b;
	a_node = *a_alt;
	b_node = *b_alt;
	for(int i=0;i<13;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, a_node->num, a_node, a_node->wedge);
		a_node = a_node->next;
	}
	printf("\n@@ next is b's test @@\n\n");
	for(int i=0;i<13;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, b_node->num, b_node, b_node->wedge);
		b_node = b_node->next;
	}
	printf("\n@@ here is test space @@\n\n");
	printf("\n------------ testcase is ended ----------------\n\n\n");
	//$$$$$$$$$$$$$$$$$$$$$$$//

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

	///////////////////////
	a_alt = a;
	b_alt = b;
	a_node = *a_alt;
	b_node = *b_alt;
	for(int i=0;i<13;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, a_node->num, a_node, a_node->wedge);
		a_node = a_node->next;
	}
	printf("\n@@ next is b's test @@\n\n");
	for(int i=0;i<13;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, b_node->num, b_node, b_node->wedge);
		b_node = b_node->next;
	}
	printf("\n@@ here is test space @@\n\n");
	//$$$$$$$$$$$$$$$$$$$$$$$//
}