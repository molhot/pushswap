/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_mediam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:05:23 by satushi           #+#    #+#             */
/*   Updated: 2022/11/17 22:51:11 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	grasp_mediamnum_oflist(t_staccontent **subject)
{
	size_t			sum;
	t_staccontent	*sentinel;
	size_t			listlen;

	sentinel = (*subject)->next;
	sum = (*subject)->num;
	listlen = grasp_listlen(subject);
	while(sentinel != *subject)
	{
		sum = sum + (size_t)sentinel->num;
		sentinel = sentinel ->next;
	}
	return (sum / listlen);
}