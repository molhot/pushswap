/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeout_basiclist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:04:17 by satushi           #+#    #+#             */
/*   Updated: 2022/11/16 21:10:49 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t    grasp_listlen(t_staccontent **subject_list2)
{
    size_t          listlen;
    t_staccontent   *sentinel_list;

    listlen = 1;
    sentinel_list = *subject_list2;
    while(sentinel_list->next != *subject_list2)
    {
        listlen = listlen + 1;
        sentinel_list = sentinel_list->next;
        printf(" list len is %zu\n", listlen);
    }
    printf("list len is %zu\n", listlen);
	return (listlen);
}

void	grasp_listmaxvalue(t_staccontent **subject_list)
{
	size_t			maxvalue;
	t_staccontent	*sentinel_forlist;

	maxvalue = (*subject_list)->num;
	sentinel_forlist = *subject_list;
	while(sentinel_forlist->next != *subject_list)
	{
		if(maxvalue < sentinel_forlist->num)
			maxvalue = sentinel_forlist->num;
		sentinel_forlist = sentinel_forlist->next;
	}
	printf("maxvalue is %ld\n", maxvalue);
}

void	grasp_listminvalue(t_staccontent **subject_list)
{
	size_t			minvalue;
	t_staccontent	*sentinel_forlist;

	minvalue = (*subject_list)->num;
	sentinel_forlist = *subject_list;
	while(sentinel_forlist->next != *subject_list)
	{
		if(minvalue > sentinel_forlist->num)
			minvalue = sentinel_forlist->num;
		sentinel_forlist = sentinel_forlist->next;
	}
	printf("minvalue is %ld\n", minvalue);
}
