/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_forlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:05:39 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 21:48:53 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quicksortfunc(t_staccontent **a, t_staccontent **b)
{
    int             pivot;
    t_staccontent   *sentinel;
	int				b_insertcounter;
	size_t			list_counter;
	int				judge_pivot;
	//fortest 
	int i = 0;
	t_staccontent	*listestb;
	//here is end

    sentinel = *a;
    if (find_LIS(a)->LISlen == grasp_listlen(a))
        return 0;
	judge_pivot = check_remaingnumis_overpivot(a);
    while (judge_pivot == 0)
	{
		push_swap_ra(a);
		judge_pivot = check_remaingnumis_overpivot(a);
	}
	pivot = (*a)->num;
	list_counter = grasp_listlen(a);
	b_insertcounter = 0;
	while (list_counter != 0)
	{
		if (pivot <= sentinel->num)
		{
			b_insertcounter++;
			push_swap_pa(a, b);
		}
		list_counter--;
	}
	printf("bcounter is %d\n", b_insertcounter);
	listestb = *b;
	while(i != 4)
		{
			printf("b's int is %d\n", listestb->num);
			listestb = listestb->next;
			i = i + 1;
		}
		i = 0;
	while (b_insertcounter != 0)
	{
		adda_endoflist(a, b);
		b_insertcounter--;
	}
	return 1;
}

void	quicksortrepeat(t_staccontent **a, t_staccontent **b)
{
	int	judgerepeatend;
	int i = 0;
	t_staccontent	*listesta;

	judgerepeatend = 1;
	listesta = *a;
	while(judgerepeatend == 1)
	{
		printf("\n%s\n", "-----------------------");
		while(i != 8)
		{
			printf("a's int is %d\n", listesta->num);
			listesta = listesta->next;
			i = i + 1;
		}
		i = 0;
		printf("\n%s\n", "-----------------------");
		judgerepeatend = quicksortfunc(a, b);
		listesta = *a;
	}
}