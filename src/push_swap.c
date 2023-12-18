#include "push_swap.h"

/*
void	ft_initstack_a(t_stack_node **stack, int argc, char *argv[])
{
	char	**mat;
	int	i;

	i = 2;
	if (argc == 2)
		mat = ft_split(&argv[1], ' ');
	if (argc > 2)
	{
		while (i < argc)
		{
			
		}
	}
//verif with atol
}

int main(int argc, char *argv[])
{
	char	**mat;
	t_stack_node	**a;

	ft_initstack_a(a, argc, &argv[1])
	return(0);
}*/

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
}
