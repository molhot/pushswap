/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 21:28:16 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization()
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

void	insert_info_tolist(int subnum, t_staccontent *nowaddr, int n, int last, t_staccontent *f_addr)
{
	if (n == last)
		nowaddr->next = f_addr;
	else
		nowaddr->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	nowaddr->next->prev = nowaddr;
	nowaddr->num = subnum;
	nowaddr->wedge = false;
}

t_staccontent **insertelem_tostack(int counter, char **numstr)
{
	t_staccontent	**a;
	t_staccontent	*node;
	int				i;

	a = list_initialization();
	if (a == NULL)
		return (NULL);
	node = *a;
	i = 1;
	while(i != counter)
	{
		insert_info_tolist(ft_atoi(numstr[i]), node, i, counter - 1, *a);
		node = node->next;
		i++;
	}
	return a;
}

t_staccontent	**push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;

	a = insertelem_tostack(arg_num, num_ch);
	b = list_initialization();
	free(*b);
	(*b) = NULL;

	quicksort_main(a,b);
	return a;
}

int	main(int argc, char **argv)
{
	int i = 0;
	t_staccontent *node;
	t_staccontent **a;

	a = push_swap(argc, argv);
	node = (*a);
	//printf("|nodenumis  is %d|\n",node->num);
	//printf("\n6------\n");
	//printf("listlen is %zu\n", grasp_listlen(a));
	//printf("mediam is %d\n", mediam(a));
	while(i != 12)
	{
		printf("|%d is %d and addr is %p and node true or not is %d|\n",i, node->num, node, node->wedge);
		node = node->next;
		i = i + 1;
	}
}
