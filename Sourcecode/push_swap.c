/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:27 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/25 13:26:30 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_swap_init(t_swap *swap)
{
	swap->args = NULL;
	swap->stack_b = NULL;
	swap->stack_a = NULL;
	swap->size_a = 0;
	swap->size_b = 0;
	swap->min_a = 0;
	swap->max_a = 0;
}

void	ft_get_args(t_swap *swap, char *argv[])
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	if (!tmp)
		ft_errors(swap);
	while (argv[++i] != NULL)
	{
		tmp = ft_strjoin_free(tmp, argv[i]);
		if (!tmp)
			ft_errors(swap);
		tmp = ft_strjoin_free(tmp, " ");
		if (!tmp)
			ft_errors(swap);
	}
	swap->args = ft_split(tmp, ' ');
	if (!swap->args)
	{
		free(tmp);
		ft_errors(swap);
	}
	free(tmp);
}

void	ft_check_args(t_swap *swap, char *argv[])
{
	int	i;
	int	c;

	c = 0;
	ft_get_args(swap, argv);
	while (swap->args[c] != NULL)
	{
		i = 0;
		while (swap->args[c][i] != '\0')
		{
			if (!((swap->args[c][i] >= '0' && swap->args[c][i] <= '9')
				|| (swap->args[c][i] == '+' || swap->args[c][i] == '-')))
				ft_errors(swap);
			if (swap->args[c][i + 1] == '+' || swap->args[c][i + 1] == '-')
				ft_errors(swap);
			if ((swap->args[c][i] == '+' || swap->args[c][i] == '-') &&
				swap->args[c][i + 1] == '\0')
				ft_errors(swap);
			i++;
		}
		c++;
	}
}

void	ft_get_number(t_swap *swap)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (swap->args[++i] != NULL)
		len++;
	swap->stack_a = (int *)malloc(sizeof(int) * (len + 1));
	swap->stack_b = (int *)malloc(sizeof(int) * (len + 1));
	if (!swap->stack_a || !swap->stack_b)
		ft_errors(swap);
	swap->stack_a[len] = '\0';
	swap->stack_b[len] = '\0';
	i = -1;
	while (swap->args[++i] != NULL)
	{
		swap->stack_a[i] = ft_atol(swap->args[i], swap);
		swap->size_a++;
	}
	i = -1;
	while (++i < swap->size_a)
		ft_check_for_dups(swap, swap->stack_a[i], i);
	if (ft_sorted(swap) == 0)
		ft_free_all(swap);
}

int	main(int argc, char *argv[])
{
	t_swap	swap;

	if (argc != 1)
	{
		ft_swap_init(&swap);
		ft_check_args(&swap, argv);
		ft_get_number(&swap);
		ft_sort_stack(&swap);
		ft_free_all(&swap);
	}
	return (0);
}
