/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:18:26 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 20:18:33 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, true);
	else if ((*a)->next == big_node)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

//without pushb! should be in the last line
void	movea_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*from;

	from = cheapest_node(*a);
	if (from->above_median
		&& from->target_node->above_median)
	{
		while (*b != from->target_node && *a != from)
		{
			rr(a, b, true);
			update_stack(*a);
			update_stack(*a);
		}
	}
	else if (!(from->above_median) && !(from->target_node->above_median))
	{
		while (*b != from->target_node && *a != from)
		{
			rrr(a, b, true);
			update_stack(*a);
			update_stack(*a);
		}
	}
	prepare_push(a, from, 'a');
	prepare_push(b, from->target_node, 'b');
	pb(a, b, true);
}

void	moveb_a(t_stack_node **a, t_stack_node **b)
{
	prepare_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stacksize(*a) > 4)
		pb(a, b, true);
	pb(a, b, true);
	while (stacksize(*a) > 3)
	{
		update_stack(*a);
		update_stack(*b);
		set_target_l(*a, *b, LONG_MAX);
		set_price(*a, *b);
		movea_b(a, b);
	}
	sort_three(a);
	while (stacksize(*b) >= 1)
	{
		update_stack(*a);
		update_stack(*b);
		set_target_h(*b, *a, LONG_MAX);
		set_price(*b, *a);
		moveb_a(a, b);
	}
	if (!(stacksorted(*a)))
		last_resort(a);
//	printstack(*a);
}

void	last_resort(t_stack_node **a)
{
	t_stack_node	*min;

	update_stack(*a);
	min = find_min(*a);
	if (min->above_median == true)
	{
		while (!(stacksorted(*a)))
			ra(a, true);
	}
	else
	{
		while (!(stacksorted(*a)))
			rra(a, true);
	}
}
