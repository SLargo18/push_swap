#include "../include/push_swap.h"

void	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int	c)
{
	return(c >= '0' && c <= '9');
}
