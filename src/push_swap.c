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
	//da merda se for *nbr[i], porque lemos o um ponter nulo
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
		sa(a, true);
	else if ((*a)->next == big_node)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

int main(int argc, char *argv[])
{
	t_stack_node	*a;
	int	error;

	a = NULL;
//	b = NULL;
	//appendstack(&a, 3);
	error = ft_initstack_a(&a, argc, argv);
	if (error)
		return (1);
	printstack(a);
	if(!stacksorted(a))
		sort_three(&a);
	//ra(&a, true);
	printstack(a);
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
