#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
//#include "../libft/inc/libft.h"

typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *target_node;
//	struct s_stack_node *prev;
	struct s_stack_node *next;
}	t_stack_node;

void	appendstack(t_stack_node **stack, int n);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
int	stacksize(t_stack_node *stack);
void	printstack(t_stack_node *stack);

#endif // !
