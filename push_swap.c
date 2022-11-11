/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 22:39:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization(int argnum)
{
	t_staccontent	**subject_list;
	int 			i;

	subject_list = (t_staccontent **)malloc(sizeof(t_staccontent *) * 1);
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
		house_list = lists;
		(lists)->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
		(lists)->num = ft_atoi(num_chr[i]);
		i++;
		lists = lists->next;
	}
	(*subject)->prev = lists->next;
	return (subject);
}

void	push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;

	a = list_initialization(arg_num);
	b = list_initialization(arg_num);
	a = insert_list(a, arg_num, num_ch);

	// for test//
	int i = 0;
	t_staccontent *test;
	test = *a;
	while (i <= 5)
	{
		printf("content num is -> %zu\n", test->num);
		i = i + 1;
		test = test + 1;
	}
	printf("\n%s\n", "here is between");
	i = 0;
	push_swap_ra(a);
	while (i <= 5)
	{
		printf("content num is -> %zu\n", test->num);
		i = i + 1;
		test = test + 1;
	}
	//for test zone
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
