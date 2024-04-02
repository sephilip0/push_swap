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

void	ft_frees(char **mat)
{
	int	i;

	i = 0;
	if (!mat[i])
		return ;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	error_exit(int ret)
{
	write(2, "Error\n", 6);
	return (ret);
}
