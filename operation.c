#include "push_swap.h"

void	push_swap_ra(stac_content **a)
{
	*a = (*a)->next;
}

void	push_swap_rb(stac_content **b)
{
	*b = (*b)->next;
}

void	push_swap_rr(stac_content **a, stac_content **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}