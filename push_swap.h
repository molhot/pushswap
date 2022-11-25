/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:22 by satushi           #+#    #+#             */
/*   Updated: 2022/11/23 23:19:07 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct stac
{
	int		num;
	bool	wedge;
	struct stac	*prev;
	struct stac	*next;
}t_staccontent;

typedef struct LISinfo
{
	size_t	LISlen;
	struct stac	*LISf_addr;
	struct stac	*LISe_addr;
}lisinfo;

int		ft_atoi(const char *str);
size_t	grasp_listlen(t_staccontent **sublist);
int		mediam(t_staccontent **sublist);
//void	pushfunc(t_staccontent **pushed, t_staccontent **push);
void	pa(t_staccontent **a, t_staccontent **b);
void	pb(t_staccontent **a, t_staccontent **b);
void	quicksort_firststep(t_staccontent **a, t_staccontent **b);
void	quicksort_main(t_staccontent **a, t_staccontent **b);

#endif