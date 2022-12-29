/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 15:33:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	int			stack_mediam_a;
	int			tmp_buf;
	size_t		counter;

	stack_mediam_a = mediam(a);
	if ((*a)->num <= stack_mediam_a)
		pa(a, b);
	counter = grasp_listlen(a);
	while (counter != 0)
	{
		if ((*a)->num <= stack_mediam_a)
		{
		 	if (tmp_buf < (*a)->num)
				pa(a, b);
			else
			{
				pa(a, b);
				push_swap_rb(b);
			}
			tmp_buf = (*b)->num;
		}
		else
			push_swap_ra(a);
		counter--;
	}
}

void	quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	int			tmp_buf;
	int			sorted_counter;

	// while ((*a)->sorted != true)
	// {
	// 	pa(a, b);
	// }
	// 	ここも少し変えれるかもしれない
	// aはソート済みで、的確に数の準場版がわかれば一部はaの中で完結する
	sorted_counter = check_sorted_in_list(a);
	if (sorted_counter != 0)
	{
		while (sorted_counter != 0)
		{
			(*a)->sorted = true;
			push_swap_ra(a);
		}
	}
	while ((*a)->sorted != true)
	{
		if (tmp_buf < (*a)->num)
			pa(a, b);
		else
			pa(a, b);
		tmp_buf = (*b)->num;
	}
}

void	quicksort_dividearrange(t_staccontent **a, t_staccontent **b)
{
	int counter;

	while (1)
	{
		if (sortcheck(a) == true)
		{
			//printf("%s\n", "this is works");
			//別関数に移してよいかも
			while ((*a)->wedge != true)
			{
				(*a)->sorted = true;
				push_swap_ra(a);
			}
			(*a)->wedge = false;
			(*a)->sorted = true;
			push_swap_ra(a);
		}
		else
		{
			//ここをもう少し帰れそう
			//wedgeまでの数の比較を行い、並んでいるところまではaの後ろに着ける
			//2個とか3個ならここで処理してもよいかもしれない
			counter = sorted_count(a);
			while(counter != 0)
			{
				//printf("%s\n", "here is moved");
				(*a)->wedge = false;
				(*a)->sorted = true;
				push_swap_ra(a);
				counter--;
			}
			insert_towedge(a, b);
			over_3_func(a, b);
		}
		if (wedge_checker(a) == false)
			return ;
	}
}

void print_anode(t_staccontent **a)
{
	t_staccontent *node;
	t_staccontent *first;
	node = *a;
	first = *a;
	int i = 0;

	while (node -> next != *a)
	{
		//printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
		i++;
		node = node->next;
	}
	//printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
	*a = first;
}

void	quicksort_main(t_staccontent **a, t_staccontent **b)
{
	if (grasp_listlen(a) == 2)
	{
		push_swap_sa(a);
		return ;
	}
	if (grasp_listlen(a) == 3)
	{
		if ((*a)->num > (*a)->next->num && (*a)->next->num > (*a)->next->next->num)
		{
			push_swap_ra(a);
			push_swap_sa(a);
		}
		if ((*a)->next->next->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
			push_swap_ra(a);
		if ((*a)->num > (*a)->next->num && (*a)->next->next->num > (*a)->num)
			push_swap_sa(a);
		if ((*a)->next->num > (*a)->num && (*a)->num > (*a)->next->next->num)
			push_swap_rra(a);
		if ((*a)->next->num > (*a)->next->next->num && (*a)->next->next->num > (*a)->num)
		{
			push_swap_ra(a);
			push_swap_sa(a);
			push_swap_rra(a);
		}
		return ;
	}
	quicksort_firststep(a, b);
	over_3_func(a, b);
	//print_anode(a);
	if (wedge_checker(a) == true)
		quicksort_dividearrange(a, b);
	quicksort_secondstep(a, b);
	over_3_func(a, b);
	if (wedge_checker(a) == true)
		quicksort_dividearrange(a, b);
}
