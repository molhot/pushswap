/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_or_not.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:45:09 by satushi           #+#    #+#             */
/*   Updated: 2022/12/29 02:14:15 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool sortcheck(t_staccontent **sublist)
{
	t_staccontent *node;
	t_staccontent *f_node;

	node = *sublist;
	f_node = *sublist;
	//printf("%s\n", "this is sortchecker, worked");
	while (node->wedge != true && node->next != *sublist)
	{
		if (node->num > node->next->num)
		{
			*sublist = f_node;
			return (false);
		}
		node = node->next;
	}
	*sublist = f_node;
	return (true);
}