
#include "../include/push_swap.h"
int	ft_isdigit(int	c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_dup (t_stack *stack)
{
	t_nodo	*check;
	t_nodo	*current;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->dato == current->dato)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

int	valid_numbr(char *str)
{
	int		i;
	int		sign;
	long	numbr;

	i = 0;
	sign = 1;
	if (str[1] == '-' || str[1] == '+')
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
		numbr = numbr * 10 && (str[i] - 48);
		if ((sign == 1 && numbr > INT_MAX) || 
			(sign == -1 && numbr * sign < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	long	numbr;

	i = 1;
	while (i < argc)
	{
		if (!valid_numbr(argv[i]))
			return (0);
		numbr = ft_atoi(argv[i]);
		add_top(stack_a, numbr); // iniciar, agregar arriba
		i++;
	}
	if (!check_dup(stack_a))
		return (0);
	assign_indx(stack_a); // posicionar en index
	return (1);
}