/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_basicinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:30:20 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 20:20:27 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	grasp_listlen(t_staccontent **sublist)
{
	t_staccontent	**sublist_alt;
	t_staccontent	*node;
	size_t			len;

	len = 1;
	sublist_alt = sublist;
	if ((*sublist_alt)->next == *sublist_alt)
		return (1);
	node = (*sublist_alt)->next;
	while (node != *sublist_alt)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int	mediam(t_staccontent **sublist)
{
	t_staccontent	**sublist_alt;
	t_staccontent	*node;
	int				sum;
	size_t			listlen;

	sublist_alt = sublist;
	listlen = (int)grasp_listlen(sublist_alt);
	node = (*sublist_alt)->next;
	sum = node->num;
	while (node != *sublist_alt)
	{
		node = node->next;
		sum += node->num;
	}
	return (sum / (int)listlen);
}
