/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 18:32:30 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	int	stack_mediam_a;
	size_t counter;

	stack_mediam_a = mediam(a);
	printf("%d\n", stack_mediam_a);
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

void	quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	while ((*a)->sorted != true)
		pa(a, b);
}

void insert_towedge(t_staccontent **a, t_staccontent **b)
{
	while ((*a)->wedge != true)
	{
		pa(a, b);
	}
	pa(a,b);
}

void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int b_mediamnum;
	int	judgenum;
	size_t b_len;

	b_mediamnum = mediam(b);
	printf("quicksort b to a is %d\n\n",b_mediamnum);
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
			push_swap_rb(b);
		b_len--;
	}
}

void over_3_func(t_staccontent **a, t_staccontent **b)
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

bool wedge_checker(t_staccontent **sublist)
{
	t_staccontent **sublist_alt;
	size_t listlen;

	sublist_alt = sublist;
	listlen = grasp_listlen(sublist);
	printf("listlen is %ld",listlen);
	while (listlen != 0)
	{
		if ((*sublist_alt)->wedge == true)
			return true;
		*sublist_alt = (*sublist_alt)->next;
		listlen--;
	}
	return false;
}

void quicksort_main(t_staccontent **a, t_staccontent **b)
{
	//size_t	b_len;

	////////////////////////
	t_staccontent **a_alt;
	//t_staccontent **b_alt;
	//t_staccontent *b_node;
	t_staccontent *a_node;
	///////////////////////

	quicksort_firststep(a, b);
	over_3_func(a, b);


	// over_3_func(a, b);
	// insert_towedge(a, b);
	// over_3_func(a, b);
	// insert_towedge(a, b);
	// over_3_func(a, b);
	// insert_towedge(a, b);
	// over_3_func(a, b);
	// insert_towedge(a, b);
	// over_3_func(a, b);
	// insert_towedge(a, b);
	// over_3_func(a, b);

	printf("\n\n------------------------------\n\n");

	while (wedge_checker(a) != false)
	{
		if (wedge_checker(a) == false)
			return ;
		insert_towedge(a, b);
		over_3_func(a, b);
	}

	printf("\n\n------------------------------\n\n");

	quicksort_secondstep(a, b);

	printf("\n\n------------------------------\n\n");

	// while (wedge_checker(a) != false)
	// {
	// 	over_3_func(a, b);
	// 	if (wedge_checker(a) == false)
	// 		return ;
	// 	insert_towedge(a, b);
	// }

	over_3_func(a, b);
	//insert_towedge(a, b);
	//over_3_func(a, b);


	a_alt = a;
	//b_alt = b;
	a_node = *a_alt;
	//b_node = *b_alt;
	for(int i=0;i<18;i++)
	{
		printf("|%dth is %d and addr is %p and node true or not is %d and sorted is %d|\n",i, a_node->num, a_node, a_node->wedge, a_node->sorted);
		a_node = a_node->next;
	}
	// printf("\n@@ next is b's test @@\n\n");
	// for(int i=0;i<13;i++)
	// {
	// 	printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, b_node->num, b_node, b_node->wedge);
	// 	b_node = b_node->next;
	// }
	printf("\n@@ here is test space @@\n\n");
}

	// a_alt = a;
	// //b_alt = b;
	// a_node = *a_alt;
	// //b_node = *b_alt;
	// for(int i=0;i<13;i++)
	// {
	// 	printf("|%dth is %d and addr is %p and node true or not is %d and sorted is %d|\n",i, a_node->num, a_node, a_node->wedge, a_node->sorted);
	// 	a_node = a_node->next;
	// }
	// // printf("\n@@ next is b's test @@\n\n");
	// // for(int i=0;i<13;i++)
	// // {
	// // 	printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, b_node->num, b_node, b_node->wedge);
	// // 	b_node = b_node->next;
	// // }
	// printf("\n@@ here is test space @@\n\n");

///////////////////////
	// a_alt = a;
	// b_alt = b;
	// a_node = *a_alt;
	// b_node = *b_alt;
	// for(int i=0;i<13;i++)
	// {
	// 	printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, a_node->num, a_node, a_node->wedge);
	// 	a_node = a_node->next;
	// }
	// printf("\n@@ next is b's test @@\n\n");
	// for(int i=0;i<13;i++)
	// {
	// 	printf("|%dth is %d and addr is %p and node true or not is %d|\n",i, b_node->num, b_node, b_node->wedge);
	// 	b_node = b_node->next;
	// }
	// printf("\n@@ here is test space @@\n\n");
//$$$$$$$$$$$$$$$$$$$$$$$//