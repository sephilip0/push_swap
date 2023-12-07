* ************************************************************************* */
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

void 	sa(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node 	*tmp2;

//	if (ft_stacksize(t_stack_node *stack) < 2)
//		return
	tmp = *stack;
	tmp->next = (*stack)->next->next;
	(*stack)->next = tmp;
	(*stack) = tmp;
}
