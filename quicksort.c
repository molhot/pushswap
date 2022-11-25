/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:05:48 by satushi           #+#    #+#             */
/*   Updated: 2022/11/23 23:16:44 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	int	stack_mediam_a;
	t_staccontent *a_node;

	stack_mediam_a = mediam(a);
	printf("%d\n", stack_mediam_a);
	if ((*a)->num <= stack_mediam_a)
		pa(a, b);
	a_node = (*a)->next;
	while(a_node != (*a))
	{
		if ((a_node)->num <= stack_mediam_a)
			pa(a, b);
		a_node = a_node->next;
	}
}

void	quicksort_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int b_mediamnum;
	int	counter;
	t_staccontent	*b_node;

	b_mediamnum = mediam(b);
	printf("b mediam is %d\n", b_mediamnum);
	counter = 0;
	if ((*b)->num >= b_mediamnum)
	{
		counter = 1;
		(*b)->wedge = true;
		pb(a, b);
	}
	b_node = (*b)->next;
	while(b_node != (*b))
	{
		if ((*b)->num >= b_mediamnum)
		{
			if (counter == 0)
			{
				(*b)->wedge = true;
				counter = 1;
			}
			pb(a, b);
		}
		*b = (*b)->next;
	}
}

void quicksort_main(t_staccontent **a, t_staccontent **b)
{
	size_t	b_len;
	//////
	//int i = 0;;
	//////

	quicksort_firststep(a, b);
	b_len = grasp_listlen(b);
	printf("listblen is %zu\n", grasp_listlen(b));
	while (b_len > 3)// && i != 2)
	{
		printf("%s\n", "b is longer than 3 charlen");
		quicksort_b_to_a(a, b);
		b_len = grasp_listlen(b);
		printf("listblen is %zu\n", grasp_listlen(b));
		//i++;
	}
}