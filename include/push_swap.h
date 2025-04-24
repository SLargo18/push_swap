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

void	ft_putstr_fd(char *s, int fd);

#endif