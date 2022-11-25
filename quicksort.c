/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 20:55:37 by satushi          ###   ########.fr       */
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

	///
	printf("bmediam is -> %d\n\n", b_mediamnum);
	///
	
	judgenum = 0;
	if ((*b)->num >= b_mediamnum)
	{
		printf("here is under control\n");
		judgenum++;
		(*b)->wedge = true;
		pb(a, b);
		printf("judgenum is %d \n", judgenum);
	}
	b_len = grasp_listlen(b);
	while(b_len != 0)
	{
		if ((*b)->num >= b_mediamnum)
		{
			if (judgenum == 0)
			{
				printf("here is under control hoo\n");
				printf("judgenum is %d \n", judgenum);
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
	t_staccontent **b_alt;
	t_staccontent *node;
	///////////////////////

	quicksort_firststep(a, b);

	///////////////////////
	b_alt = b;
	node = *b_alt;
	for(int i=0;i<12;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, node->num, node, node->wedge);
		node = node->next;
	}
	printf("\n@@ here is test space @@\n\n");
	///////////////////////

	b_len = grasp_listlen(b);
	while (b_len > 3)
	{
		quicksort_b_to_a(a, b);
		b_len = grasp_listlen(b);
	}
}