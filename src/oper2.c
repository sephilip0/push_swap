/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:17:52 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 21:16:53 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_stack_node **a, t_stack_node **b, bool pt)
{
	ra(a, false);
	rb(b, false);
	if (pt == true)
		write(1, "rr\n", 3);
}

void	rra(t_stack_node **stack, bool pt)
{
	t_stack_node	*last;

	last = find_last(*stack);
	last->next = (*stack);
	while ((*stack)->next != last)
		(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = last;
	if (pt == true)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack, bool pt)
{
	t_stack_node	*last;

	last = find_last(*stack);
	last->next = (*stack);
	while ((*stack)->next != last)
		(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = last;
	if (pt == true)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool pt)
{
	rra(a, false);
	rrb(b, false);
	if (pt == true)
		write(1, "rrr\n", 4);
}
