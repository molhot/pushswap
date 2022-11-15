/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/14 22:01:23 by satushi          ###   ########.fr       */
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

	a = list_initialization(arg_num);
	b = list_initialization(arg_num);
	a = insert_list(a, arg_num, num_ch);
	b = insert_list(b, arg_num, num_ch);

	// for test//
	int i = 1;
	t_staccontent *test;
	test = *a;
	while (i <= 5)
	{
		printf("content num is -> %d\n", test->num);
		printf("addr is -> %p\n", test);
		i = i + 1;
		test = test->next;
	}
	printf("\n%s\n", "--------------------");
	i = 1;
	push_swap_sa(a);
	t_staccontent *test2;
	test2 = *a;
	while (i <= 5)
	{
		printf("content num is -> %d\n", test2->num);
		printf("addr is -> %p\n", test2);
		i = i + 1;
		test2 = test2->next;
	}
	printf("\n%s\n", "--------------------");
	i = 1;
	push_swap_pa(a, b);
	t_staccontent *test3;
	test3 = *a;
	//for test zone
	while (i <= 5)
	{
		printf("content num is -> %d\n", test3->num);
		printf("addr is -> %p\n", test3);
		i = i + 1;
		test3 = test3->next;
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
