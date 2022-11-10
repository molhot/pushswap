#include "push_swap.h"

stac_content	**list_initialization()
{
	stac_content **subject_list;

	subject_list = (stac_content **)malloc(sizeof(stac_content*) * 1);
	*subject_list = (stac_content *)malloc(sizeof(stac_content) * 1);
	return (subject_list);
}

stac_content	**insert_list(stac_content **a, size_t num, char **num_chr)
{
	size_t 			i;
	stac_content	*lists;
	stac_content	*house_list;

	i = 1;
	lists = *a;
	while(i != num)
	{
		if(i != 0)
			(lists)->prev = house_list;
		if(i != num - 1)
		{
			house_list = lists;
			(lists)->next = (stac_content *)malloc(sizeof(stac_content) * 1);
		}
		if(i == num - 1)
			lists->next = *a;
		(lists)->num = ft_atoi(num_chr[i]);
		i++;
		lists = lists->next;
	}
	(*a)->prev = lists->next;

	return a;
}

void	push_swap(size_t arg_num, char **num_ch)
{
	stac_content	**a;
	stac_content	**b;

	a = list_initialization();
	b = list_initialization();
	a = insert_list(a, arg_num, num_ch);
	
	int i = 0;
	stac_content *t;
	t = *a;
	while(i != 5)
	{
		printf("%d\n", t->num);
		printf("%p\n", t);
		t = t->next;
		i = i + 1;
	}
	i = 0;
	t = NULL;
	push_swap_a(a);
	t = *a;
	while(i != 5)
	{
		printf("%d\n", t->num);
		printf("%p\n", t);
		t = t->next;
		i = i + 1;
	}
}

int main(size_t argc, char **argv)
{
	size_t	i;

	i = 0;
	push_swap(argc, argv);
}