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

static	int	get_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else
		return (30);
}

static	void	push_blocks(t_stack *stack_a, t_stack *stack_b, int max_c, int *counts)
{
	if (stack_a->top->index <= max_c)
	{
		pb(stack_a, stack_b, 1);
		if (stack_b->top->index > max_c - get_size(stack_a->size) / 2)
			rb (stack_b, 1);
		counts[0]++;
		counts[1]++;
	}
	else
		ra(stack_a, 1);
}

static	void	rotate_pos(t_stack *stack_b, int max_i)
{
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
}

static	void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	counts[2];
	int	size;

	i = 0;
	size = get_size(stack_a->size);
	while (stack_a->size > 0)
	{
		counts[0] = 0;
		counts[1] = 1;
		while (counts[1] < size && stack_a->size > 0)
			push_blocks(stack_a, stack_b, i + size, counts);
		i += counts[0];
	}
}

static	void	sort_btoa(t_stack *stack_a, t_stack *stack_b)
{
	int	max_i;

	while (stack_b->size >= 0)
	{
		max_i = find_max_ip(stack_b);
		printf("aa");
		rotate_pos(stack_b, max_i);
		pa(stack_b, stack_a, 1);
	}
}

void	k_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_b(stack_a, stack_b);
	sort_btoa(stack_a, stack_b);
}

/*void	k_sort(t_stack *stack_a, t_stack *stack_b)
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
}*/
