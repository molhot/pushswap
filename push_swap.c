/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/15 20:37:23 by satushi          ###   ########.fr       */
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

	a = list_initialization(arg_num);
	b = list_initialization(arg_num);
	a = insert_list(a, arg_num, num_ch);
	b = insert_list(b, arg_num, num_ch);

	// for test//
	printf("\n%s\n", "^^teststarst^^");
	int i = 0;
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
	i = 0;
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
	i = 0;
	push_swap_pa(a, b);
	t_staccontent *test3;
	test3 = *a;
	while (i <= 5)
	{
		printf("as content num is -> %d\n", test3->num);
		printf("addr is -> %p\n", test3);
		i = i + 1;
		test3 = test3->next;
	}
	printf("\n%s\n", "--------------------");
	t_staccontent *test4;
	test4 = *b;
	i = 0;
	while (i <= 7)
	{
		printf("bs content num is -> %d\n", test4->num);
		printf("addr is -> %p\n", test4);
		i = i + 1;
		test4 = test4->next;
	}
	printf("\n%s\n", "--------------------");
	i = 0;
	push_swap_ra(a);
	t_staccontent *test5;
	test5 = *a;
	while (i <= 5)
	{
		printf("as content num is -> %d\n", test5->num);
		printf("addr is -> %p\n", test5);
		i = i + 1;
		test5 = test5->next;
	}
	printf("\n%s\n", "--------------------");
	i = 0;
	push_swap_rra(a);
	t_staccontent *test6;
	test6 = *a;
	while (i <= 5)
	{
		printf("as content num is -> %d\n", test6->num);
		printf("addr is -> %p\n", test6);
		i = i + 1;
		test6 = test6->next;
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
