#include "../inc/push_swap.h"

void ft_free_all(t_swap *swap)
{
    int i;

    i = -1;
    if(swap->args)
    {
        while(swap->args[i] != NULL)
            free(swap->args[i]);
        free(swap->args);
    }
    if(swap->stack_a)
        free(swap->stack_a);
    if(swap->stack_b)
        free(swap->stack_b);
    exit(EXIT_FAILURE);
}