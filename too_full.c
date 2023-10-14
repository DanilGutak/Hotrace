#include "hotrace.h"

int	search_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i++] == '\n')
			return (0);
	}
	return (1);
}
