/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:04:56 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/23 18:51:40 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sort_btoa(t_stack *stack_a, t_stack *stack_b)
{
	int	max_i;

	while (stack_b->size > 0)
	{
		max_i = find_max_ip(stack_b);
		rotate_pos(stack_b, max_i);
		pa(stack_a, stack_b, 1);
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
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
