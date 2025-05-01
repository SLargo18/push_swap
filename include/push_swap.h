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

#endif