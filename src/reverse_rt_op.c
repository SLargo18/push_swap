#include "../include/push_swap.h"

void	rra(t_stack *stack_a, int show)
{
	t_nodo	*last;
	t_nodo	*second_last;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	if (show)
		ft_putstr("rra\n", 1);
}

void	rrb(t_stack *stack_b, int show)
{
	t_nodo	*last;
	t_nodo	*second_last;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	if (show)
		ft_putstr("rrb\n", 1);
	
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int show)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (show)
		ft_putstr("rrr\n", 1);
}