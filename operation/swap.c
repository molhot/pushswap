/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:52:05 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 04:11:46 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_staccontent **sub)
{
	t_staccontent *old;
	t_staccontent *new;
	t_staccontent *tmp;

	old = *sub;
	new = (*sub)->next;
	tmp = (*sub)->prev;
	if (old == tmp)
		return ;
	tmp->next = new;
	old->next = new->next;
	old->prev = new;
	new->prev = tmp;
	new->next = old;
	old->next->prev = old;
	*sub = new;
}

void	push_swap_sa(t_staccontent **a)
{
	swap(a);
}

void	push_swap_sb(t_staccontent **b)
{
	swap(b);
}

void	push_swap_ss(t_staccontent **a,t_staccontent **b)
{
	int a_tmp;
	int b_tmp;
	t_staccontent *a_first;
	t_staccontent *b_first;
	t_staccontent *a_second;
	t_staccontent *b_second;

	if((*a)->next == *a || (*b)->next == *b)
	{
		if ((*a)->next != *a)
			push_swap_sa(a);
		else if((*b)->next != *b)
			push_swap_sa(b);
		return ;
	}
	a_first = *a;
	a_tmp = a_first->num;
	b_first = *b;
	b_tmp = b_first->num;
	a_second = a_first->next;
	b_second = b_first->next;
	a_first->num = a_second->num;
	b_first->num = b_second->num;
	a_second->num = a_tmp;
	b_second->num = b_tmp;
}