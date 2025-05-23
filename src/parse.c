/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:05:04 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/13 12:09:55 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	check_dup(t_stack *stack)
{
	t_nodo	*check;
	t_nodo	*current;

	current = stack->top;
	while (current)
	{

		check = current->next;
		while (check)
		{
			if (current->dato == check->dato)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

void	set_indx(t_stack *stack)
{
	t_nodo	*current;
	t_nodo	*compare;
	int		indx;

	current = stack->top;
	while (current)
	{
		indx = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->dato > compare->dato)
				indx++;
			compare = compare->next;
		}
		current->index = indx;
		current = current->next;
	}
}

int	valid_numbr(char *str)
{
	int		i;
	int		sign;
	long	numbr;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	numbr = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		numbr = numbr * 10 + (str[i] - 48);
		if ((sign == 1 && numbr > INT_MAX) || 
		(sign == -1 && numbr > (long) INT_MAX + 1))
			return (0);
		i++;
	}
	return (1);
}

int	process_arg(char *arg, t_stack *stack_a)
{
	char	**split;
	long	numbr;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!valid_numbr(split[i]))
			return (free_split(split, i), (0));
		numbr = ft_atoi(split[i]);
		add_top(stack_a, numbr);
		i++;
	}
	free_split(split, i);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		if (!process_arg(argv[i], stack_a))
			return (0);
		i--;
	}
	if (!check_dup(stack_a))
		return (0);
	set_indx(stack_a);
	return (1);
}