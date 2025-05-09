#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_nodo	*current;

	if (!stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->dato > current->next->dato)
			return (0);
		current = current->next;
	}
	return (1);
}

void	k_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	push;
	int	max_indx;
	int	max_i;

	max_indx = stack_a->size - 1;
	if (stack_a->size <= 100)
		size = 15;
	else 
		size = 30;
	i = 0;
	while (stack_a->size > 0)
	{
		push = 0;
		j = 0;
		while(j < size && stack_a->size > 0)
		{
			if(stack_a->top->index <= i + size)
			{
				pb(stack_a, stack_b, 1);
				if (stack_a->top->index > i + size / 2)
					rb(stack_b, 1);
				push++;
				j++;
			}
			else 
				ra (stack_a, 1);
		}
		i += push;
	}
	while (stack_b->size > 0)
	{
		max_i = find_max_ip(stack_b);
		if (max_i <= stack_b->size / 2)
		{
			while (max_i > 0)
			{
				rb(stack_b, 1);
				max_i--;
			}
		}
		else
		{
			while (max_i < stack_b->size)
			{
				rrb(stack_b, 1);
				max_i++;
			}
		}
		pa(stack_b, stack_a, 1);
	}
}