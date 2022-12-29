#include "../pushswap.h"

int sorted_count(t_staccontent **list);
{
	t_staccontent	*list_f;
	t_staccontent	*node;
	int		tentative_most_minimumnum;
	int		counter;
	int		tmp_buff;

	list_f = *list;
	node = *list;
	tentative_most_minimumnum = node->num;
	while (node->before->wedge != true)
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
		if (node->num < tmp_buff)
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

// 10 20 21 34 23 1 2 3 4 5
// ならば
// 1 2 3 5 4 / 1 2 3 4 5
// としたい
// 2 3 4 1 5
// だと最悪だった　解決済み

int main()
{
	return (0);
}
