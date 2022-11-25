/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:43 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 21:29:34 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	pushfunc(t_staccontent **inserted, t_staccontent **push)
{
	t_staccontent 	*newcontent;
	t_staccontent	*freeaddr;

	freeaddr = *push;
	newcontent = (t_staccontent*)malloc(sizeof(t_staccontent) * 1);
	if ((*push)->wedge == true)
		newcontent->wedge = true;
	else
		newcontent->wedge = false;
	if (newcontent == NULL)
		return ;
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
	free(freeaddr);
	if(grasp_listlen(push) == 1)
		*push = NULL;
}

void	pa(t_staccontent **a, t_staccontent **b)
{
	pushfunc(b, a);
}

void	pb(t_staccontent **a, t_staccontent **b)
{
	pushfunc(a, b);
}