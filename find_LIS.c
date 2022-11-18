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

static	lisinfo	*ready_LISlist()
{
	lisinfo	*lislist;

	lislist = (lisinfo *)malloc(sizeof(lisinfo) * 1);
	return (lislist);
}

static	void	inputLISf_addr(lisinfo *sublislist, t_staccontent **subjectsearchlist)
{
	size_t			counter;
	t_staccontent	*serchedlist;

	counter = sublislist->LISlen;
	serchedlist = *subjectsearchlist;
	while (serchedlist != sublislist->LISe_addr)
		serchedlist = serchedlist->next;
	while (counter != 1)
	{
		serchedlist = serchedlist->prev;
		counter--;
	}
	sublislist->LISf_addr = serchedlist;
}

lisinfo	*find_LIS(t_staccontent **subjectlist)
{
    t_staccontent   *sentinel;
    size_t			LIS_len_tmp;
	lisinfo			*LISinfolist;

    LISinfolist = ready_LISlist();
	LISinfolist->LISlen = 1;
	LIS_len_tmp = 1;
	sentinel = (*subjectlist)->next;
	while (sentinel != *subjectlist)
	{
		if(sentinel->prev->num < sentinel->num)
			LIS_len_tmp = LIS_len_tmp + 1;
		else if(sentinel->prev->num > sentinel->num && LIS_len_tmp <= LISinfolist->LISlen)
			LIS_len_tmp = 1;
		if(LIS_len_tmp > LISinfolist->LISlen)
		{
			LISinfolist->LISlen = LIS_len_tmp;
			LISinfolist->LISe_addr = sentinel;
		}
		sentinel = sentinel->next;
	}
	inputLISf_addr(LISinfolist, subjectlist);
	return (LISinfolist);
}