/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:31:44 by satushi           #+#    #+#             */
/*   Updated: 2022/11/17 22:56:39 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_lisinfo	*ready_lislist(void)
{
	t_lisinfo	*lislist;

	lislist = (t_lisinfo *)malloc(sizeof(t_lisinfo) * 1);
	return (lislist);
}

static	void	inputlisf_addr\
(t_lisinfo *sublist, t_staccontent **serchlist)
{
	size_t			counter;
	t_staccontent	*serchedlist;

	counter = sublist->lislen;
	serchedlist = *serchlist;
	while (serchedlist != sublist->lisf_addr)
		serchedlist = serchedlist->next;
	while (counter != 1)
	{
		serchedlist = serchedlist->prev;
		counter--;
	}
	sublist->lisf_addr = serchedlist;
}

t_lisinfo	*find_lis(t_staccontent **subjectlist)
{
	t_staccontent	*sentinel;
	size_t			lislentmp;
	t_lisinfo		*lisinfolist;

	lisinfolist = ready_lislist();
	lisinfolist->lislen = 1;
	lislentmp = 1;
	sentinel = (*subjectlist)->next;
	while (sentinel != *subjectlist)
	{
		if (sentinel->prev->num < sentinel->num)
			lislentmp = lislentmp + 1;
		else if (sentinel->prev->num > sentinel->num && \
		lislentmp <= lisinfolist->lislen)
			lislentmp = 1;
		if (lislentmp > lisinfolist->lislen)
		{
			lisinfolist->lislen = lislentmp;
			lisinfolist->lise_addr = sentinel;
		}
		sentinel = sentinel->next;
	}
	inputlisf_addr(lisinfolist, subjectlist);
	return (lisinfolist);
}
