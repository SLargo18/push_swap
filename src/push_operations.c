
#include "../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int show)
{
	t_nodo	*temp;

	if (!stack_a->top)
		return ;
	temp = stack_a->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	stack_b->size--;
	if (show)
		ft_putstr_fd("pa\n", 1);
}
