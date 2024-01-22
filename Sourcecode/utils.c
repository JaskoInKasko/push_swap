#include "../inc/push_swap.h"

int    ft_atol(const char *nptr, t_swap *swap)
{
	long int	res;
	int			nb;

	nb = 1;
	if (ft_strlen(nptr) > 11)
		ft_errors(swap, 3);
	while (*nptr != '\0' && ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			nb = nb * (-1);
		nptr++;
	}
	res = 0;
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		res = res * 10 + *nptr - 48;
		if ((res * nb) < -2147483648 || (res > 2147483647 && nb == 1))
			ft_errors(swap, 3);
		nptr++;
	}
	res = res * nb;
	return ((int)res);
}

void	ft_check_for_dups(t_swap *swap, char dup, int i)
{
	int	i_cpy;

	i_cpy = i;
	while (swap->stack_a[++i_cpy] != '\0')
	{
		if (dup == swap->stack_a[i_cpy])
			ft_errors(swap, 4);
	}
}

int	ft_sorted(t_swap *swap)
{
	int i;

	i = -1;
	while(++i + 1 < swap->size_a)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (1);
	}
	return (0);
}

void	ft_get_distance_ra(t_swap *swap)
{
	swap->distance_max_ra = 0;
	swap->distance_min_ra = 0;
	if (swap->stack_a[1] == swap->max_a)
		swap->distance_max_ra = 1;
	if (swap->stack_a[2] == swap->max_a)
		swap->distance_max_ra = 2;
	if (swap->stack_a[3] == swap->max_a)
		swap->distance_max_ra = 3;
	if (swap->stack_a[1] == swap->min_a)
		swap->distance_min_ra = 1;
	if (swap->stack_a[2] == swap->min_a)
		swap->distance_min_ra = 2;
	if (swap->stack_a[3] == swap->min_a)
		swap->distance_min_ra = 3;
	if(swap->size_a == 5)
	{
		if (swap->stack_a[4] == swap->min_a)
			swap->distance_min_ra = 4;
		if (swap->stack_a[4] == swap->max_a)
			swap->distance_max_ra = 4;
	}
}

void	ft_get_distance_rra(t_swap *swap)
{
	swap->distance_max_rra = 0;
	swap->distance_min_rra = 0;
	if(swap->size_a == 5)
	{
		if (swap->stack_a[4] == swap->max_a)
			swap->distance_max_rra = 1;
		if (swap->stack_a[4] == swap->min_a)
			swap->distance_min_rra = 1;
	}
	if (swap->stack_a[3] == swap->max_a)
		swap->distance_max_rra = 2;
	if (swap->stack_a[2] == swap->max_a)
		swap->distance_max_rra = 3;
	if (swap->stack_a[1] == swap->max_a)
		swap->distance_max_rra = 4;
	if (swap->stack_a[3] == swap->min_a)
		swap->distance_min_rra = 2;
	if (swap->stack_a[2] == swap->min_a)
		swap->distance_min_rra = 3;
	if (swap->stack_a[1] == swap->min_a)
		swap->distance_min_rra = 4;
}