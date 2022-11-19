/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_sortneed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:20:33 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 21:36:30 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_remaingnumis_overpivot(t_staccontent **subject)
{
    int             pivot;
    t_staccontent   *sentinel;

    pivot = (*subject)->num;
    sentinel = (*subject)->next;
    while(sentinel != (*subject))
    {
        if(pivot > sentinel->num)
        {
            printf("pivot is %d\n", pivot);
            return (1);
        }
        sentinel = sentinel->next;
    }
    return (0);
}