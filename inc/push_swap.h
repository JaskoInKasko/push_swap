#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../included_functions/libft/libft.h"

typedef struct s_swap
{
	int *nbs;
	int	nb;
}	t_swap;

//		ERROR
void	ft_errors(t_swap *swap, int n);

#endif