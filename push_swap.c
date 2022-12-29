/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:40 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 20:04:51 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_node(t_staccontent **a)
// {
// 	t_staccontent *node;
// 	t_staccontent *first;
// 	node = *a;
// 	first = *a;
// 	int i = 0;

// 	while (node -> next != *a)
// 	{
// 		printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
// 		i++;
// 		node = node->next;
// 	}
// 	printf("%d is %d and wedge is %d (0 is false)\n", i, node->num, node->wedge);
// 	*a = first;
// }

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

bool argument_checker(int arg_num, char **argument)
{
	int		char_num;
	int		arg_counter;
	char	subject;

	char_num = 0;
	arg_counter = 1;
	while (arg_counter != arg_num)
	{
		while(argument[arg_counter][char_num] != '\0')
		{
			subject = argument[arg_counter][char_num];
			if (char_num == 0 && ('0' > subject || '9' < subject) && subject != '-')
				return (false);
			else if (char_num != 0 && ('0' > subject || '9' < subject))
				return (false);
			char_num++;
		}
		arg_counter++;
		char_num = 0;
	}
	return (true);
}

t_staccontent	**push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;
	bool			argment_letimacy;
	bool			dupli_check;

	if (arg_num == 1)
		return (NULL);
	argment_letimacy = argument_checker(arg_num, num_ch);
	if (argment_letimacy == false)
		return (NULL);
	a = insertelem_tostack(arg_num, num_ch);
	dupli_check = duplication_checker(a);
	if (dupli_check == false)
		return (false);
	if ((*a)->next == (*a))
		return (a);
	if (sortcheck(a) == true)
		return (a);
	//print_node(a);
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	quicksort_main(a, b);
	return (a);
}

int	main(int argc, char **argv)
{
	t_staccontent	*node;
	t_staccontent	**a;
	int				i;

	i = 0;
	a = push_swap(argc, argv);
	if (a == NULL && argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	else if (a == NULL && argc == 1)
	{
		//printf("\n");
		return (1);
	}
	node = (*a);
	while (node->next != *a)
	{
		//printf("|%d is %d && wedge is %d|\n" ,i, node->num, node->wedge);
		node = node->next;
		i++;
	}
	//printf("|%d is %d && wedge is %d|\n" ,i, node->num, node->wedge);
	return (1);
}
