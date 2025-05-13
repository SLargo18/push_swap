/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:05:11 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/13 12:07:36 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a, int show)
{
	t_nodo	*first;
	t_nodo	*last;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	stack_a->top = first->next;
	first->next = NULL;
	last->next = first;
	if (show)
		ft_putstr("ra\n", 1);
}

void	rb(t_stack *stack_b, int show)
{
	t_nodo	*first;
	t_nodo	*last;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	stack_b->top = first->next;
	first->next = NULL;
	last->next = first;
	if (show)
		ft_putstr("rb\n", 1);
}


void	rr(t_stack *stack_a, t_stack *stack_b, int show)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (show)
		ft_putstr("rr\n", 1);
}
