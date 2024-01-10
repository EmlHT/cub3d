#include "libft.h"

int ft_isspace(char c)
{
    int i;

    i = ft_atoi(c);
	if (!((i >= 9 && i <= 13)) && !(i == 32))
		return (0);
	else
		return (1);
}
