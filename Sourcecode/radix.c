/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:25:20 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/25 13:25:23 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_radix_sort(t_swap *swap)
{
	int	i;
	int	j;
	int	size;
	int	ary_div_size;

	i = -1;
	size = swap->size_a;
	ary_div_size = 1;
	while (size > 1 && ary_div_size++)
		size /= 2;
	size = swap->size_a;
	while (++i < ary_div_size)
	{
		j = 0;
		while (j++ < size)
		{
			if (((swap->stack_a[0] >> i) & 1) == 0)
				ft_push(swap, "pb");
			else
				ft_rotate(swap, "ra");
		}
		while (swap->size_b > 0)
			ft_push(swap, "pa");
	}
}
