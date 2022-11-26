/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:03:18 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 06:03:16 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotation(t_staccontent **sub)
{
	*sub = (*sub)->next;
}

void	push_swap_ra(t_staccontent **a)
{
	rotation(a);
}

void	push_swap_rb(t_staccontent **b)
{
	rotation(b);
}

void	push_swap_rr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}