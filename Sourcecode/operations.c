#include "../inc/push_swap.h"

void	ft_swap(t_swap *swap, char	*arg)
{
	int tmp;

	if (ft_strcmp(arg, "sa") == 0 || ft_strcmp(arg, "ss") == 0)
	{
		tmp = swap->stack_a[0];
		if (swap->size_a >= 2)
		{
			swap->stack_a[0] = swap->stack_a[1];
			swap->stack_a[1] = tmp;
			ft_putstr(arg);
		}
	}
	if (ft_strcmp(arg, "sb") == 0 || ft_strcmp(arg, "ss") == 0)
	{
		tmp = swap->stack_b[0];
		if (swap->size_b >= 2)
		{
			swap->stack_b[0] = swap->stack_b[1];
			swap->stack_b[1] = tmp;
		}
	}
}

void	ft_push(t_swap	*swap, char *arg)
{
	int	tmp;

	if(swap->size_b >= 0)
	{
		if(ft_strcmp(arg, "pa") == 0)
		{
			tmp = swap->stack_a[0];
			swap->stack_b[0] = tmp;
			ft_memmove(swap->stack_a - 1, swap->stack_a, swap->size_a);
			int	i = -1;
			while(swap->stack_a[++i] != '\0')
				ft_printf("%d\n", swap->stack_a);
			swap->size_a--;
		}
		if(ft_strcmp(arg, "pb") == 0)
		{

		}
	}
}

void	ft_rotate(t_swap *swap, char *arg)
{
	(void)swap;
	(void)arg;
}
