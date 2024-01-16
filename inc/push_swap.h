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
int		ft_sorted(t_swap *swap);
int		ft_get_max_num(t_swap *swap);
int		ft_get_min_num(t_swap *swap);

//		SORT
void	ft_sort_stack(t_swap *swap);

//		OPERATIONS
void	ft_swap(t_swap *swap, char	*arg);
void	ft_push(t_swap	*swap, char *arg);
void	ft_rotate(t_swap *swap, char *arg);

//		ERROR
void	ft_errors(t_swap *swap, int n);

//		FREES
void	ft_free_all(t_swap *swap, int n);

#endif