#include "../include/push_swap.h"

int	init_stack(void)
{
	t_stack	*new_s;

	new_s = (t_stack *)malloc(sizeof(t_stack));
	if (!new_s)
		return (free(new_s), NULL);
	new_s->top = NULL;
	new_s->size = 0;
	return (new_s);
}

free_stack (t_stack *stack)
{
	t_nodo	*current;
	t_nodo	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_a)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit_error(NULL, NULL);
	}
	if (!parse_args(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit_error(NULL, NULL);
	}
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b); // aca es para hacer alg
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}
