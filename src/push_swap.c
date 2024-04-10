/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:18:12 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 20:18:20 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*cheapest_node(t_stack_node *a)
{
	t_stack_node	*cheapest;
	int				cost;

	cost = a->push_cost;
	cheapest = a;
	while (a)
	{
		if (a->push_cost < cost)
		{
			cost = a->push_cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}

//find lower target
void	set_target_l(t_stack_node *a, t_stack_node *b, long stksize)
{
	t_stack_node	*tmp_b;
	long			dif;
	long			dif2;

	tmp_b = b;
	while (a)
	{
		a->target_node = NULL;
		dif = stksize;
		b = tmp_b;
		while (b)
		{
			dif2 = ft_mod(b->nbr - a->nbr);
			if ((b->nbr < a->nbr) && (dif > dif2))
			{
				a->target_node = b;
				dif = dif2;
			}
			b = b->next;
		}
		if (a->target_node == NULL)
			a->target_node = find_max(tmp_b);
		a = a->next;
	}
}

//find higher target
void	set_target_h(t_stack_node *a, t_stack_node *b, long stksize)
{
	t_stack_node	*tmp_b;
	long			dif;
	long			dif2;

	tmp_b = b;
	while (a)
	{
		a->target_node = NULL;
		dif = stksize;
		b = tmp_b;
		while (b)
		{
			dif2 = ft_mod((long)b->nbr - (long)a->nbr);
			if ((b->nbr > a->nbr) && (dif > dif2))
			{
				a->target_node = b;
				dif = dif2;
			}
			b = b->next;
		}
		if (a->target_node == NULL)
			a->target_node = find_min(tmp_b);
		a = a->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stacksize(a);
	size_b = stacksize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = size_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

void	update_stack(t_stack_node *stack)
{
	int	median;
	int	index;

	index = 0;
	median = stacksize(stack) / 2;
	if (stacksize(stack) % 2 == 1)
		median++;
	while (stack)
	{
		if (median)
		{
			stack->above_median = true;
			median--;
		}
		else
			stack->above_median = false;
		stack->index = index;
		index++;
		stack = stack->next;
	}
}
