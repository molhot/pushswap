/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:31:26 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 20:08:27 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_swap_pa(t_staccontent **a, t_staccontent **b)
{
	t_staccontent *a_delf_b_addf;
	t_staccontent *b_newhead;
	int			  tmp_num;

	b_newhead = (t_staccontent*)malloc(sizeof(t_staccontent) * 1);
	a_delf_b_addf = *a;
	if(b_newhead == NULL)
		return ;
	tmp_num = (*a)->num;
	*a = (*a)->next;
	(*a)->prev = (*a)->prev->prev;
	(*a)->prev->next = (*a);
	free(a_delf_b_addf);

	if ((*b)->next == NULL)
	{
		free(b_newhead);
		(*b)->next = *b;
		(*b)->prev = *b;
		(*b)->num = tmp_num;
		return ;
	}
	b_newhead->next = *b;
	b_newhead->prev = (*b)->prev;
	b_newhead->num = tmp_num;
	(*b)->prev = b_newhead;
	(*b)->prev->prev->next = b_newhead;
	*b = b_newhead;
}

void push_swap_pb(t_staccontent **a, t_staccontent **b)
{
	t_staccontent *b_delf_a_addf;
	t_staccontent *a_newhead;
	int			  tmp_num;

	a_newhead = (t_staccontent*)malloc(sizeof(t_staccontent) * 1);
	b_delf_a_addf = *b;
	if(a_newhead == NULL)
	{
		free(a_newhead);
		return ;
	}
	tmp_num = (*b)->num;
	*b = (*b)->next;
	(*b)->prev = (*b)->prev->prev;
	(*b)->prev->next = (*b);
	free(b_delf_a_addf);

	if ((*a)->next == NULL)
	{
		free(a_newhead);
		(*a)->next = *a;
		(*a)->prev = *a;
		(*a)->num = tmp_num;
		return ;
	}
	a_newhead->next = *a;
	a_newhead->prev = (*a)->prev;
	a_newhead->num = tmp_num;
	(*a)->prev = a_newhead;
	(*a)->prev->prev->next = a_newhead;
	*a = a_newhead;
}