/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephilip@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:35:31 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/04 16:44:14 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_stack_node	*stacknew(int *number)
{
	t_stack_node	*new;

	new = (malloc(sizeof(t_stack_node)));
	if (new == NULL)
		return (NULL);
	new->nbr = number;
//	new->index = ?;
	new->push_cost = MAX_INT;
	new->above_median = false;
	new->cheapest = false;
	new->target_node = NULL;
	new->next = NULL;
	return (new);
}*/

void	appendstack(t_stack_node **stack, int n)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return ;
	printf("WHAT?\n\n");
	new = (malloc(sizeof(t_stack_node)));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = n;
	if (*stack == NULL)
	{
		printf("FIRST\n");
		*stack = new;
		return ;
	}
	last = find_last(*stack);
	last->next = new;
}

t_stack_node	*find_last(t_stack_node *stack)
{

	if (!stack)
		return (NULL);
	if (stack->next == NULL)
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

/*void	stackdel_front(t_stack_node **stack)
{
	t_stack_node	*first;

//no verify yet
	first = *stack;
	*stack = (*stack)->next;
	free(first);
}

void	stackadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;
}

void	stackadd_front(t_stack_node **stack, t_stack_node *new)
{
	if (new == NULL)
		return ;
	if (stack == NULL)
	{
		*stack = new;
		return ;
	}
//verify
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}*/

