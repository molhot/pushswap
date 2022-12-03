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
