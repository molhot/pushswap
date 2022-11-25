/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:33:46 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 22:39:52 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void patt_threenum(t_staccontent **list)
{
    const int f_num = (*list)->num;
    const int s_num = (*list)->next->num;
    const int t_num = (*list)->next->next->num;

    if (f_num > s_num && s_num > t_num)
    {
        push_swap_ra(list);
        push_swap_sa(list);
    }
    if (f_num > s_num && t_num > s_num)
        push_swap_ra(list);
    if (f_num > s_num && t_num > f_num)
        push_swap_sa(list);
    if (s_num > f_num && f_num > t_num)
        push_swap_rra(list);
    if (s_num > t_num && t_num > f_num)
    {
        push_swap_ra(list);
        push_swap_sa(list);
        push_swap_rra(list);
    }
}