/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:45 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 21:55:52 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sa(t_staccontent **a)
{
	int				tmp_num;
	t_staccontent	*first;
	t_staccontent	*second;

	first = *a;
	if (first->next == NULL)
		return ;
	second = first->next;
	tmp_num = first->num;
	first->num = second->num;
	second->num = tmp_num;
}

void	push_swap_ra(t_staccontent **a)
{
	*a = (*a)->next;
}

void	push_swap_rb(t_staccontent **b)
{
	*b = (*b)->next;
}

void	push_swap_rr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}
