/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:17:02 by sephilip          #+#    #+#             */
/*   Updated: 2023/12/25 21:17:37 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		write(1, "ra\n", 3);
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
		write(1, "rb\n", 3);
}
