#include "../inc/push_swap.h"

void    ft_get_min_max_nb(t_swap *swap)
{
    int i;

    i = 0;
    swap->max_a = swap->stack_a[0];
    swap->min_a = swap->stack_a[0];
    while(++i < swap->size_a)
    {
        if(swap->max_a < swap->stack_a[i])
            swap->max_a = swap->stack_a[i];
    }
    i = 0;
    while(++i < swap->size_a)
    {
        if(swap->min_a > swap->stack_a[i])
            swap->min_a = swap->stack_a[i];
    }
}

void    ft_create_index(t_swap *swap)
{
    int *index;
    int i;
    int j;
    int c;

    i = -1;
    c = 0;
    index = (int *)malloc(sizeof(int) * (swap->size_a + 1));
    if(!index)
        ft_free_all(swap);
    index[swap->size_a] = '\0';
    while(++i < swap->size_a)
    {
        j = -1;
        c = 0;
        while(++j < swap->size_a)
            if(swap->stack_a[i] > swap->stack_a[j])
                c++;
        index[i] = c;
    }
    i = -1;
    while(++i < swap->size_a)
        swap->stack_a[i] = index[i];
    free(index);
}