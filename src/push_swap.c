#include "push_swap.h"

int	ft_initstack_a(t_stack_node **a, int argc, char *argv[])
{
	char	**mat;
	int	i;
	int	error;

	i = 2;
	error = 0;
	if (argc == 2)
	{
		//we need to free split soon
		mat = ft_split(argv[1], ' ');
		error = veradd(a, mat);
	}
	if (argc > 2)
	{
		error = veradd(a, &argv[i-1]);
	}
	return (error);
}

void	error_nbr()
{

}

void	error_stack()
{
	printf("Error\n");
	exit(1);
	//free
}

int	veradd(t_stack_node **stack, char **nbr)
{
	long	a;
	int	i;

	i = 0;
//	//da merda se for *nbr[i], porque lemos o um ponter nulo
	while (nbr[i])
	{
		a = ft_atol(nbr[i]);
		if (a < -2147483638 || a > 2147483647)
		{
			//error_stack(stack);
			error_stack();
			return (1);
		}
		if (!instack(*stack, a)) //no typecast yet
			appendstack(stack, a);
		else
		{
			error_stack();
			return (1);
		}
		i++;
	}
	return (0);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	// why false in the tutor?
	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, true);
	else if ((*a)->next == big_node)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stacksize(*a) > 4)
		pb(a, b, true);
	pb(a, b, true);
//	printstack(*a);
//	printf("===========\n");
	while (stacksize(*a) > 3)
	{
		update_stack(a);
		update_stack(b);
		set_target_l(a, b);
		set_price(a, b);
//		printf("A: +++++++++++++++++++\n");
//		printstack(*a);
//		printf("B: +++++++++++++++++++\n");
//		printstack(*b);
		prepare_push_f(a, b);
		pb(a, b, true);
	}
	sort_three(a);
//	printstack(*a);
//	printf("m.m.m.m.m.m.m.m.m.m.m.m.m.m.m.m.m\n");
//	printf("SIZE %d\n", stacksize(*b));
	while (stacksize(*b) >= 1)
	{
		update_stack(a);
		update_stack(b);
		// b, a 
		set_target_h(b, a);
		set_price(b, a);
//		printf("A: +.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.\n");
//		printstack(*a);
//		printf("B: +.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.\n");
//		printstack(*b);
		prepare_push_b(a, b);
		pa(a, b, true);
	}
//	printf("A: ========================\n");
//	printstack(*a);
//	printf("b: ========================\n");
//	printstack(*b);
//	printf("fim: ========================\n");
	while (!(stacksorted(*a)))
		ra(a, true);
}

