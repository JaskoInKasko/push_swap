#include "../inc/push_swap.h"

void ft_free_all(t_swap *swap, int n)
{
    if(n == 2)
        ft_putstr_fd("Error\n", STDERR_FILENO);
    if(swap->stack_a)
        free(swap->stack_a);
    if(swap->stack_b)
        free(swap->stack_b);
    exit(EXIT_FAILURE);
}