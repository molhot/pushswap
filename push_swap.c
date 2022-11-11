/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 21:37:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization(void)
{
	t_staccontent	**subject_list;

	subject_list = (t_staccontent **)malloc(sizeof(stac_content *) * 1);
	*subject_list = (t_staccontent *)malloc(sizeof(stac_content) * 1);
	return (subject_list);
}

t_staccontent	**insert_list(t_staccontent **a, size_t num, char **num_chr)
{
	size_t			i;
	t_staccontent	*lists;
	t_staccontent	*house_list;

	i = 1;
	lists = *a;
	while (i != num)
	{
		if (i != 0)
			(lists)->prev = house_list;
		if (i != num - 1)
		{
			house_list = lists;
			(lists)->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
		}
		if (i == num - 1)
			lists->next = *a;
		(lists)->num = ft_atoi(num_chr[i]);
		i++;
		lists = lists->next;
	}
	(*a)->prev = lists->next;
	return (a);
}

void	push_swap(size_t arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;

	a = list_initialization();
	b = list_initialization();
	a = insert_list(a, arg_num, num_ch);
	push_swap_ra(a);
}

int	main(int argc, char **argv)
{
	size_t	i;

	i = 0;
	push_swap(argc, argv);
}
