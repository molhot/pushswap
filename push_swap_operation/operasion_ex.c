/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operasion_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:03:20 by satushi           #+#    #+#             */
/*   Updated: 2022/11/19 20:12:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    adda_endoflist(t_staccontent **a_sub, t_staccontent **b_sub)
{
    push_swap_pb(a_sub, b_sub);
    push_swap_ra(a_sub);
}

void    addb_endoflist(t_staccontent **a_sub, t_staccontent **b_sub)
{
    push_swap_pa(a_sub, b_sub);
    push_swap_rb(a_sub);
}