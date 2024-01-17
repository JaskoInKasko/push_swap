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
	ft_push(swap, "pa");
	if (swap->stack_a[0] > swap->stack_a[3])
		ft_rotate(swap, "ra");
}

void	ft_sort_size_five(t_swap *swap)
{
		ft_push(swap, "pb");
		ft_push(swap, "pb");
		ft_sort_size_three(swap);
		ft_push(swap, "pa");
		if(swap->stack_a[0] > swap->stack_a[3])
			ft_rotate(swap, "ra");
		if(swap->stack_a[0] > swap->stack_a[1])
			ft_swap(swap, "sa");
		ft_push(swap, "pa");
		if(swap->stack_a[0] > swap->stack_a[4])
			ft_rotate(swap, "ra");
		if(swap->stack_a[0] > swap->stack_a[1])
			ft_swap(swap, "sa");
}

void	ft_sort_stack(t_swap *swap)
{
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
	int	i = -1;
	while (swap->stack_a[++i] != '\0')
		ft_printf("stack a:%d\n", swap->stack_a[i]);
}