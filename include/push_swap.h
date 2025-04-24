#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_nodo
{
	int	dato;
	int	index;
	struct nodo *next;
} t_nodo;

typedef struct s_stack {
	int	size;
	t_nodo *top;
} t_stack;
#endif