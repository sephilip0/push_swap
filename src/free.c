/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:37:28 by sephilip          #+#    #+#             */
/*   Updated: 2024/02/19 16:37:35 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_sent(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	i++;
	return (i);
}

char	**ft_frees(char **mat)
{
	int	i;
	int	j;

	j = count_sent(mat);
	i = 0;
	while (i < j)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}
