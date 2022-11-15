/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:31:44 by satushi           #+#    #+#             */
/*   Updated: 2022/11/15 22:17:45 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_LIS(t_staccontent **subjectlist)
{
    t_staccontent   *sentinel;
    size_t			LIS_len;
    size_t			LIS_len_tmp;

    LIS_len = 1;
	LIS_len_tmp = 1;
	sentinel = (*subjectlist)->next;
	while (sentinel != *subjectlist)
	{
		if(sentinel->prev->num < sentinel->num)
			LIS_len_tmp = LIS_len_tmp + 1;
		if(LIS_len_tmp > LIS_len && sentinel->prev->num > sentinel->num)
		{
			LIS_len = LIS_len_tmp;
			LIS_len_tmp = 1;
		}
		printf("tmp LISlen is %zu\n", LIS_len_tmp);
		sentinel = sentinel->next;
	}
	printf("LIS length is %zu\n", LIS_len);
}