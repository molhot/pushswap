/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:57:14 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 22:21:03 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    patt_twonum(t_staccontent **list)
{
    int f_num;
    int s_num;

    f_num = (*list)->num;
    s_num = (*list)->next->num;

    if (f_num > s_num)
        push_swap_sa(list);
}