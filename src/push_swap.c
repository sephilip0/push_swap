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
	t_stack_node *aprint;

	a = NULL;
	appendstack(&a, 10);
	printf("a->nbr: %d\n", a->next);
	appendstack(&a, 11);
	printf("a->nbr: %d\n", a->next);
	appendstack(&a, 12);
	printf("a->nbr: %d\n", a->next);
	aprint = find_last(a);
	printf("%d\n", aprint->nbr);
	return (0);
}
