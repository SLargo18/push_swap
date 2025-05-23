/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ksort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:29:57 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/23 18:33:17 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_btoa(stack_a, stack_b);
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
