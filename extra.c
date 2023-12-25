#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	char	*nbr;
	int		i;
	int		res;
	int		sig;

	nbr = (char *)nptr;
	i = 0;
	res = 0;
	sig = 1;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sig = -sig;
		i++;
	}
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		res = res * 10 + nbr[i] - 48;
		i++;
	}
	if (nbr[i] && (nbr[i] < 48 || nbr[i] > 57))
		return (10000000000);
	return (sig * res);
}

int	ft_mod(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
