/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_basicinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:30:20 by satushi           #+#    #+#             */
/*   Updated: 2022/11/23 16:30:21 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t grasp_listlen(t_staccontent **sublist)
{
	t_staccontent	*node;
	size_t			len;

	len = 1;
	if ((*sublist)->next == *sublist)
		return (1);
	node = (*sublist)->next;
	while (node != *sublist)
	{
		len++;
		node =node->next;
	}
	return (len);
}

int	mediam(t_staccontent **sublist)
{
	t_staccontent	*node;
	int				sum;
	size_t			listlen;

	listlen = (int)grasp_listlen(sublist);
	node = (*sublist)->next;
	sum = node->num;
	while (node != *sublist)
	{
		node =node->next;
		sum += node->num;
	}
	return (sum / listlen);
}