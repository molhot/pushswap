/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:45 by satushi           #+#    #+#             */
/*   Updated: 2022/11/14 21:00:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sa(t_staccontent **a)
{
	int tmp;
	t_staccontent *first;
	t_staccontent *second;

	first = *a;
	tmp = first->num;
	second = first->next;
	first->num = second->num;
	second->num = tmp;
}

void	push_swap_sb(t_staccontent **b)
{
	int tmp;
	t_staccontent *first;
	t_staccontent *second;

	first = *b;
	tmp = first->num;
	second = first->next;
	first->num = second->num;
	second->num = tmp;
}

void	push_swap_ss(t_staccontent **a,t_staccontent **b)
{
	int a_tmp;
	int b_tmp;
	t_staccontent *a_first;
	t_staccontent *b_first;
	t_staccontent *a_second;
	t_staccontent *b_second;

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

void push_swap_pa(t_staccontent **a, t_staccontent **b)
{
	t_staccontent *a_delf_b_addf;
	t_staccontent *a_nextf;
	t_staccontent *a_last;
	t_staccontent *b_nextn;
	t_staccontent *b_last;
	t_staccontent *b_newhead;
	int			  tmp_num;

	b_newhead = (t_staccontent*)malloc(sizeof(t_staccontent) * 1);
	if(b_newhead == NULL)
		return ;
	tmp_num = (*a)->num;
	*a = (*a)->next;
	(*a)->prev = ((*a)->prev)->prev;
	free(a_delf_b_addf);

	b_newhead->next = *b;
	b_newhead->prev = (*b)->prev;
	(*b)->prev = b_newhead;
	(*b)->prev->prev->next = b_newhead;
	*b = b_newhead;
}

void	push_swap_ra(t_staccontent **a)
{
	*a = (*a)->next;
}

void	push_swap_rb(t_staccontent **b)
{
	*b = (*b)->next;
}

void	push_swap_rr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}

void	push_swap_rra(t_staccontent **a)
{
	*a = (*a)->prev;
}

void	push_swap_rra(t_staccontent **b)
{
	*b = (*b)->prev;
}

void	push_swap_rrr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
}