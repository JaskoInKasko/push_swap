#include "../inc/push_swap.h"

void    ft_errors(t_swap *swap, int n)
{
    if(n == 1)
        ft_putstr_fd("Error\n", STDERR_FILENO);
    if(n == 1 || n == 2)
        exit(EXIT_FAILURE);
}