#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


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

void	ft_putstr(char *s, int fd);
int	ft_isdigit(int	c);

#endif