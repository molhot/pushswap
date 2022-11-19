/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasplist_len_mav_miv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:43:18 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 20:51:07 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
    }
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
		if(maxvalue < (size_t)sentinel_forlist->num)
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
		if(minvalue > (size_t)sentinel_forlist->num)
			minvalue = sentinel_forlist->num;
		sentinel_forlist = sentinel_forlist->next;
	}
	printf("minvalue is %ld\n", minvalue);
}