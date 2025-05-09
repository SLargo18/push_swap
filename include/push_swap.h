#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_nodo
{
	int	dato;
	int	index;
	struct s_nodo *next;
} t_nodo;

typedef struct s_stack 
{
	t_nodo	*top;
	int	size;
} t_stack;

t_stack	*init_stack(void);
int		ft_isdigit(int	c);
int		ft_atoi(const char *str);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		parse_args(int argc, char **argv, t_stack *stack_a);
char	**ft_split(char const *s, char c);
void	free_split(char **result, size_t i);
void	ft_putstr(char *s, int fd);
void	free_stack (t_stack *stack);
void	add_top(t_stack *stack, int dato);
void	exit_error(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		find_min_pos(t_stack *stack_a);
int		find_max_ip(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	k_sort(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
int		check_dup(t_stack *stack);
void	set_indx(t_stack *stack);
int		valid_numbr(char *str);
int		process_arg(char *arg, t_stack *stack_a);
void	rra(t_stack *stack_a, int show);
void	rrb(t_stack *stack_b, int show);
void	rrr(t_stack *stack_a, t_stack *stack_b, int show);
void	ra(t_stack *stack_a, int show);
void	rb(t_stack *stack_b, int show);
void 	rr(t_stack *stack_a, t_stack *stack_b, int show);
void	sa(t_stack *stack_a, int show);
void	sb(t_stack *stack_b, int show);
void	ss(t_stack *stack_a, t_stack *stack_b, int show);
void	pa(t_stack *stack_a, t_stack *stack_b, int show);
void	pb(t_stack *stack_a, t_stack *stack_b, int show);
int		remove_top(t_stack *stack);
int		empty_s(t_stack *stack);

#endif