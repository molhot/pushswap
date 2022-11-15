/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeout_basiclist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:04:17 by satushi           #+#    #+#             */
/*   Updated: 2022/11/15 22:20:14 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    grasp_listlen(t_staccontent **subject_list2)
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
}