#include "../inc/push_swap.h"

void	ft_swap_init(t_swap *swap)
{
	swap->nb = 0;
	swap->nbs = NULL; 
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
			if(!(argv[c][i] >= '0' && argv[c][i] <= '9')) //|| argv[c][i] == '-'))
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
	swap->nbs = (int *)malloc (sizeof(int) * len + 1);
	if(!swap->nbs)
		ft_errors(swap, 2);
	i = 0;
	while(argv[++i] != NULL)
		swap->nbs[i - 1] = ft_atoi(argv[i]);
	/*i = -1;
	while(swap->nbs[++i] != '\0')
		ft_printf("%d\n", swap->nbs[i]);*/
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