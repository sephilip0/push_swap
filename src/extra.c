/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:15:08 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 20:16:07 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(char *nbr)
{
	int		i;
	long	res;
	long	sig;

	i = 0;
	res = 0;
	sig = 1;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sig = -sig;
		if (strlen(nbr) == 1)
			return (10000000000);
		i++;
	}
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		res = res * 10 + nbr[i] - 48;
		if ((res * sig) > INT_MAX || (res * sig) < INT_MIN)
			return (10000000000);
		i++;
	}
	if (nbr[i] && (nbr[i] < 48 || nbr[i] > 57))
		return (10000000000);
	return (sig * res);
}

long	ft_mod(long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
