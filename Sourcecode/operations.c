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
			ft_putendl_fd(arg, STDOUT_FILENO);
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

	if (swap->size_b > 0)
	{
		if (ft_strcmp(arg, "pa") == 0)
		{
			tmp = swap->stack_b[0];
			swap->size_a++;
			ft_memmove(swap->stack_a + 1, swap->stack_a, sizeof(int) * swap->size_a);
			swap->stack_a[0] = tmp;
			ft_memmove(swap->stack_b, swap->stack_b + 1, sizeof(int) * swap->size_b);
			swap->size_b--;
		}
	}
	if (ft_strcmp(arg, "pb") == 0)
	{
		tmp = swap->stack_a[0];
		swap->size_b++;
		ft_memmove(swap->stack_b + 1, swap->stack_b, sizeof(int) * swap->size_b);
		swap->stack_b[0] = tmp;
		ft_memmove(swap->stack_a, swap->stack_a + 1, sizeof(int) * swap->size_a);
		swap->size_a--;
	}
}

void	ft_rotate(t_swap *swap, char *arg)
{
	(void)swap;
	(void)arg;
}
