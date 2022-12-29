/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sortedarea.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:19:54 by user              #+#    #+#             */
/*   Updated: 2022/12/29 16:29:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int check_sorted_in_list(t_staccontent **list);
{
	t_staccontent	*list_f;
	t_staccontent	*node;
	int		tentative_most_minimumnum;
	int		counter;
	int		tmp_buff;

	list_f = *list;
	node = *list;
	tentative_most_minimumnum = node->num;
	while (node->sorted != true)
	{
		node = node->next;
		if (node->num < tentative_most_minimumnum)
		{
			*list = list_f;
			return (0);
		}
	}
	counter = 0;
    node = list_f;
	tmp_buff = node->num;
	while (node->before->wedge != true)
	{
		node = node->next;
		if (node->sorted != true)
		{
			*list = list_f;
			return (counter);
		}
		tmp_buff = node->num;
		counter++;
	}
    *list = list_f;
	return (counter);
}