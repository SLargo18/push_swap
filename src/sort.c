#include "../include/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->dato > stack_a->top->next->dato)
		sa(stack_a, 1);
}

void	sort_three(t_stack *stack_a)
{
	int	one;
	int two;
	int three;

	one = stack_a->top->dato;
	two = stack_a->top->next->dato;
	three = stack_a->top->next->next->dato;

	if (one && two < three && one)
			sa (stack_a, 1);
	else if (one > two && two > three)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	} 
	else if (one > two && two < three && one > three)
		ra (stack_a, 1);
	else if (one < two && two > three && one < three)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (one < two && two > three && one > three)
		rra(stack_a, 1);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos == 1)
		sa(stack_a, 1);
	else if(min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if(min_pos == 3)
		rra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos == 1)
		sa(stack_a, 1);
	else if (min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (min_pos == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (min_pos == 4)
	{
		rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	sort_four (stack_a, stack_b);
	pa (stack_b, stack_a, 1);
}

int	find_min_pos(t_stack *stack_a)
{
	t_nodo	*current;
	int		i;
	int		min;
	int		min_pos;

	current = stack_a->top;
	min = INT_MAX;
	i = 0;
	min_pos = 0;
	while (current)
	{
		if (current->dato < min)
		{
			min = current->dato;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

int	find_max_ip(t_stack *stack)
{
	t_nodo	*current;
	int		i;
	int		max_i;
	int		max_indx;

	current = stack->top;
	i = 0;
	max_i = 0;
	max_indx = -1;
	while (current)
	{
		if (current->index > max_indx)
		{
			max_indx = current->index;
			max_i = i;
		}
		current = current->next;
		i++;
	}
	return (max_i);
}
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else 
		k_sort(stack_a, stack_b);
}