/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:13:27 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 21:05:05 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	appendstack(t_stack_node **stack, int n)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return (1);
	new = (malloc(sizeof(t_stack_node)));
	if (!new)
		return (1);
	new->next = NULL;
	new->nbr = n;
	if (*stack == NULL)
	{
		*stack = new;
		return (1);
	}
	last = find_last(*stack);
	last->next = new;
	return (0);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	printstack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		printf("me: %p\n", stack);
		printf("nbr: %d ", stack->nbr);
		printf("index %d ", stack->index);
		printf("above: %d ", stack->above_median);
		printf("price: %d ", stack->push_cost);
		printf("target: %p\n", stack->target_node);
		stack = stack->next;
	}
}