//put both on top
void	prepare_push_f(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*from;
	t_stack_node	*to;

//	if (stacksize(*a) < 2)
	from = cheapest_node(a);
	to = from->target_node;
	while (*a != from)
	{
		if ((from->above_median) && (to->above_median))
		{
			rr(a, b, true);
		}
		else if (!(from->above_median) && !(to->above_median))
			rrr(a, b, true);
		else if (from->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
	while (*b != to)
	{
		if (to->above_median)
			rb(b, true);
		else
			rrb(b, true);
	}
//was here:	pb(a, b, true);
}

void	prepare_push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*from;
	t_stack_node	*to;

//	if (stacksize(*a) < 2)
	from = cheapest_node(b);
	to = from->target_node;
	while (*b != from)
	{
		if ((from->above_median) && (to->above_median))
		{
			rr(a, b, true);
		}
		else if (!(from->above_median) && !(to->above_median))
			rrr(a, b, true);
		else if (from->above_median)
			rb(b, true);
		else
			rrb(b, true);
	}
	while (*a != to)
	{
		if (to->above_median)
		{
		//	printf("YO WTF\n");
		//	printstack(*a);
			ra(a, true);
		}
		else
			rra(a, true);
	}
//was here:	pb(a, b, true);
}



t_stack_node	*cheapest_node(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;
	int	cost;

	tmp = *a;
	cost = (*a)->push_cost;
	cheapest = (*a);
	while (*a)
	{
		if ((*a)->push_cost < cost)
		{
			cost = (*a)->push_cost;
			cheapest = (*a);
		}
		*a = (*a)->next;
	}
	*a = tmp;
//	printf("chapest: %d\n", cheapest->nbr);
	return (cheapest);
}

void	set_target_l(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	long	stksize;
	long	dif;
	long	dif2;

	stksize = LONG_MAX;
	tmp_a = *a;
	tmp_b = *b;
	while (*a)
	{
//		printf("\nanalise: %d\n", (*a)->nbr);
		(*a)->target_node = NULL;
		dif = stksize;
		*b = tmp_b;
		while (*b)
		{
			//this could be lower/higher than max_int
			dif2 = ft_mod((*b)->nbr - (*a)->nbr);
//			printf("dif: %ld dif2: %ld\n", dif, dif2);
//			printf("b: %d a: %d\n", (*b)->nbr, (*a)->nbr);
			if (((*b)->nbr < (*a)->nbr) && (dif > dif2))
			{
//				printf("DONE\n");
				(*a)->target_node = (*b);
				dif = dif2;
			}
//			printf("now_target: %p\n", (*a)->target_node);
			(*b) = (*b)->next;
		}
		if ((*a)->target_node == NULL)
			(*a)->target_node = find_max(tmp_b);
		//dangerous putting find_max(*b)
//		printf("final_target: %p\n", (*a)->target_node);
		(*a) = (*a)->next;
	}
	*a = tmp_a;
	*b = tmp_b;
}
// a is from and b is to. re-used previous function
void	set_target_h(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	long	stksize;
	long	dif;
	long	dif2;

	stksize = LONG_MAX;
	tmp_a = *a;
	tmp_b = *b;
	while (*a)
	{
//		printf("\nanalise: %d\n", (*a)->nbr);
		(*a)->target_node = NULL;
		dif = stksize;
		*b = tmp_b;
		while (*b)
		{
			dif2 = ft_mod((*b)->nbr - (*a)->nbr);
//			printf("dif: %ld dif2: %ld", dif, dif2);
//			printf("b: %d a: %d\n", (*b)->nbr, (*a)->nbr);
			if (((*b)->nbr > (*a)->nbr) && (dif > dif2))
			{
//				printf("DONE\n");
				(*a)->target_node = (*b);
				dif = dif2;
			}
//			printf("now_target: %p\n", (*a)->target_node);
			(*b) = (*b)->next;
		}
		if ((*a)->target_node == NULL)
			(*a)->target_node = find_min(tmp_b);
		//dangerous putting find_max(*b)
//		printf("final_target: %p\n", (*a)->target_node);
		(*a) = (*a)->next;
	}
	*a = tmp_a;
	*b = tmp_b;
}

//NOW WE NEED SOMETHING TO SET PRICE AND FIND CHEAPEST
void	set_price(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;
	int	sizea;

	sizea = stacksize(*a);
	tmp = *a;
	while (*a)
	{
//		printf("FUTURE PRICE: %d\n", find_price(*a, *b, sizea));
		(*a)->push_cost = find_price(*a, *b, sizea);
		*a = (*a)->next;
	}
	*a = tmp;
}

// NEED AN UPDATED INDEX
int	find_price(t_stack_node *a, t_stack_node *b, int sizea)
{
	int	index;
	int	ind_cpy;
	int	index_target;
	int	target_cpy;

	index = a->index;
	ind_cpy = index;
	while (index > 1 && index <= sizea)
	{
		if (a->above_median)
			index--;
		//	ra(stack, false);
		else
			index++;
		//	rra(stack, false);
	}
	index_target = a->target_node->index;
	target_cpy = index_target;
	while (index_target > 1 && index_target <= stacksize(b))
	{
		if (a->target_node->above_median)
			index_target--;
		//	ra(stack, false);
		else
			index_target++;
		//	rra(stack, false);
	}
//	printf("index: %d\n", index);
//	printf("ind_cpy: %d\n", ind_cpy);
//	printf("index_target: %d\n", index_target);
//	printf("target_cpy: %d\n", target_cpy);
	index = ft_mod(ind_cpy - index) + ft_mod(target_cpy - index_target);
	return (index);
}

void	update_stack(t_stack_node **stack)
{
	int	median;
	int	index;
	t_stack_node	*first;

	index = 1;
	median = stacksize(*stack) / 2;
	if (stacksize(*stack) % 2 == 1)
		median++;
	first = *stack;
	while (*stack)
	{
		if (median)
		{
			(*stack)->above_median = true;
			median--;
		}
		else
			(*stack)->above_median = false;
		(*stack)->index = index;
		//printf("index: %d\n", (*stack)->index);
		//printf("abmed: %d\n", (*stack)->above_median);
		index++;
		*stack = (*stack)->next;
	}
	*stack = first;
}


int main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int	error;

	a = NULL;
	b = NULL;
	error = ft_initstack_a(&a, argc, argv);
	if (error)
		return (1);
//	printstack(a);
	if(!stacksorted(a))
	{
		if (stacksize(a) <= 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
//	printstack(a);
	return(0);
}
/*
int main(void)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	appendstack(&a, 10);
	appendstack(&a, 11);
	appendstack(&a, 12);
	appendstack(&a, 13);
	appendstack(&a, 14);
	appendstack(&b, 1);
	appendstack(&b, 2);
	appendstack(&b, 3);
	printstack(a);
	printf("++++++++\n");
	rra(&a, true);
	printstack(a);
	return (0);
}*/
