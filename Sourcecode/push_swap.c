#include "../inc/push_swap.h"

void	ft_swap_init(t_swap *swap)
{
	swap->stack_b = NULL;
	swap->stack_a = NULL;
	swap->size_a = 0;
	swap->size_b = 0;
}

void	ft_check_args(t_swap *swap, char *argv[])
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while(argv[c] != NULL)
	{
		while(argv[c][i] != '\0')
		{
			if (!((argv[c][i] >= '0' && argv[c][i] <= '9')
				|| (argv[c][i] == '+' || argv[c][i] == '-')))
				ft_errors(swap, 1);
			if (argv[c][i + 1] == '+' || argv[c][i + 1] == '-')
				ft_errors(swap, 1);
			i++;
		}
		i = 0;
		c++;
	}
}

void	ft_get_number(t_swap *swap, char *argv[])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(argv[++i] != NULL)
		len++;
	swap->stack_a = (int *)malloc(sizeof(int) * (len + 1));
	swap->stack_b = (int *)malloc(sizeof(int) * (len + 1));
	if (!swap->stack_a || !swap->stack_b)
		ft_errors(swap, 2);
	swap->stack_a[len] = '\0';
	swap->stack_b[len] = '\0';
	i = 0;
	while(argv[++i] != NULL)
	{
		swap->stack_a[i - 1] = ft_atol(argv[i], swap);
		swap->size_a++;
	}
	i = -1;
	while(swap->stack_a[++i] != '\0')
		ft_check_for_dups(swap, swap->stack_a[i], i);
}

int	main(int argc, char *argv[])
{
	t_swap	swap;

	if(argc != 1)
	{
		ft_swap_init(&swap);
		ft_check_args(&swap, argv);
		ft_get_number(&swap, argv);
	}
	return (0);
}