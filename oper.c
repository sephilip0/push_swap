/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephilip@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:06:59 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/04 16:44:22 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	sa(t_stack_node **stack, bool pt)
{
	t_stack_node	*tmp;

	if (stacksize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (pt == true)
		printf("sa\n");
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
		printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool pt)
{
	sa(a, false);
	sb(b, false);
	if (pt == true)
		printf("ss\n");
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
		printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool pt)
{
	t_stack_node	*tmp;

	//if a is empty
	if (*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	if (pt == true)
		printf("pb\n");
}

void	ra(t_stack_node **stack, bool pt)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	//change tmp after changing stack!
	last = find_last(*stack);
	last->next = tmp;
	if (pt == true)
		printf("ra\n");
}

void	rb(t_stack_node **stack, bool pt)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	last = find_last(*stack);
	last->next = tmp;
	if (pt == true)
		printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool pt)
{
	ra(a, false);
	rb(b, false);
	if (pt == true)
		printf("rr\n");
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
		printf("rra\n");
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
		printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool pt)
{
	rra(a, false);
	rrb(b, false);
	if (pt == true)
		printf("rrr\n");
}
