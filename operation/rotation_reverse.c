/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:04:20 by satushi           #+#    #+#             */
/*   Updated: 2022/11/22 13:05:40 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap_rra(t_staccontent **a)
{
	*a = (*a)->prev;
}

void	push_swap_rrb(t_staccontent **b)
{
	*b = (*b)->prev;
}

void	push_swap_rrr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
}