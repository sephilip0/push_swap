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
	new = (malloc(sizeof(t_stack_node)));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = n;
	if (*stack == NULL)
	{
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

// PRINTF USAGE
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

int	instack(t_stack_node *stack, int nbr)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
		{
			// delete
//			printf("nbr: %d\n", nbr);
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

