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

	mat = NULL;
	error = 0;
	if (argc == 2)
	{
		mat = new_split(argv[1], ' ');
	//	if (!mat)
		//	return (1);
		error = veradd(a, mat, 1);
	}
	i = 2;
	if (argc > 2)
	{
		while (i < argc)
		{
			mat = new_split(argv[i - 1], ' ');	
			error = veradd(a, mat, 0);
			i++;
		}
	}
	if (mat)
		ft_frees(mat);
	return (error);
}

int	veradd(t_stack_node **stack, char **nbr, int fr)
{
	long	a;
	int		i;
	int		error;

	i = 0;
	error = 0;
	if (!nbr)
		return (1);
	while (nbr[i])
	{
		if (!*nbr[i])
			error_stack(stack, nbr, 0);
		a = ft_atol(nbr[i]);
		if (a < -2147483648 || a > 2147483647)
			error_stack(stack, nbr, fr);
		if (!instack(*stack, a))
			appendstack(stack, a);
		else
			error_stack(stack, nbr, fr);
		if (error != 0)
			return (1);
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

void	error_stack(t_stack_node **stack, char **mat, int fr)
{
	if (*stack)
		free_stack(stack);
	if (fr)
		ft_frees(mat);
	write(2, "Error\n", 6);
	exit(1);
}
