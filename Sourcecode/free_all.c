#include "../inc/push_swap.h"

void ft_free_all(t_swap *swap)
{
    if(swap->stack_a)
        free(swap->stack_a);
    if(swap->stack_b)
        free(swap->stack_b);
    exit(EXIT_FAILURE);
}