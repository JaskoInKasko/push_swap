#include "../inc/push_swap.h"

void    ft_errors(t_swap *swap, int n)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    if(n == 1)
        exit(EXIT_FAILURE);
    ft_free_all(swap);
}