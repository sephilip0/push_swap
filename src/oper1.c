/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:17:22 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 20:58:02 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack_node **stack, bool pt)
{
	t_stack_node	*tmp;

	if (stacksize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (pt == true)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack, bool pt)
{
	t_stack_node	*tmp;

	if (stacksize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (pt == true)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool pt)
{
	sa(a, false);
	sb(b, false);
	if (pt == true)
		write(1, "ss\n", 3);
}

void	pa(t_stack_node **a, t_stack_node **b, bool pt)
{
	t_stack_node	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (pt == true)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, bool pt)
{
	t_stack_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	if (pt == true)
		write(1, "pb\n", 3);
}
