/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:43 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 19:56:34 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void print_node(t_staccontent **a)
// {
// 	t_staccontent *node;
// 	t_staccontent *first;
// 	node = *a;
// 	first = *a;
// 	int i = 0;

// 	while (node -> next != *a)
// 	{
// 		printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
// 		i++;
// 		node = node->next;
// 	}
// 	printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
// 	*a = first;
// }

static void	push_subfunc(t_staccontent **push, \
t_staccontent *newcontent, t_staccontent **inserted)
{
	newcontent->num = (*push)->num;
	newcontent->next = (*inserted);
	newcontent->prev = (*inserted)->prev;
	(*inserted)->prev = newcontent;
	(*inserted)->prev->prev->next = newcontent;
	*push = (*push)->next;
	*inserted = newcontent;
}

void	pushfunc(t_staccontent **inserted, t_staccontent **push)
{
	t_staccontent	*newcontent;
	t_staccontent	*freeaddr;
	size_t			pushlen;

	pushlen = grasp_listlen(push);
	freeaddr = *push;
	newcontent = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
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
	push_subfunc(push, newcontent, inserted);
	if (pushlen == 1)
		*push = NULL;
	free(freeaddr);
}

void	pa(t_staccontent **a, t_staccontent **b)
{
	pushfunc(b, a);
	showchar("pb\n");
}

void	pb(t_staccontent **a, t_staccontent **b)
{
	pushfunc(a, b);
	showchar("pa\n");
}
