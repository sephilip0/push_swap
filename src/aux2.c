/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:14:56 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 20:15:01 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	instack(t_stack_node *stack, int nbr)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

int	stacksize(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	stacksorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->next->nbr < stack->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
