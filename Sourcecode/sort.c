#include "../inc/push_swap.h"

void	ft_sort_size_four2(t_swap *swap, int max,int min)
{
	while(ft_sorted(swap) != 0)
	{
		/*if (swap->stack_a[0] > swap->stack_a[3] && swap->stack_a[1] > swap->stack_a[2]
			&& swap->stack_a[2] > swap->stack_a[3])
			ft_pb(swap);*/
		if (swap->stack_a[0] > swap->stack_a[1] && swap->stack_a[1] < swap->stack_a[2])
			ft_swap(swap, "sa");
		else if (swap->stack_a[0] < swap->stack_a[3] && swap->stack_a[3] != max)
			ft_rotate(swap, "rra");
		else if (swap->stack_a[1] > swap->stack_a[2] && swap->stack_a[2] == min)
			ft_rotate(swap, "ra");
		else
			ft_rotate(swap, "rra");
	}
}

void	ft_sort_size_three(t_swap *swap)
{
	while(ft_sorted(swap) != 0)
	{
		if (swap->stack_a[0] > swap->stack_a[1] && swap->stack_a[2] < swap->stack_a[1])
			ft_swap(swap, "sa");
		if (swap->stack_a[0] > swap->stack_a[2] && swap->stack_a[1] < swap->stack_a[2])
			ft_rotate(swap, "ra");
		ft_rotate(swap, "rra");
	}
	/*if (swap->stack_a[0] < swap->stack_a[2]
		&& swap->stack_a[0] > swap->stack_a[1])
		ft_sa(swap);
	else if (swap->stack_a[0] < swap->stack_a[2]
		&& swap->stack_a[0] < swap->stack_a[1])
	{
		ft_sa(swap);
		ft_ra(swap);
	}
	else if (swap->stack_a[0] > swap->stack_a[1]
		&& swap->stack_a[1] > swap->stack_a[2])
	{
		ft_sa(swap);
		ft_rra(swap);
	}
	else if (swap->stack_a[0] > swap->stack_a[1]
		&& swap->stack_a[1] < swap->stack_a[2])
		ft_ra(swap);
	else
		ft_rra(swap);*/
}

void	ft_sort_size_four(t_swap *swap)
{
	int max;
	int	min;

	max = ft_get_max_num(swap);
	min = ft_get_min_num(swap);
	if(swap->stack_a[0] == max || swap->stack_a[0] == min)
	{
		if(!(swap->stack_a[1] < swap->stack_a[2]
			&& swap->stack_a[2] < swap->stack_a[3]))
			ft_push(swap, "pb");
		ft_sort_size_three(swap);
		ft_push(swap, "pa");
		if (swap->stack_a[0] == max)
			ft_rotate(swap, "ra");
	}
	ft_sort_size_four2(swap, max, min);
}

void	ft_sort_stack(t_swap *swap)
{
	if(swap->size_a == 1)
		ft_free_all(swap, 2);
	if(swap->size_a == 2)
	{
		if(swap->stack_a[0] > swap->stack_a[1])
			ft_swap(swap, "sa");
	}
	if(swap->size_a == 3)
		ft_sort_size_three(swap);
	if(swap->size_a == 4)
		ft_sort_size_four(swap);
	ft_push(swap, "pb");
}