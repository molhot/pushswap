/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/17 00:09:46 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization(int argnum)
{
	t_staccontent	**subject_list;

	subject_list = (t_staccontent **)malloc(sizeof(t_staccontent *) * argnum);
	if (subject_list == NULL)
		return (NULL);
	*subject_list = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	if (*subject_list == NULL)
	{
		free(*subject_list);
		free(subject_list);
		return (NULL);
	}
	return (subject_list);
}

t_staccontent	**insert_list(t_staccontent **subject, int num, char **num_chr)
{
	int				i;
	t_staccontent	*lists;
	t_staccontent	*house_list;

	i = 0;
	lists = *subject;
	house_list = *subject;
	while (i != num - 2)
	{
		if (i != 0)
			(lists)->prev = house_list;
		(lists)->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
		house_list = lists;
		(lists)->num = ft_atoi(num_chr[i + 1]);
		i++;
		lists = lists->next;
	}
	(lists)->prev = house_list;
	(lists)->num = ft_atoi(num_chr[i + 1]);
	(lists)->next = *subject;
	(*subject)->prev = lists;
	return (subject);
}

void	push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;
	t_staccontent	*tmp_af;
	lisinfo			*lislist;

	a = list_initialization(arg_num);
	b = list_initialization(arg_num);
	printf("\n%s\n", "-----------------------");
	a = insert_list(a, arg_num, num_ch);
	printf("\n%s\n", "-----------------------");
	lislist = find_LIS(a);
	printf("\n%s\n", "-----------------------");
	int j = 0;
	while (*a != lislist->LISf_addr && j != 5)
	{
		push_swap_pa(a, b);
		printf("addr is %p\n", *a);
		j = j + 1;
	}



	

	// for test//
	printf("\n%s\n", "^^teststarst^^");
	t_staccontent	*listesta;
	t_staccontent	*listestb;

	listesta = *a;
	listestb = *b;
	int i = 0;
	printf("\n%s\n", "-----------------------");
	while(i != 10)
	{
		printf("a's int is %d\n", listesta->num);
		printf("b's int is %d\n", listestb->num);
		listesta = listesta->next;
		listestb = listestb->next;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
