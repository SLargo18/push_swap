/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:05:21 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/23 19:21:42 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_nodo	*current;
	t_nodo	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*new_s;

	new_s = (t_stack *)malloc(sizeof(t_stack));
	if (!new_s)
		return (NULL);
	new_s->top = NULL;
	new_s->size = 0;
	return (new_s);
}

void	add_top(t_stack *stack, int dato)
{
	t_nodo	*new_n;

	new_n = (t_nodo *)malloc(sizeof(t_nodo));
	if (!new_n)
		return ;
	new_n->dato = dato;
	new_n->index = 0;
	new_n->next = stack->top;
	stack->top = new_n;
	stack->size++;
}

int	remove_top(t_stack *stack)
{
	t_nodo	*temp;
	int		dato;

	if (!stack->top)
		return (0);
	temp = stack->top;
	dato = temp->dato;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (dato);
}

int	empty_s(t_stack *stack)
{
	return (stack->top == NULL);
}
