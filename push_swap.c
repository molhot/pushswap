/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/26 05:14:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization(void)
{
	t_staccontent	**subject_list;

	subject_list = (t_staccontent **)malloc(sizeof(t_staccontent *) * 1);
	if (subject_list == NULL)
		return (NULL);
	*subject_list = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	if (*subject_list == NULL)
	{
		free(subject_list);
		return (NULL);
	}
	return (subject_list);
}

void	insert_info_tolist(t_staccontent *nowaddr, \
int n, int last, t_staccontent *f_addr)
{
	if (n == last)
		nowaddr->next = f_addr;
	else
		nowaddr->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	nowaddr->next->prev = nowaddr;
	nowaddr->wedge = false;
	nowaddr->sorted = false;
}

t_staccontent	**insertelem_tostack(int counter, char **numstr)
{
	t_staccontent	**a;
	t_staccontent	*node;
	int				i;

	a = list_initialization();
	if (a == NULL)
		return (NULL);
	node = *a;
	i = 1;
	while (i != counter)
	{
		insert_info_tolist(node, i, counter - 1, *a);
		node->num = ft_atoi(numstr[i]);
		node = node->next;
		i++;
	}
	return (a);
}

t_staccontent	**push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;

	a = insertelem_tostack(arg_num, num_ch);
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	quicksort_main(a, b);
	return (a);
}

int	main(int argc, char **argv)
{
	int				i;
	t_staccontent	*node;
	t_staccontent	**a;

	i = 0;
	a = push_swap(argc, argv);
	node = (*a);
	while (node->next != *a)
	{
		printf("|%d is %d and addr is %p and node true or not is %d|\n", \
		i, node->num, node, node->wedge);
		node = node->next;
	}
	printf("|%d is %d and addr is %p and node true or not is %d|\n", \
	i, node->num, node, node->wedge);
	return (1);
}
