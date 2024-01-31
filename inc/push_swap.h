/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:27:10 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/25 13:27:13 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../included_functions/libft/libft.h"

typedef struct s_swap
{
	char	**args;
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		min_a;
	int		max_a;
	int		distance_max_ra;
	int		distance_max_rra;
	int		distance_min_ra;
	int		distance_min_rra;
}	t_swap;

//		UTILS
int		ft_atol(const char *nptr, t_swap *swap);
void	ft_check_for_dups(t_swap *swap, int dup, int i);
int		ft_sorted(t_swap *swap);
void	ft_get_distance_ra(t_swap *swap);
void	ft_get_distance_rra(t_swap *swap);

//		UTILS 2
void	ft_get_min_max_nb(t_swap *swap);
void	ft_create_index(t_swap *swap);

//		SORT
void	ft_sort_stack(t_swap *swap);

//		OPERATIONS
void	ft_swap(t_swap *swap, char	*arg);
void	ft_push(t_swap	*swap, char *arg);
void	ft_rotate(t_swap *swap, char *arg);
void	ft_rev_rotate(t_swap *swap, char *arg);

//		RADIX
void	ft_radix_sort(t_swap *swap);

//		ERROR
void	ft_errors(t_swap *swap);

//		FREES
void	ft_free_all(t_swap *swap);

#endif
