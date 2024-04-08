/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:35:57 by sephilip          #+#    #+#             */
/*   Updated: 2024/04/01 16:04:46 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

//START
int				ft_initstack_a(t_stack_node **a, int argc, char *argv[]);
int				veradd(t_stack_node **stack, char **nbr);
void			prepare_push(t_stack_node **stack, t_stack_node *tn, char sn);
void			free_stack(t_stack_node **stack);
void			error_stack(t_stack_node **stack, char **mat);

//FREE
void			ft_frees(char **mat);
int				error_exit(int ret);

//AUXILIARY
int				instack(t_stack_node *stack, int nbr);
int				stacksize(t_stack_node *stack);
int				stacksorted(t_stack_node *stack);
int				appendstack(t_stack_node **stack, int n);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

//PUSH_SWAP
void			set_target_l(t_stack_node *a, t_stack_node *b, long stksize);
void			set_target_h(t_stack_node *a, t_stack_node *b, long stksize);
void			set_price(t_stack_node *a, t_stack_node *b);
void			update_stack(t_stack_node *stack);
t_stack_node	*cheapest_node(t_stack_node *a);

//PUSHING
void			sort_three(t_stack_node **a);
void			movea_b(t_stack_node **a, t_stack_node **b);
void			moveb_a(t_stack_node **a, t_stack_node **b);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			last_resort(t_stack_node **a);

//OPERATIONS
void			sa(t_stack_node **stack, bool pt);
void			sb(t_stack_node **stack, bool pt);
void			ss(t_stack_node **a, t_stack_node **b, bool pt);
void			pa(t_stack_node **a, t_stack_node **b, bool pt);
void			pb(t_stack_node **a, t_stack_node **b, bool pt);
void			ra(t_stack_node **stack, bool pt);
void			rb(t_stack_node **stack, bool pt);
void			rr(t_stack_node **a, t_stack_node **b, bool pt);
void			rra(t_stack_node **stack, bool pt);
void			rrb(t_stack_node **stack, bool pt);
void			rrr(t_stack_node **a, t_stack_node **b, bool pt);

//NEW_SPLIT
int				new_countwords(char *s, char c);
int				new_sizeword(char *s, char c, int i);
char			**new_free(char **mat, int j);
char			**new_split(char *s, char c);

//EXTRA
long			ft_atol(char *nbr);
int				ft_mod(int n);

#endif // !
