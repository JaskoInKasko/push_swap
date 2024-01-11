#include "../inc/push_swap.h"

void    ft_sa(t_swap *swap)
{
	int	tmp;

	tmp = swap->stack_a[0];
	if (swap->size_a >= 2)
	{
		swap->stack_a[0] = swap->stack_a[1];
		swap->stack_a[1] = tmp;
	}
}

void    ft_sb(t_swap *swap)
{
	int	tmp;

	tmp = swap->stack_b[0];
	if (swap->size_b >= 2)
	{
		swap->stack_b[0] = swap->stack_b[1];
		swap->stack_b[1] = tmp;
	}
}

void    ft_ss(t_swap *swap)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = swap->stack_a[0];
	tmp_b = swap->stack_b[0];
	if (swap->size_a >= 2 && swap->size_b >= 2)
	{
		swap->stack_a[0] = swap->stack_a[1];
		swap->stack_b[0] = swap->stack_b[1];
		swap->stack_a[1] = tmp_a;
		swap->stack_b[1] = tmp_b;
	}
}

/*void    ft_pa(t_swap *swap)
{
	int	tmp;

	if(swap->size_b >= 1)
	{
		
	}
}*/