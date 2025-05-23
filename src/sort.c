/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:05:14 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/23 18:43:13 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->dato > stack_a->top->next->dato)
		sa(stack_a, 1);
}

void	sort_three(t_stack *stack_a)
{
	int	one;
	int	two;
	int	three;

	one = stack_a->top->dato;
	two = stack_a->top->next->dato;
	three = stack_a->top->next->next->dato;
	if (one < two && two > three && one < three)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (one > two && two < three && one > three)
		ra (stack_a, 1);
	else if (one > two && two > three)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (one > two && two < three && one < three)
		sa(stack_a, 1);
	else if (one < two && two > three && one > three)
		rra(stack_a, 1);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
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
		rra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
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
	pa (stack_a, stack_b, 1);
}
