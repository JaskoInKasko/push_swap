#include "../inc/push_swap.h"

void    ft_errors(t_swap *swap, int n)
{
    if(n == 1)
        ft_putstr_fd("Error\n", STDERR_FILENO);
    if(n == 2)
        ft_free_all(swap, 1);
    if(n == 3 || n == 4)
        ft_free_all(swap, 2);
    if(n == 1)
        exit(EXIT_FAILURE);
}