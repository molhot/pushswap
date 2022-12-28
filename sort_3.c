/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:33:46 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 18:45:18 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	patt_threenum(t_staccontent **list)
// {
// 	int	f_num;
// 	int	s_num;
// 	int	t_num;

// 	f_num = (*list)->num;
// 	s_num = (*list)->next->num;
// 	t_num = (*list)->next->next->num;
// 	if (f_num > s_num && s_num > t_num)
// 	{
// 		push_swap_rb(list);
// 		push_swap_sb(list);
// 	}
// 	if (t_num > s_num && f_num > t_num)
// 		push_swap_rb(list);
// 	if (f_num > s_num && t_num > f_num)
// 		push_swap_sb(list);
// 	if (s_num > f_num && f_num > t_num)
// 		push_swap_rrb(list);
// 	if (s_num > t_num && t_num > f_num)
// 	{
// 		push_swap_rb(list);
// 		push_swap_sb(list);
// 		push_swap_rrb(list);
// 	}
// }

void	patt_threenum(t_staccontent **list)
{
	if ((*list)->num > (*list)->next->num && (*list)->next->num > (*list)->next->next->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
	}
	if ((*list)->next->next->num > (*list)->next->num && (*list)->num > (*list)->next->next->num)
		push_swap_rb(list);
	if ((*list)->num > (*list)->next->num && (*list)->next->next->num > (*list)->num)
		push_swap_sb(list);
	if ((*list)->next->num > (*list)->num && (*list)->num > (*list)->next->next->num)
		push_swap_rrb(list);
	if ((*list)->next->num > (*list)->next->next->num && (*list)->next->next->num > (*list)->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
		push_swap_rrb(list);
	}
}
