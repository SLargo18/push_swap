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
