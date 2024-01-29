#include "../inc/push_swap.h"

void	ft_swap_init(t_swap *swap)
{
	swap->stack_b = NULL;
	swap->stack_a = NULL;
	swap->size_a = 0;
	swap->size_b = 0;
	swap->min_a = 0;
	swap->max_a = 0;
}

void	ft_get_args(t_swap *swap, char *argv[])
{
	char	*tmp;
	int		i;

	tmp = ft_strdup("");
	i = 0;
	while(argv[++i] != NULL)
		tmp = ft_strjoin(argv[i], " ");
	swap->args = ft_split(tmp, ' ');
}

void	ft_check_args(t_swap *swap, char *argv[])
{
	int	i;
	int	c;

	c = 1;
	ft_get_args(swap, argv);
	while(argv[c] != NULL)
	{
		i = 0;
		while(argv[c][i] != '\0')
		{
			if (!((argv[c][i] >= '0' && argv[c][i] <= '9')
				|| (argv[c][i] == '+' || argv[c][i] == '-')))
				ft_errors(swap, 1);
			if (argv[c][i + 1] == '+' || argv[c][i + 1] == '-')
				ft_errors(swap, 1);
			if ((argv[c][i] == '+' || argv[c][i] == '-') &&
				argv[c][i + 1] == '\0')
				ft_errors(swap, 1);
			i++;
		}
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
	while(++i < swap->size_a)
		ft_check_for_dups(swap, swap->stack_a[i], i);
	if (ft_sorted(swap) == 0)
		ft_free_all(swap);
}

int	main(int argc, char *argv[])
{
	t_swap	swap;

	if (argc != 1)
	{
		ft_swap_init(&swap);
		ft_check_args(&swap, argv);
		ft_get_number(&swap, argv);
		ft_sort_stack(&swap);
		ft_free_all(&swap);
	}
	return (0);
}