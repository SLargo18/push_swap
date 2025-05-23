/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:04:56 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/13 12:11:35 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	get_size(int size)
{
	if (size <= 100)
		return (15);
	if (size <= 500)
		return (35);
	return (45);
}

static void	push_blocks(t_stack *stack_a, t_stack *stack_b,
						int max_c, int *pushed)
{
	if (stack_a->top->index <= *pushed)
	{
		pb(stack_a, stack_b, 1);
		(*pushed)++;
	}
	else if (stack_a->top->index <= max_c)
	{
		pb(stack_a, stack_b, 1);
		rb(stack_b, 1);
		(*pushed)++;
	}
	else
		ra(stack_a, 1);
}

static void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	pushed;
	int	total;
	int	max_c;

	size = get_size(stack_a->size);
	pushed = 0;
	total = stack_a->size;
	while (stack_a->size > 0 && pushed < total)
	{
		max_c = pushed + size;
		push_blocks(stack_a, stack_b, max_c, &pushed);
	}
}

static void	rotate_pos(t_stack *stack_b, int max_i)
{
	if (max_i <= stack_b->size / 2)
	{
		while (max_i-- > 0)
			rb(stack_b, 1);
	}
	else
	{
		while (max_i++ < stack_b->size)
			rrb(stack_b, 1);
	}
}

static void	sort_btoa(t_stack *stack_a, t_stack *stack_b)
{
	int	max_i;

	while (stack_b->size > 0)
	{
		max_i = find_max_ip(stack_b);
		rotate_pos(stack_b, max_i);
		pa(stack_a, stack_b, 1);
	}
}

void	k_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_btoa(stack_a, stack_b);
}
