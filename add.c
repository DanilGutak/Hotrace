#include "hotrace.h"

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