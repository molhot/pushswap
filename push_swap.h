/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:18:22 by satushi           #+#    #+#             */
/*   Updated: 2022/11/25 22:38:30 by satushi          ###   ########.fr       */
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

//quicksortfunc
void	quicksort_firststep(t_staccontent **a, t_staccontent **b);
void	quicksort_main(t_staccontent **a, t_staccontent **b);

//reverserotation
void	push_swap_rra(t_staccontent **a);
void	push_swap_rrb(t_staccontent **b);
void	push_swap_rrr(t_staccontent **a, t_staccontent **b);

//rotation
void	push_swap_ra(t_staccontent **a);
void	push_swap_rb(t_staccontent **b);
void	push_swap_rr(t_staccontent **a, t_staccontent **b);

//swap
void	push_swap_sa(t_staccontent **a);
void	push_swap_sb(t_staccontent **b);
void	push_swap_ss(t_staccontent **a,t_staccontent **b);

//push
void	pa(t_staccontent **a, t_staccontent **b);
void	pb(t_staccontent **a, t_staccontent **b);

//sort min num ex 3 or 2
void    patt_twonum(t_staccontent **list);
void	patt_threenum(t_staccontent **list);

#endif