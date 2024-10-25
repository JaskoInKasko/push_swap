/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:25:32 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/25 13:25:36 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_push_expanded(t_swap *swap, char *arg);

void	ft_swap(t_swap *swap, char	*arg)
{
	int	tmp;

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
			if (ft_strcmp(arg, "ss") != 0)
				ft_putendl_fd(arg, STDOUT_FILENO);
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
			ft_memmove(swap->stack_a + 1, swap->stack_a,
				sizeof(int) * swap->size_a);
			swap->stack_a[0] = tmp;
			ft_memmove(swap->stack_b, swap->stack_b + 1,
				sizeof(int) * swap->size_b);
			swap->size_b--;
			swap->size_a++;
			ft_putendl_fd(arg, STDOUT_FILENO);
		}
	}
	ft_push_expanded(swap, arg);
}

void	ft_push_expanded(t_swap *swap, char *arg)
{
	int	tmp;

	if (ft_strcmp(arg, "pb") == 0)
	{
		tmp = swap->stack_a[0];
		ft_memmove(swap->stack_b + 1, swap->stack_b,
			sizeof(int) * swap->size_b);
		swap->stack_b[0] = tmp;
		ft_memmove(swap->stack_a, swap->stack_a + 1,
			sizeof(int) * swap->size_a);
		swap->size_a--;
		swap->size_b++;
		ft_putendl_fd(arg, STDOUT_FILENO);
	}
}

void	ft_rotate(t_swap *swap, char *arg)
{
	int	tmp;

	if ((ft_strcmp(arg, "ra") == 0 && swap->size_a > 0)
		|| (ft_strcmp(arg, "rr") == 0 && swap->size_a > 0 && swap->size_b > 0))
	{
		tmp = swap->stack_a[0];
		ft_memmove(swap->stack_a, swap->stack_a + 1,
			sizeof(int) * (swap->size_a - 1));
		swap->stack_a[swap->size_a - 1] = tmp;
		ft_putendl_fd(arg, STDOUT_FILENO);
	}
	if ((ft_strcmp(arg, "rb") == 0 && swap->size_b > 0)
		|| (ft_strcmp(arg, "rr") == 0 && swap->size_b > 0 && swap->size_a > 0))
	{
		tmp = swap->stack_b[0];
		ft_memmove(swap->stack_b, swap->stack_b + 1,
			sizeof(int) * (swap->size_b - 1));
		swap->stack_b[swap->size_b - 1] = tmp;
		if (ft_strcmp(arg, "rr") != 0)
			ft_putendl_fd(arg, STDOUT_FILENO);
	}
}

void	ft_rev_rotate(t_swap *swap, char *arg)
{
	int	tmp;

	if ((ft_strcmp(arg, "rra") == 0 && swap->size_a > 0)
		|| (ft_strcmp(arg, "rrr") == 0 && swap->size_a > 0 && swap->size_b > 0))
	{
		tmp = swap->stack_a[swap->size_a - 1];
		ft_memmove(swap->stack_a + 1, swap->stack_a,
			sizeof(int) * (swap->size_a - 1));
		swap->stack_a[0] = tmp;
		ft_putendl_fd(arg, STDOUT_FILENO);
	}
	if ((ft_strcmp(arg, "rrb") == 0 && swap->size_b > 0)
		|| (ft_strcmp(arg, "rrr") == 0 && swap->size_b > 0 && swap->size_a > 0))
	{
		tmp = swap->stack_b[swap->size_b - 1];
		ft_memmove(swap->stack_b, swap->stack_b + 1,
			sizeof(int) * (swap->size_b - 1));
		swap->stack_b[0] = tmp;
		if (ft_strcmp(arg, "rrr") != 0)
			ft_putendl_fd(arg, STDOUT_FILENO);
	}
}
