#include "hotrace.h"

void	search(t_data *data, char *str)
{
	unsigned int	index;

	if (!str)
	{
		write(1, ": Not found.\n", 13);
		return ;
	}
	index = hash_fnv(str) % data->length;
	while (index < data->length)
	{
		if (ft_strcmp(data->keys[index], str) == 0)
		{
			write(1, data->values[index], ft_strlen(data->values[index]));
			write(1, "\n", 1);
			return ;
		}
		index++;
	}
	write(1, str, ft_strlen(str));
	write(1, ": Not found.\n", 13);
}

unsigned int	hash_fnv(char *str)
{
	unsigned int	fnv_prime;
	unsigned int	hash;
	unsigned int	i;
	unsigned int	length;

	fnv_prime = 0x811C9DC5;
	hash = 0;
	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		hash *= fnv_prime;
		hash ^= (*str);
		i++;
	}
	return (hash);
}

int	add(t_data *data, char *key, char *value)
{
	unsigned int	index;

	index = hash_fnv(key) % data->length;
	while (index < data->length)
	{
		if (!data->keys[index])
		{
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			return (0);
		}
		index++;
	}
	return (1);
}
