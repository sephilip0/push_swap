/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:18:42 by sephilip          #+#    #+#             */
/*   Updated: 2024/02/19 16:18:04 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_initstack_a(t_stack_node **a, int argc, char *argv[])
{
	char	**mat;
	int		i;
	int		error;

	i = 2;
	mat = NULL;
	error = 0;
	if (argc == 2)
	{
		mat = ft_split(argv[1], ' ');
		error = veradd(a, mat);
	}
	if (argc > 2)
		error = veradd(a, &argv[i - 1]);
	if (mat)
		ft_frees(mat);
	return (error);
}

//da merda se for *nbr[i], porque lemos o um ponter nulo
//no typecast in (!instack(*stack, a)) yet
int	veradd(t_stack_node **stack, char **nbr)
{
	long	a;
	int		i;

	i = 0;
	while (nbr[i])
	{
		a = ft_atol(nbr[i]);
		if (a < -2147483638 || a > 2147483647)
		{
			error_stack(stack, nbr);
			return (1);
		}
		if (!instack(*stack, a))
			appendstack(stack, a);
		else
		{
			error_stack(stack, nbr);
			return (1);
		}
		i++;
	}
	return (0);
}

void	prepare_push(t_stack_node **stack,
				t_stack_node *top_node,
				char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = 0;
}

void	error_stack(t_stack_node **stack, char **mat)
{
	if (*stack)
		free_stack(stack);
	ft_frees(mat);
	write(2, "Error\n", 6);
	exit(1);
}
