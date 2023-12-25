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
void	printstack(t_stack_node *stack);
int	instack(t_stack_node *stack, int nbr);
int	stacksize(t_stack_node *stack);
int	stacksorted(t_stack_node *stack);

int	ft_initstack_a(t_stack_node **a, int argc, char *argv[]);
void	error_stack();
int	veradd(t_stack_node **stack, char **nbr);
void	sort_three(t_stack_node **a);
void	sort_stack(t_stack_node **a, t_stack_node **b);
void	last_resort(t_stack_node **a);

void	movea_b(t_stack_node **a, t_stack_node **b);
void	moveb_a(t_stack_node **a, t_stack_node **b);
void	prepare_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

t_stack_node	*cheapest_node(t_stack_node *a);
void	set_target_l(t_stack_node *a, t_stack_node *b);
void	set_target_h(t_stack_node *a, t_stack_node *b);
void	set_price(t_stack_node *a, t_stack_node *b);
//int	find_price(t_stack_node *a, t_stack_node *b, int sizea);
void	update_stack(t_stack_node *stack);

void	sa(t_stack_node **stack, bool pt);
void 	sb(t_stack_node **stack, bool pt);
void	ss(t_stack_node **a, t_stack_node **b, bool pt);
void	pa(t_stack_node **a, t_stack_node **b, bool pt);
void	pb(t_stack_node **a, t_stack_node **b, bool pt);
void	ra(t_stack_node **stack, bool pt);
void	rb(t_stack_node **stack, bool pt);
void	rr(t_stack_node **a, t_stack_node **b, bool pt);
void	rra(t_stack_node **stack, bool pt);
void	rrb(t_stack_node **stack, bool pt);
void	rrr(t_stack_node **a, t_stack_node **b, bool pt);

char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
int	ft_mod(int n);

#endif // !
