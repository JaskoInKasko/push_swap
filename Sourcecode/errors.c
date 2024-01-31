/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:39 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/25 13:26:42 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_errors(t_swap *swap)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_free_all(swap);
}
