#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../included_functions/libft/libft.h"

typedef struct s_swap
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_swap;

//		UTILS
int		ft_atol(const char *nptr, t_swap *swap);
void	ft_check_for_dups(t_swap *swap, char dup, int i);

//		SORT
void    ft_sa(t_swap *swap);
void    ft_sb(t_swap *swap);
void    ft_ss(t_swap *swap);

//		ERROR
void	ft_errors(t_swap *swap, int n);

//		FREES
void	ft_free_all(t_swap *swap, int n);

#endif