/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:31:26 by satushi           #+#    #+#             */
/*   Updated: 2022/11/17 21:15:13 by satushi          ###   ########.fr       */
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