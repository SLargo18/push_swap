/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_opetations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:05:23 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/13 12:06:21 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a, int show)
{
	t_nodo	*first;
	t_nodo	*second;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = stack_a->top->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	if (show)
		ft_putstr("sa\n", 1);
}

void	sb(t_stack *stack_b, int show)
{
	t_nodo	*first;
	t_nodo	*second;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = stack_b->top->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	if (show)
		ft_putstr("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int show)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (show)
		ft_putstr("ss\n", 1);
}
