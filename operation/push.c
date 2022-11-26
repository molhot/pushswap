/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:43 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 05:52:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	pushfunc(t_staccontent **inserted, t_staccontent **push)
{
	t_staccontent 	*newcontent;
	t_staccontent	*freeaddr;
	size_t pushlen;

	pushlen = grasp_listlen(push);
	freeaddr = *push;
	newcontent = (t_staccontent*)malloc(sizeof(t_staccontent) * 1);
	if (newcontent == NULL)
		return ;
	if (freeaddr->wedge)
		newcontent->wedge = true;
	else
		newcontent->wedge = false;
	if (*inserted == NULL)
		*inserted = newcontent;
	if (grasp_listlen(push) != 1)
	{
		(*push)->prev->next = (*push)->next;
		(*push)->next->prev = (*push)->prev;
	}
	newcontent->num = (*push)->num;
	newcontent->next = (*inserted);
	newcontent->prev = (*inserted)->prev;
	(*inserted)->prev = newcontent;
	(*inserted)->prev->prev->next = newcontent;
	*push = (*push)->next;
	*inserted = newcontent;
	if(pushlen == 1)
		*push = NULL;
	free(freeaddr);
}

void	pa(t_staccontent **a, t_staccontent **b)
{
	pushfunc(b, a);
}

void	pb(t_staccontent **a, t_staccontent **b)
{
	pushfunc(a, b);
}