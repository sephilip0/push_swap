long	ft_atol(const char *nptr)
{
//verify numbers greater than max int/long?
	char	*nbr;
	int		i;
	int		res;
	int		sig;

	nbr = (char *)nptr;
	i = 0;
	res = 0;
	sig = 1;
//	while (((nbr[i] >= 9) && (nbr[i] <= 13)) || nbr[i] == 32)
//		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sig = -sig;
		i++;
	}
		if (nbr[i] <= 48 || nbr[i] >= 57)
		return ()
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		if (nbr[i] <= 48 || nbr[i] >= 57)
		return ()
		res = res * 10 + nbr[i] - 48;
		i++;
	}
	return (sig * res);
}
