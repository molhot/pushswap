/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:51:50 by satushi           #+#    #+#             */
/*   Updated: 2022/11/18 22:06:44 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	quicksort(int *subjectarrange, int left, int right)
{
	int pivotnum;
	int	fromf;
	int	frome;
	int tmp;

	if(left >= right)
		return ;
	pivotnum = subjectarrange[left + 1];
	fromf = left;
	frome = right;
	while(1)
	{
		while(subjectarrange[fromf] < pivotnum)
			fromf++;
		while(subjectarrange[frome] > pivotnum)
			frome--;
		if (fromf >= frome)
			break ;
		tmp = subjectarrange[fromf];
		subjectarrange[fromf] = subjectarrange[frome];
		subjectarrange[frome] = tmp;
		fromf++;
		frome--;
	}
	printf("\n%s\n", "check");
	quicksort(subjectarrange, left, fromf - 1);
	printf("\n%s\n", "check2");
	quicksort(subjectarrange, frome + 1, right);
}

int main()
{
	int subjectarrange[5] = {1, 8, 10, 6, 2};
	printf("%lu\n",sizeof(subjectarrange) / 4);
	int j = 0;
	quicksort(subjectarrange, 0, 4);
	while (j != 5)
	{
		printf("%d\n", subjectarrange[j]);
		j = j + 1;
	}
	return (0);
}