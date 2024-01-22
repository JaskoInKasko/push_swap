#include "../inc/push_swap.h"

void	ft_sort_size_three(t_swap *swap)
{
	while(ft_sorted(swap) != 0)
	{
		if (swap->stack_a[0] > swap->stack_a[1] && swap->stack_a[1] < swap->stack_a[2]
			&& swap->stack_a[2] < swap->stack_a[0])
			ft_rotate(swap, "ra");
		else if (swap->stack_a[0] > swap->stack_a[1]
			&& (swap->stack_a[2] > swap->stack_a[1] || swap->stack_a[2] < swap->stack_a[1]))
			ft_swap(swap, "sa");
		else
			ft_rev_rotate(swap, "rra");
	}
}

void	ft_sort_size_four(t_swap *swap)
{
	ft_push(swap, "pb");
	ft_sort_size_three(swap);
	if(swap->stack_b[0] < swap->stack_a[2] && swap->stack_b[0] > swap->stack_a[1]
		&& swap->stack_b[0] < swap->stack_a[2])
		ft_rev_rotate(swap, "rra");
	ft_push(swap, "pa");
	if (swap->stack_a[0] > swap->stack_a[3])
		ft_rotate(swap, "ra");
	if (swap->stack_a[0] > swap->stack_a[3] && swap->stack_a[0] > swap->stack_a[2])
		ft_rotate(swap, "ra");
	if(swap->stack_a[0] > swap->stack_a[1])
		ft_swap(swap, "sa");
}

void	ft_decide_for_ra_or_rra(t_swap *swap)
{
	if (swap->distance_min_ra >= swap->distance_min_rra)
	{
		while(swap->stack_a[0] != swap->min_a)
			ft_rev_rotate(swap, "rra");
	}
	else
	{
		while(swap->stack_a[0] != swap->min_a)
			ft_rotate(swap, "ra");
	}
	ft_push(swap, "pb");
	ft_get_distance_ra(swap);
	ft_get_distance_rra(swap);
	if (swap->distance_max_ra >= swap->distance_max_rra)
	{
		while(swap->stack_a[0] != swap->max_a)
			ft_rev_rotate(swap, "rra");
	}
	else
	{
		while(swap->stack_a[0] != swap->max_a)
			ft_rotate(swap, "ra");
	}
	ft_push(swap, "pb");
}

void	ft_sort_size_five(t_swap *swap)
{
	ft_get_min_max_nb(swap);	
	ft_get_distance_ra(swap);
	ft_get_distance_rra(swap);
	ft_decide_for_ra_or_rra(swap);
	ft_sort_size_three(swap);
	if(swap->stack_b[0] < swap->stack_b[1])
	{
		ft_push(swap, "pa");
		ft_push(swap, "pa");
		ft_rotate(swap, "ra");
	}
	else
	{
		ft_push(swap, "pa");
		ft_rotate(swap, "ra");
		ft_push(swap, "pa");
	}
}

void	ft_sort_stack(t_swap *swap)
{
	ft_create_index(swap);
	if (swap->size_a == 1)
		ft_free_all(swap);
	if (swap->size_a == 2)
	{
		if(swap->stack_a[0] > swap->stack_a[1])
			ft_swap(swap, "sa");
	}
	if (swap->size_a == 3)
		ft_sort_size_three(swap);
	if (swap->size_a == 4)
		ft_sort_size_four(swap);
	if (swap->size_a == 5)
		ft_sort_size_five(swap);
	if(swap->size_a > 5)
		ft_radix_sort(swap);
}